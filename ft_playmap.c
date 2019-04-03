/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_playmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:59:26 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/28 19:59:27 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_player	*ft_playsign(char *line, t_player *game)
{
	if (line[10] == '1')
		game->sign = 'O';
	else if (line[10] == '2')
		game->sign = 'X';
	return (game);
}

int			ft_chrlook(char *line, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0')
	{
		j = 0;
		while (line[i] == str[j])
		{
			if (str[(j + 1)] == '\0')
				return (1);
			i++;
			j++;
		}
		i++;
	}
	return (0);
}

t_player	*get_player(t_player *game)
{
	char	*line;

	while ((get_next_line(0, &line)) > 0)
	{
		if (line[0] == '$')
		{
			if ((ft_chrlook(line, "mtrotsen.filler")) == 1)
			{
				ft_playsign(line, game);
				return (game);
			}
		}
	}
	return (game);
}

t_player	*find_plat(char *line, t_player *game)
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
				game->yplat = ft_atoi(cpy);
			else if (p > 0)
				game->xplat = ft_atoi(cpy);
			free(cpy);
			p++;
		}
		i++;
	}
	return (game);
}

t_player	*get_plateau(t_player *game)
{
	char	*line;

	while ((get_next_line(0, &line)) > 0)
	{
		if ((ft_chrlook(line, "Plateau")) == 1)
		{
			find_plat(line, game);
			return (game);
		}
	}
	return (game);
}
