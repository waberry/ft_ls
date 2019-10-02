/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:45:20 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:45:31 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_mtime(struct stat *filestat, t_options *options)
{
	if (options->full_time == 1)
		return (ctime(&filestat->st_mtime));
	else if (time(NULL) - (filestat->st_mtime) > (6 * 30 * 24 * 3600))
		return (ft_strsub(ctime(&filestat->st_mtime), 19, 25));
	else
		return (ft_strsub(ctime(&filestat->st_mtime), 0, 17));
}

char		*get_atime(struct stat *filestat, t_options *options)
{
	if (options->full_time == 1)
		return (ctime(&filestat->st_atime));
	else if (time(NULL) - (filestat->st_atime) > (6 * 30 * 24 * 3600))
		return (ft_strsub(ctime(&filestat->st_atime), 19, 25));
	else
		return (ft_strsub(ctime(&filestat->st_atime), 0, 17));
}

char		*get_ctime(struct stat *filestat, t_options *options)
{
	if (options->full_time == 1)
		return (ctime(&filestat->st_ctime));
	else if (time(NULL) - (filestat->st_ctime) > (6 * 30 * 24 * 3600))
		return (ft_strsub(ctime(&filestat->st_ctime), 19, 25));
	else
		return (ft_strsub(ctime(&filestat->st_ctime), 0, 17));
}

char		*get_xtime(char x, struct stat *filestat, t_options *options)
{
	if (x == 'a')
		return (get_atime(filestat, options));
	if (x == 'm')
		return (get_mtime(filestat, options));
	if (x == 'c')
		return (get_ctime(filestat, options));
	return (NULL);
}

long long	read_total(t_mylist *dirp)
{
	t_mylist			*p;
	struct stat			dirstat;
	long long			total;

	total = 0;
	p = dirp;
	while (p)
	{
		lstat(p->path, &dirstat);
		total += dirstat.st_blocks;
		p = p->next;
	}
	return (total);
}
