/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:10:58 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/04/02 20:10:59 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char		*ft_strdupfill(const char *s, int size)
{
	int		i;
	char	*dup;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (size + 1));
	if (dup == NULL)
		return (0);
	while (i < size)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

t_player	*piecepos(t_player *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < game->ypiece || x < game->xpiece)
	{
		if (game->piece[y][x] == '\0' && (y + 1) < game->ypiece)
		{
			y++;
			x = 0;
		}
		if (game->piece[y][x] == '*')
		{
			game->yppos = y;
			break ;
		}
		x++;
		if (game->piece[y][x] == '\0' && (y + 1) >= game->ypiece)
			break ;
	}
	ft_trymake(game);
	return (game);
}

t_player	*ft_game_piece(t_player *game)
{
	char	*line;
	int		i;

	i = 0;
	game->piece = malloc(sizeof(char *) * game->ypiece);
	i = 0;
	while (i < game->ypiece)
	{
		get_next_line(game->fd, &line);
		game->piece[i] = ft_strdupfill(line, game->xpiece);
		i++;
		free(line);
	}
	return (game);
}

t_player	*ft_piece_get(char *line, t_player *game)
{
	char	*cpy;
	int		i;
	int		j;
	int		p;
	int		f;

	ZR(p, i);
	while (line[i] != ':' && line[i] != '\0')
	{
		ZR(j, f);
		while (line[i] >= '0' && line[i] <= '9')
			JI(i, j);
		if (j > 0)
		{
			cpy = ft_strnew(j);
			i = i - j;
			while (line[i] >= '0' && line[i] <= '9')
				CLIF(cpy, line, i, f);
			P(p, game->ypiece, game->xpiece, cpy);
			FEE(cpy, p);
		}
		i++;
	}
	GAME(game);
	return (game);
}

int			read_map(t_player *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->yplat);
	while (i < game->yplat)
		game->map[i++] = malloc(sizeof(char) * (game->xplat + 1));
	i = 0;
	while ((get_next_line(game->fd, &line)) > 0 && \
		(ft_chrlook(line, "Piece")) != 1)
	{
		game->map[i] = ft_strcpy(game->map[i], &line[4]);
		HERE(i, line);
	}
	ft_piece_get(line, game);
	free(line);
	ft_freeup(game->piece, game->ypiece);
	ft_freeup(game->map, game->yplat);
	ft_freeint(game->heatmap, game->yplat);
	if (get_next_line(game->fd, &line) == 0)
		return (1);
	free(line);
	get_next_line(game->fd, &line);
	free(line);
	return (0);
}
