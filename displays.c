/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:14:47 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:23:17 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_details(char *path, struct stat *dirstat, t_options *options)
{
	unsigned long	i;
	char			*time;

	i = -1;
	get_mode(path, dirstat);
	ft_putchar(' ');
	ft_putstr(get_nlinks(dirstat));
	ft_putchar(' ');
	ft_putstr(get_ownername(dirstat));
	ft_putchar(' ');
	ft_putstr(get_ownergroup(dirstat));
	ft_putchar(' ');
	ft_putstr(get_size(dirstat));
	ft_putchar(' ');
	time = get_xtime('m', dirstat, options);
	while (++i < ft_strlen(time) - 1)
		ft_putchar(time[i]);
	ft_putchar(' ');
}

void		detailed_display_mylist(t_mylist *dirp, t_options *options)
{
	struct stat	dirstat;
	char		buf[PATH_MAX + 1];

	ft_putstr("total ");
	ft_putnbr(read_total(dirp));
	ft_putchar('\n');
	while (dirp)
	{
		ft_bzero(buf, PATH_MAX + 1);
		lstat(dirp->path, &dirstat);
		print_details(dirp->path, &dirstat, options);
		if (is_linked(dirp->path))
		{
			readlink(dirp->path, buf, PATH_MAX + 1);
			print_linked(dirp);
			ft_putstr(" -> ");
			ft_putstr(buf);
		}
		else if (is_directory(dirp->path))
			print_dir(dirp);
		else
			ft_putstr(dirp->name);
		ft_putchar('\n');
		dirp = dirp->next;
	}
}

void		display_one_mylist(t_mylist *dirp)
{
	char	*tmp;

	tmp = NULL;
	while (dirp != NULL)
	{
		if (is_linked(dirp->path))
			print_linked(dirp);
		else if (is_directory(dirp->path))
			print_dir(dirp);
		else
			ft_putstr(dirp->name);
		ft_putchar('\n');
		dirp = dirp->next;
	}
}

void		display_recur(char *path, t_options *options)
{
	t_mylist	*dirp;
	t_mylist	*tmp_dir1;

	tmp_dir1 = get_dirs(path, options);
	dirp = tmp_dir1;
	if (options->sort_bytime)
		sort_xtime('m', dirp, options);
	(options->rev) ? mylist_rev(&dirp) : mylist_rev(NULL);
	if (options->verb && dirp)
		detailed_display_mylist(dirp, options);
	else
		display_one_mylist(dirp);
	while (dirp && options->recur)
	{
		if (is_directory(dirp->path))
		{
			if (ft_strcmp(dirp->name, "..") && ft_strcmp(dirp->name, "."))
			{
				ft_putchar('\n');
				ft_putendl(dirp->path);
				display_recur(dirp->path, options);
			}
		}
		dirp = dirp->next;
	}
	mylist_del(&tmp_dir1);
}
