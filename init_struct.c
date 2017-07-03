/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:07:13 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 15:07:14 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static t_piece	*init_piece(void)
{
	t_piece		*piece;

	if (!(piece = ft_memalloc(sizeof(t_piece))))
		return (NULL);
	piece->piece = NULL;
	piece->piece_x = 0;
	piece->piece_y = 0;
	piece->diff_x = 0;
	piece->diff_y = 0;
	return (piece);
}

static t_algo	*init_algo(void)
{
	t_algo		*algo;

	if (!(algo = ft_memalloc(sizeof(t_algo))))
		return (NULL);
	algo->start_y = 0;
	algo->start_x = 0;
	algo->radius = 0;
	algo->aggressive = 0;
	return (algo);
}

t_filler		*init_struct(void)
{
	t_filler	*filler;

	if (!(filler = ft_memalloc(sizeof(t_filler))))
		return (NULL);
	filler->basic_map = NULL;
	filler->map = NULL;
	filler->player = 0;
	filler->letter = '\0';
	filler->adverse_letter = '\0';
	filler->position = NULL;
	filler->map_x = 0;
	filler->map_y = 0;
	if (!(filler->piece = init_piece()))
	{
		ft_memdel((void **)&filler);
		return (NULL);
	}
	if (!(filler->algo = init_algo()))
	{
		ft_memdel((void **)&(filler->piece));
		ft_memdel((void **)&filler);
		return (NULL);
	}
	// DEBUG
	filler->fd = 0;
	filler->finish = 0;
	return (filler);
}
