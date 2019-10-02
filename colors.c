/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 23:23:42 by wdaher-a          #+#    #+#             */
/*   Updated: 2019/06/22 23:24:50 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	bold_green(void)
{
	ft_putstr("\e[1;32m");
}

void	bold_blue(void)
{
	ft_putstr("\e[1;36m");
}

void	magenta(void)
{
	ft_putstr("\e[0;35m");
}

void	white(void)
{
	ft_putstr("\e[0m");
}
