/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:28:32 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/23 00:28:34 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_capital(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			return (1);
		++i;
	}
	return (0);
}

int		is_there_capital(t_mylist *dirp)
{
	t_mylist	*p;

	p = dirp;
	while (p)
	{
		if (is_capital(p->name))
			return (1);
		p = p->next;
	}
	return (0);
}
