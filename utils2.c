/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:07:32 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/23 00:10:38 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		dirs_n(t_mylist *dirp)
{
	int			count;
	t_mylist	*p;

	count = 0;
	p = dirp;
	while (p != NULL)
	{
		++count;
		p = p->next;
	}
	return (count);
}

int		is_directory(const char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
		return (0);
	return (S_IFDIR & path_stat.st_mode);
}

int		is_linked(const char *path)
{
	struct stat	path_stat;

	if (lstat(path, &path_stat) == -1)
		return (0);
	return (S_ISLNK(path_stat.st_mode));
}

int		ft_strchrl(const char *s, int c)
{
	int		i;
	int		ret;

	i = -1;
	ret = -1;
	while (++i < (int)ft_strlen(s))
		if (s[i] == c)
			ret = i;
	return (ret);
}
