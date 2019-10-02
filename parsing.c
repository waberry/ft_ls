/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:49:32 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:56:52 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	is_alpha(char c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) ? 1 : 0);
}

static void	options_handler(char *s, t_options *options)
{
	int		i;

	i = -1;
	while (s[++i])
	{
		if (is_alpha(s[i]))
		{
			if (s[i] == 'l')
				options->verb = 1;
			else if (s[i] == 'R')
				options->recur = 1;
			else if (s[i] == 'a')
				options->all = 1;
			else if (s[i] == 'r')
				options->rev = 1;
			else if (s[i] == 't')
				options->sort_bytime = 1;
			else if (s[i] == 'T')
				options->full_time = 1;
			else
				error("invalid option!", 0);
		}
	}
}

t_options	*options_new(void)
{
	t_options *res;

	if (!(res = (t_options*)malloc(sizeof(t_options))))
		return (NULL);
	res->verb = 0;
	res->recur = 0;
	res->all = 0;
	res->rev = 0;
	res->sort_bytime = 0;
	res->index = 0;
	res->full_time = 0;
	res->files = NULL;
	res->errors = NULL;
	res->all_args = NULL;
	return (res);
}

t_options	*myparser(int ac, char **av)
{
	t_options	*options;
	int			i;

	options = options_new();
	if (ac < 2)
		return (options);
	i = 0;
	while (++i < ac)
	{
		if (ft_strcmp(av[i], "-") == 0)
			break ;
		if (ft_strcmp(av[i], "--") == 0)
		{
			options->index = i + 1;
			return (options);
		}
		if ((av[i][2] && av[i][0] == '-' && av[i][1] != '-' && av[i][2] == '-')
			|| (av[i][2] && av[i][0] == '-' && av[i][1] == '-'))
			error("illegal option -- -", 0);
		if (av[i][0] != '-')
			break ;
		options_handler(av[i], options);
	}
	options->index = i;
	return (options);
}
