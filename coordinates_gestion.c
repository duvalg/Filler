/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates_gestion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 05:21:46 by gduval            #+#    #+#             */
/*   Updated: 2017/07/03 05:21:58 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			create_coordinates_array(char *str, t_filler *filler)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '*')
			size++;
		i++;
	}
	if (!(PIECE->piece = ft_memalloc(sizeof(int *) * (size + 1))))
		return (0);
	i = 0;
	while (i < size)
	{
		if (!(PIECE->piece[i] = ft_memalloc(sizeof(int) * 2)))
			return (0);
		i++;
	}
	PIECE->piece[size] = NULL;
	return (1);
}

int			*get_coordinates(char *basic_piece, t_filler *filler)
{
	int		y;
	int		x;
	int		point;
	char	**piece;

	y = -1;
	point = 0;
	piece = ft_strsplit(basic_piece, '\n');
	create_coordinates_array(basic_piece, filler);
	while (piece[++y])
	{
		x = -1;
		while (piece[y][++x])
		{
			if (piece[y][x] == '*')
			{
				PIECE->piece[point][0] = y;
				PIECE->piece[point][1] = x;
				point++;
			}
		}
		ft_memdel((void **)&piece[y]);
	}
	ft_memdel((void **)&piece);
	return (PIECE->piece[0]);
}
