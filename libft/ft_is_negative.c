/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 14:04:04 by mtrotsen          #+#    #+#             */
/*   Updated: 2018/10/31 15:13:44 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_is_negative(int n)
{
	if (n < 0)
		ft_putchar('N');
	if (n >= 0)
		ft_putchar('P');
}
