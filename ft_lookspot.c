/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookspot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 11:19:03 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/04/08 11:19:04 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_strdelint(int **as)
{
	if (as != NULL && *as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

void		ft_freeint(int **chr, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		ft_strdelint(&chr[i]);
		i++;
	}
	free(chr);
	chr = NULL;
}

void		ft_freeup(char **chr, int num)
{
	int		i;

	i = 0;
	while (i < num)
	{
		ft_strdel(&chr[i]);
		i++;
	}
	free(chr);
	chr = NULL;
}

int			next_level(t_player *game, int x, int y)
{
	int		xx;
	int		yy;
	int		savex;

	savex = x;
	ST(xx, yy, game->xppos, game->yppos);
	ZRR(game->onme, game->places, game->countsum);
	while (yy < game->ypiece || xx < game->xpiece)
	{
		if ((game->piece[yy][xx] == '\0' && (yy + 1) < game->ypiece))
			YX(yy, y, x, xx, savex, game->xppos);
		LEL(y, game->yplat, x, game->xplat);
		if (game->piece[yy][xx] == '*' && game->heatmap[y][x] == -1)
			JI(game->onme, game->places);
		BF(game->piece, yy, xx, game->heatmap, y, x);
		if (game->piece[yy][xx] == '*' && game->heatmap[y][x] > 10)
			GG(game->places, game->countsum, game->heatmap, y, x);
		K(game->onme);
		RE(game->places, game->starcount);
		JI(x, xx);
		if ((game->map[y][x] == '\0' && (y + 1) >= game->yplat) || \
			(game->piece[yy][xx] == '\0' && (yy + 1) >= game->ypiece))
			break ;
	}
	return (0);
}

t_player	*ft_lookspot(t_player *game)
{
	int			x;
	int			y;
	int			sum;

	ZRL(x, y, game->sum);
	while (y < game->yplat || x < game->xplat)
	{
		if (game->map[y][x] == '\0' && (y + 1) < game->yplat)
			PZ(y, x);
		if ((next_level(game, x, y)) == 1 && game->onme == 1)
		{
			if (game->sum > game->countsum || game->sum == 0)
			{
				game->sum = game->countsum;
				game->xend = x;
				game->yend = y;
			}
		}
		x++;
		if (game->map[y][x] == '\0' && (y + 1) >= game->yplat)
			break ;
	}
	ft_lookgame(game);
	return (game);
}
