/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trymake.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:14:19 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/04/17 16:14:20 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player	*ft_trymake(t_player *game)
{
	int	x;
	int	y;

	ZR(x, y);
	while (y < game->ypiece || x < game->xpiece)
	{
		if (y >= game->ypiece && (x + 1) < game->xpiece)
			PZ(x, y);
		if (game->piece[y][x] == '*')
			BR(game->xppos, x);
		y++;
		if (y >= game->ypiece && (x + 1) >= game->xpiece)
			break ;
	}
	ZR(x, y);
	while (y < game->ypiece || x < game->xpiece)
	{
		if (game->piece[y][x] == '\0' && (y + 1) < game->ypiece)
			PZ(y, x);
		PI(game->piece, x, y, game->starcount);
		x++;
		if (game->piece[y][x] == '\0' && (y + 1) >= game->ypiece)
			break ;
	}
	return (game);
}

t_player	*try_place(t_player *game, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->yplat || x < game->xplat)
	{
		if (game->map[y][x] == '\0' && (y + 1) < game->yplat)
		{
			y++;
			x = 0;
		}
		if ((x + 1) < game->xplat && \
			game->heatmap[y][(x + 1)] == (i - 1) && \
			game->heatmap[y][x] < 10 && game->heatmap[y][x] != -1)
			game->heatmap[y][x] = i;
		else if (x > 0 && game->heatmap[y][(x - 1)] == (i - 1) && \
			game->heatmap[y][x] < 10 && game->heatmap[y][x] != -1)
			game->heatmap[y][x] = i;
		x++;
		if (game->map[y][x] == '\0' && (y + 1) >= game->yplat)
			break ;
	}
	return (game);
}

t_player	*try_place_two(t_player *game, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->yplat || x < game->xplat)
	{
		if (y >= game->yplat && (x + 1) < game->xplat)
		{
			x++;
			y = 0;
		}
		if ((y + 1) < game->yplat && \
			game->heatmap[(y + 1)][x] == (i - 1) && \
			game->heatmap[y][x] < 1 && game->heatmap[y][x] != -1)
			game->heatmap[y][x] = i;
		else if (y > 0 && game->heatmap[(y - 1)][x] == (i - 1) && \
			game->heatmap[y][x] < 1 && game->heatmap[y][x] != -1)
			game->heatmap[y][x] = i;
		y++;
		if (y >= game->yplat && (x + 1) >= game->xplat)
			break ;
	}
	return (game);
}

t_player	*ft_lookgame(t_player *game)
{
	if (game->xend == 0 && game->yend == 0 && game->sum == 0)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
		exit(0);
	}
	game->xend = game->xend - game->xppos;
	game->yend = game->yend - game->yppos;
	ft_putnbr(game->yend);
	ft_putchar(' ');
	ft_putnbr(game->xend);
	ft_putchar('\n');
	return (game);
}
