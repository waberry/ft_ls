/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:33:12 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:33:29 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*get_ownername(struct stat *filestat)
{
	struct passwd	*pws;

	if ((pws = getpwuid(filestat->st_uid)) == NULL)
		error("ft_ls:getpwuid:error", 0);
	return (pws->pw_name);
}

char	*get_ownergroup(struct stat *filestat)
{
	struct group	*grp;

	if ((grp = getgrgid(filestat->st_gid)) == NULL)
		error("ft_ls:getgrgid:error", 0);
	return (grp->gr_name);
}

char	*get_size(struct stat *filestat)
{
	return (ft_itoa(filestat->st_size));
}

char	*get_nlinks(struct stat *filestat)
{
	return (ft_itoa(filestat->st_nlink));
}