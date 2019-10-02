/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berry <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:40:40 by berry             #+#    #+#             */
/*   Updated: 2019/06/22 23:25:40 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	error(char *message, int output)
{
	ft_putendl(message);
	print_usage();
	exit(output);
}

void	print_usage(void)
{
	ft_putendl("usage: ./ft_ls [-alrtTR] [file ...]");
}

void	open_error(char *path)
{
	int		i;

	ft_putstr("ft_ls: ");
	i = ft_strchrl(path, '/');
	while (i != -1 && path[i])
	{
		++i;
		write(1, &path[i], 1);
	}
	if (i == -1)
		ft_putstr(path);
	ft_putstr(": ");
	if (errno == EACCES)
		ft_putendl("Permission denied");
	else
		ft_putendl("No such file or directory");
}
