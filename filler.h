/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrotsen <mtrotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 14:27:05 by mtrotsen          #+#    #+#             */
/*   Updated: 2019/03/26 14:27:06 by mtrotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include "./ft_printf/libftprintf.h"

typedef struct	s_player
{
	char		sign;
	int			yplat;
	int			xplat;
	char		**map;
	int			ypiece;
	int			xpiece;
	char		**piece;
}				t_player;

t_player	*get_player(t_player *game);
int			ft_chrlook(char *line, char *str);
t_player	*get_plateau(t_player *game);
int			read_map(t_player *game);

#endif
