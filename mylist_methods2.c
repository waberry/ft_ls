/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylist_methods2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:02:11 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/23 00:02:46 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	mylist_append_args(t_mylist **dest, t_mylist *new)
{
	t_mylist	*p;

	p = *dest;
	if (!new)
		return ;
	if (p == NULL)
		*dest = new;
	else
	{
		p = *dest;
		while (p->next)
			p = p->next;
		p->next = new;
	}
}
