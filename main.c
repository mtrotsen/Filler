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

t_player	*makeready(t_player *game)
{
	game->ypiece = 0;
	game->xpiece = 0;
	game->xppos = 0;
	game->yppos = 0;
	game->starcount = 0;
	game->x = 0;
	game->y = 0;
	game->onme = 0;
	game->sum = 0;
	game->countsum = 0;
	game->places = 0;
	game->xend = 0;
	game->yend = 0;
	return (game);
}

int			main(void)
{
	t_player	*game;
	int			fd;

	fd = 0;
	game = ft_memalloc(sizeof(t_player));
	game->fd = fd;
	get_player(game);
	get_plateau(game);
	while (1)
	{
		makeready(game);
		if (read_map(game) == 1)
		{
			return (0);
		}
	}
	return (0);
}
