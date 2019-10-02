/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 00:03:14 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/23 00:04:56 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_sametime(char x, t_mylist *lst)
{
	t_mylist	*curr;
	t_mylist	*next;

	if (!lst)
		return ;
	curr = lst;
	next = lst->next;
	while (curr->next)
	{
		if (get_xtime_t(x, curr) == get_xtime_t(x, next))
		{
			if (ft_strcmp(curr->name, next->name) > 0)
			{
				mylist_swap(curr, next);
				curr = lst;
				next = lst->next;
			}
		}
		else
		{
			curr = curr->next;
			next = next->next;
		}
	}
}

void	mylist_rev(t_mylist **lst)
{
	t_mylist	*current;
	t_mylist	*next;
	t_mylist	*previous;

	if (lst == NULL || *lst == NULL)
		return ;
	current = *lst;
	previous = NULL;
	next = NULL;
	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*lst = previous;
}

void	sort_ascii(t_mylist *lst, t_options *options)
{
	t_mylist	*curr;
	t_mylist	*next;

	curr = lst;
	next = lst->next;
	while (next)
	{
		if (options->rev == 0 && ft_strcmp(curr->name, next->name) > 0)
		{
			mylist_swap(curr, next);
			curr = lst;
			next = lst->next;
		}
		else if (options->rev && ft_strcmp(curr->name, next->name) < 0)
		{
			mylist_swap(curr, next);
			curr = lst;
			next = lst->next;
		}
		else
		{
			curr = curr->next;
			next = next->next;
		}
	}
}

void	sort_xtime(char x, t_mylist *lst, t_options *options)
{
	t_mylist	*curr;
	t_mylist	*next;

	curr = lst;
	next = lst->next;
	while (lst && next)
	{
		if (options->rev == 0 && get_xtime_t(x, curr) < get_xtime_t(x, next))
		{
			mylist_swap(curr, next);
			curr = lst;
			next = lst->next;
		}
		else if (options->rev && get_xtime_t(x, curr) > get_xtime_t(x, next))
		{
			mylist_swap(curr, next);
			curr = lst;
			next = lst->next;
		}
		else
		{
			curr = curr->next;
			next = next->next;
		}
	}
}
