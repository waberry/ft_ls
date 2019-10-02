/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylist_methods1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:22:57 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:49:19 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_mylist	*init_mylist(char *name, char *path)
{
	t_mylist	*ret;

	if (!(ret = (t_mylist *)malloc(sizeof(t_mylist))))
		return (NULL);
	ft_bzero(ret->path, PATH_MAX + 1);
	ft_bzero(ret->name, NAME_MAX + 1);
	ft_strcat(ret->name, name);
	ft_strcat(ret->path, path);
	ret->next = NULL;
	return (ret);
}

void		append_byascii(t_mylist **dest, t_mylist *new)
{
	t_mylist	*p;

	if (!new)
		return ;
	p = *dest;
	if (p == NULL || (ft_strcmp(p->name, new->name) > 0))
	{
		new->next = *dest;
		*dest = new;
	}
	else
	{
		while (p->next && (ft_strcmp(p->name, new->name) < 0))
			p = p->next;
		new->next = p->next;
		p->next = new;
	}
}

void		mylist_del_top(t_mylist **target)
{
	t_mylist	*tmp;

	if (*target != NULL)
	{
		tmp = *target;
		*target = tmp->next;
		free(tmp);
	}
}

void		mylist_del(t_mylist **target)
{
	if (*target == NULL)
		return ;
	while (*target)
		mylist_del_top(target);
}

t_mylist	*get_dirs(char *path, t_options *options)
{
	DIR				*dir;
	struct dirent	*entry;
	t_mylist		*res;
	char			tmppath[PATH_MAX + 1];

	res = NULL;
	if ((dir = opendir(path)) == NULL)
	{
		open_error(path);
		return (res);
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (!options->all && entry->d_name[0] == '.')
			continue;
		ft_strcpy(tmppath, path);
		if (tmppath[ft_strlen(tmppath) - 1] != '/')
			ft_strcat(tmppath, "/");
		ft_strcat(tmppath, entry->d_name);
		append_byascii(&res, init_mylist(entry->d_name, tmppath));
	}
	//if (is_there_capital(res))
	sort_ascii(res, options);
	closedir(dir);
	return (res);
}
