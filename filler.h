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
# include <fcntl.h>

# define HERE(i, line) i++; free(line);
# define GAME(g) ft_game_piece(g); piecepos(g); place_piece(g);
# define JI(i, j){i++; j++;}
# define CLIF(cpy, line, i, f) {cpy[f] = line[i]; f++; i++;}
# define PP(xy, c) xy = ft_atoi(cpy);
# define P(p, y, x, c) if (p == 0){PP(y, c);} else if (p > 0) PP(x, c);
# define FEE(cpy, p) free(cpy); p++;
# define ZR(j, f) j = 0; f = 0;
# define PZ(y, x) {y++; x = 0;}
# define BR(gxy, xy) {gxy = xy; break ;}
# define PI(piece, x, y, s) if (piece[y][x] == '*') s++;
# define ZRR(x, y, i) i = 0; ZR(x, y);
# define IFB(g) if (checkheat(game) == 0) break ;
# define PL(g, i) try_place(g, i); try_place_two(g, i); IFB(g); i++;
# define ZRL(x, y, s) x = 0; y = 0; s = 0;
# define BF(p, yy, xx, h, y, x) if (p[yy][xx] == '*' && h[y][x] == 10) break ;
# define ST(xx, yy, x, y) xx = x; yy = y;
# define YX(yy, y, x, xx, s, xp) {JI(yy, y); x = s; xx = xp;}
# define LEL(y, gy, x, gx) if (y >= gy || x >= gx) break ;
# define GG(p, c, h, y, x) {p++; c = c + h[y][x];}
# define K(onme) if (onme > 1) break ;
# define RE(places, s) if (places == s) return (1);

typedef struct	s_player
{
	char		sign;
	char		oposite;
	int			yplat;
	int			xplat;
	char		**map;
	int			ypiece;
	int			xpiece;
	int			xppos;
	int			yppos;
	int			starcount;
	char		**piece;
	int			**heatmap;
	int			x;
	int			y;
	int			onme;
	int			sum;
	int			countsum;
	int			places;
	int			free;
	int			xend;
	int			yend;
	int			fd;
}				t_player;

t_player		*get_player(t_player *game);
int				ft_chrlook(char *line, char *str);
t_player		*get_plateau(t_player *game);
int				read_map(t_player *game);
void			place_piece(t_player *game);
t_player		*ft_lookspot(t_player *game);
void			ft_freeup(char **chr, int num);
void			ft_freeint(int **chr, int num);
t_player		*ft_trymake(t_player *game);
t_player		*try_place(t_player *game, int i);
t_player		*try_place_two(t_player *game, int i);
t_player		*ft_lookgame(t_player *game);
int				ft_lasttry(t_player *game, int x, int y, int xx, int yy);

#endif
