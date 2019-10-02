/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:41:01 by berry             #+#    #+#             */
/*   Updated: 2019/06/22 23:36:00 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mylist_merge(t_mylist **begin, t_mylist *tail)
{
	t_mylist	*p;

	p = *begin;
	if (!p)
	{
		*begin = tail;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = tail;
}

void	load_args(int ac, char **av, t_options *options)
{
	int			i;
	struct stat	filestat;

	i = options->index;
	if (i == 0 || ac == i || !ft_strcmp(av[i], "./ft_ls") || av[i] == NULL)
	{
		mylist_append_args(&options->all_args, init_mylist(".", "."));
		return ;
	}
	while (i < ac)
	{
		if (!is_directory(av[i]) && (lstat(av[i], &filestat) == -1))
			mylist_append_args(&options->errors, init_mylist(av[i], av[i]));
		else if (!is_directory(av[i]) && lstat(av[i], &filestat) == 0)
			mylist_append_args(&options->files, init_mylist(av[i], av[i]));
		else
			mylist_append_args(&options->all_args, init_mylist(av[i], av[i]));
		++i;
	}
}

void	sort_args(t_options *options)
{
	if (options->errors)
		sort_ascii(options->errors, options);
	if (options->errors && options->rev)
		mylist_rev(&options->errors);
	if (options->sort_bytime)
	{
		if (options->files)
			sort_xtime('m', options->files, options);
		if (options->all_args)
			sort_xtime('m', options->all_args, options);
		return ;
	}
	if (options->files)
		sort_ascii(options->files, options);
	if (options->all_args)
		sort_ascii(options->all_args, options);
	//mylist_merge(&options->errors, options->files);
	//mylist_merge(&options->errors, options->all_args);
	//options->all_args = options->errors;
}


void	handle_args(t_mylist *args, t_options *options)
{
	t_mylist	*p;
	struct stat	filestat;

	p = args;
	while (p)
	{
		if (!is_directory(p->name) && (lstat(p->name, &filestat) == -1))
			open_error(p->name);
		else
		{
			if (options->verb)
			{
				lstat(p->name, &filestat);
				print_details(p->name, &filestat, options);
				ft_putendl(p->name);
			}
			else
				ft_putendl(p->name);
		}
		p = p->next;
	}
	if (args != NULL)
		ft_putchar('\n');
}


int		main(int ac, char **av)
{
	t_options	*options;
	t_mylist	*arg;

	options = myparser(ac, av);
	load_args(ac, av, options);
	sort_args(options);
	handle_args(options->errors, options);
	handle_args(options->files, options);
	arg = options->all_args;
	while (arg && is_directory(arg->name))
	{
		if (arg && arg->name[0] != '-')
		{
			ft_putstr(arg->name);
			ft_putchar(' ');
			ft_putendl(":");
		}
		if (arg)
			display_recur(arg->name, options);
		if (arg->next)
			ft_putchar('\n');
		arg = arg->next;
	}
	if (options->errors)
		mylist_del(&options->errors);
	free(options);
	return (0);
}
