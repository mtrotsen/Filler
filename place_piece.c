/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 17:10:21 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/04/03 17:10:24 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			checkheat(t_player *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->yplat || x < game->xplat)
	{
		if (game->map[y][x] == '\0' && (y + 1) < game->yplat)
		{
			y++;
			x = 0;
		}
		if (game->heatmap[y][x] == -8)
			return (1);
		x++;
		if (game->map[y][x] == '\0' && (y + 1) >= game->yplat)
			break ;
	}
	return (0);
}

t_player	*heat_it_up(t_player *game)
{
	int		y;
	int		x;
	int		i;

	i = 11;
	while (1)
	{
		PL(game, i);
		if (i > 200)
		{
			ZR(x, y);
			while (y < game->yplat || x < game->xplat)
			{
				if (game->map[y][x] == '\0' && (y + 1) < game->yplat)
					PZ(y, x);
				if (game->heatmap[y][x] == -8)
					game->heatmap[y][x] = 11;
				x++;
				if (game->map[y][x] == '\0' && (y + 1) >= game->yplat)
					break ;
			}
		}
	}
	return (game);
}

t_player	*makeheat(t_player *game)
{
	int		i;
	int		x;
	int		y;

	ZRR(x, y, i);
	while (y < game->yplat || x < game->xplat)
	{
		if (game->map[y][x] == '\0' && (y + 1) < game->yplat)
			PZ(y, x);
		if (game->map[y][x] == game->sign || \
			game->map[y][x] == (game->sign + 32))
			game->heatmap[y][x] = -1;
		else if (game->map[y][x] == game->oposite || \
			game->map[y][x] == (game->oposite + 32))
			game->heatmap[y][x] = 10;
		else
			game->heatmap[y][x] = -8;
		x++;
		if (game->map[y][x] == '\0' && (y + 1) >= game->yplat)
			break ;
	}
	heat_it_up(game);
	return (game);
}

void		place_piece(t_player *game)
{
	int		i;

	i = 0;
	game->heatmap = (int **)malloc(sizeof(int *) * game->yplat);
	while (i < game->yplat)
	{
		game->heatmap[i] = (int *)malloc(sizeof(int) * game->xplat);
		i++;
	}
	makeheat(game);
	ft_lookspot(game);
}
