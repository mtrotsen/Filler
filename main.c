/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 13:11:04 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/26 13:11:05 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_player	*game;

	game = (t_player *)malloc(sizeof(*game));
	get_player(game);
	ft_printf("\n\n\n-----------------------\nYou play as: %c\n", game->sign);
	get_plateau(game);
	ft_printf("Plateau size y: %d\n", game->yplat);
	ft_printf("Plateau size x: %d\n\n", game->xplat);
	while (1)
	{
		if (read_map(game) == 1)
			return (0);
	}
	return (0);
}
