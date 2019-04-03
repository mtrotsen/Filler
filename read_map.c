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

t_player	*ft_game_piece(t_player *game)
{
	char	*line;
	int		i;

	i = 0;
	game->piece = malloc(sizeof(char *) * game->ypiece);
	while (i < game->ypiece)
		game->piece[i++] = malloc(sizeof(char) * (game->xpiece + 1));
	i = 0;
	ft_printf("\nPiece:\n");
	while ((get_next_line(0, &line)) > 0 && (line[0] == '.' || line[0] == '*'))
	{
		game->piece[i] = ft_strcpy(game->piece[i], line);
		printf("%s\n", game->piece[i]);
		i++;
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

	p = 0;
	i = 0;
	while (line[i] != ':' && line[i] != '\0')
	{
		j = 0;
		f = 0;
		while (line[i] >= '0' && line[i] <= '9')
		{
			i++;
			j++;
		}
		if (j > 0)
		{
			cpy = ft_strnew(j);
			i = i - j;
			while (line[i] >= '0' && line[i] <= '9')
			{
				cpy[f] = line[i];
				f++;
				i++;
			}
			if (p == 0)
				game->ypiece = ft_atoi(cpy);
			else if (p > 0)
				game->xpiece = ft_atoi(cpy);
			free(cpy);
			p++;
		}
		i++;
	}
	ft_game_piece(game);
	place_piece(game);
	return (game);
}

int		read_map(t_player *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map = malloc(sizeof(char *) * game->yplat);
	while (i < game->yplat)
		game->map[i++] = malloc(sizeof(char) * (game->xplat + 1));
	i = 0;
	get_next_line(0, &line);
	ft_printf("Plateau:\n");
	while ((get_next_line(0, &line)) > 0 && (ft_chrlook(line, "Piece")) != 1)
	{
		game->map[i] = ft_strcpy(game->map[i], &line[4]);
		printf("%s\n", game->map[i]);
		i++;
	}
	ft_piece_get(line, game);
	ft_printf("\nPiece y coordinates = %d\n", game->ypiece);
	ft_printf("Piece x coordinates = %d\n\n\n\n", game->xpiece);
	while (line[0] != '<' && line[6] != 'X' && line[0] != '=')
		get_next_line(0, &line);
	get_next_line(0, &line);
	printf("Line = %s\n\n", line);
	if (line[0] == '=')
		return (1);
	return (0);
}
