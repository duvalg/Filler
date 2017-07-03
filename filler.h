/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:23:12 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 15:29:53 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define PIECE filler->piece
# define ALGO filler->algo

# include "libft/libft.h"

typedef struct	s_piece
{
	int			**piece;
	int			piece_x;
	int			piece_y;
	int			diff_x;
	int			diff_y;
}				t_piece;

typedef struct	s_algo
{
	int			start_y;
	int			start_x;
	int			radius;
	int			aggressive;
}				t_algo;

typedef struct	s_filler
{
	char		*basic_map;
	char		**map;
	int			player;
	char		letter;
	char		adverse_letter;
	char		*position;
	int			map_x;
	int			map_y;
	t_piece		*piece;
	t_algo		*algo;
	int			fd;
	int			finish;
}				t_filler;

int			main(void);
t_filler	*init_struct(void);
int			parse(t_filler *filler);
int			get_piece(t_filler *filler);
void		init_coordinates(t_filler *filler);
int			create_coordinates_array(char *str, t_filler *filler);
int			*get_coordinates(char *basic_piece, t_filler *filler);
int			player_top(t_filler *filler);
int			player_bottom(t_filler *filler);
int			is_aggressive(t_filler *filler);
int			go_top(t_filler *filler);
int			go_bottom(t_filler *filler);
int			point_is_viable(int y, int x, t_filler *filler);
void		print_coord(int y, int x, t_filler *filler);
void		ft_exit(t_filler *filler);

#endif
