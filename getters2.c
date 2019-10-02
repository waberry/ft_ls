/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:42:58 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:43:46 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	read_perms(struct stat *filestat, char *mode)
{
	mode[1] = (filestat->st_mode & S_IRUSR) ? 'r' : '-';
	mode[2] = (filestat->st_mode & S_IWUSR) ? 'w' : '-';
	mode[3] = (filestat->st_mode & S_IXUSR) ? 'x' : '-';
	mode[4] = (filestat->st_mode & S_IRGRP) ? 'r' : '-';
	mode[5] = (filestat->st_mode & S_IWGRP) ? 'w' : '-';
	
	mode[6] = (filestat->st_mode & S_IXGRP) ? 's' : 'S';
	mode[6] = (filestat->st_mode & S_IXGRP) ? 'x' : '-';
	
	mode[7] = (filestat->st_mode & S_IROTH) ? 'r' : '-';
	mode[8] = (filestat->st_mode & S_IWOTH) ? 'w' : '-';
	if (filestat->st_mode & S_ISVTX)
		mode[9] = (filestat->st_mode & S_IXOTH) ? 't' : 'T';
	else
		mode[9] = (filestat->st_mode & S_IXOTH) ? 'x' : '-';
}


static int read_type(int mode)
{
    char    c;

    if (S_ISREG(mode))
        c = '-';
    else if (S_ISDIR(mode))
        c = 'd';
    else if (S_ISBLK(mode))
        c = 'b';
    else if (S_ISCHR(mode))
        c = 'c';
#ifdef S_ISFIFO
    else if (S_ISFIFO(mode))
        c = 'p';
#endif  /* S_ISFIFO */
#ifdef S_ISLNK
    else if (S_ISLNK(mode))
        c = 'l';
#endif  /* S_ISLNK */
#ifdef S_ISSOCK
    else if (S_ISSOCK(mode))
        c = 's';
#endif  /* S_ISSOCK */
#ifdef S_ISDOOR
    /* Solaris 2.6, etc. */
    else if (S_ISDOOR(mode))
        c = 'D';
#endif  /* S_ISDOOR */
    else
    {
        /* Unknown type -- possibly a regular file? */
        c = '?';
    }
    return(c);
}

void		get_mode(char *path, struct stat *filestat)
{
	char	mode[12];
	acl_t	acl;

	ft_bzero(mode, 12);
	ft_strcpy(mode, "-----------");
	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != (acl_t)NULL)
	{
		acl_free((void*)acl);
		mode[10] = '+';
		mode[11] = '\0';
	}
	else if ((listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0)
	{
		mode[10] = '@';
		mode[11] = '\0';
	}
	else if ((listxattr(path, NULL, 0, XATTR_NOFOLLOW)) == -1)
		mode[10] = '\0';
	mode[0] = read_type(filestat->st_mode);
	//read_type(filestat, mode);
	read_perms(filestat, mode);
	ft_putstr(mode);
}
