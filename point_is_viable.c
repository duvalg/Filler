/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_is_viable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 11:48:38 by gduval            #+#    #+#             */
/*   Updated: 2017/06/26 11:48:46 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	check_connections(int y, int x, t_filler *filler)
{
	int		i;
	int		connections;

	i = 0;
	connections = 0;
	while (PIECE->piece[i])
	{
		if (filler->map[y + PIECE->piece[i][0]][x + PIECE->piece[i][1]] == \
			filler->letter)
			connections++;
		i++;
	}
	return (connections == 1) ? (1) : (0);
}

static int		points_exceed(int y, int x, t_filler *filler)
{
	int		i;

	i = 0;
	while (PIECE->piece[i])
	{
		if (y + PIECE->piece[i][0] < 0 \
			|| y + PIECE->piece[i][0] >= filler->map_y)
			return (0);
		if (x + PIECE->piece[i][1] < 0 \
			|| x + PIECE->piece[i][1] >= filler->map_x)
			return (0);
		i++;
	}
	return (1);
}

static int		check_adverse_letter(int y, int x, t_filler *filler)
{
	int		i;

	i = 0;
	while (PIECE->piece[i])
	{
		if (filler->map[y + PIECE->piece[i][0]][x + PIECE->piece[i][1]] == filler->adverse_letter || \
		filler->map[y + PIECE->piece[i][0]][x + PIECE->piece[i][1]] == (filler->adverse_letter + 32))
			return (0);
		i++;
	}
	return (1);
}

int				point_is_viable(int y, int x, t_filler *filler)
{
	if (!points_exceed(y, x, filler))
		return (0);
	if (!check_connections(y, x, filler))
		return (0);
	if (!check_adverse_letter(y, x, filler))
		return (0);
	return (1);
}
