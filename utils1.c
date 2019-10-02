/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:05:26 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/23 00:07:14 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

time_t	get_xtime_t(char x, t_mylist *target)
{
	struct stat	filestat;

	lstat(target->path, &filestat);
	if (x == 'a')
		return (filestat.st_atimespec.tv_sec);
	if (x == 'm')
		return (filestat.st_mtimespec.tv_sec);
	if (x == 'c')
		return (filestat.st_ctimespec.tv_sec);
	else
		return (-1);
}

void	mylist_copy(t_mylist *dest, t_mylist *src)
{
	t_mylist	*d;
	t_mylist	*s;

	d = dest;
	s = src;
	ft_strcpy(d->name, s->name);
	ft_strcpy(d->path, s->path);
}

void	mylist_swap(t_mylist *a, t_mylist *b)
{
	t_mylist	*tmp;

	tmp = init_mylist(a->name, a->path);
	mylist_copy(a, b);
	mylist_copy(b, tmp);
	free(tmp);
}

void	print_linked(t_mylist *dirp)
{
	magenta();
	ft_putstr(dirp->name);
	white();
	ft_putchar('    ');
}

void	print_dir(t_mylist *dirp)
{
	bold_blue();
	ft_putstr(dirp->name);
	white();
	ft_putchar('    ');
}
