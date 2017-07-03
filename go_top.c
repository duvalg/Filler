/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_top.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:47:50 by gduval            #+#    #+#             */
/*   Updated: 2017/06/19 13:48:06 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	border_reached(t_filler *filler)
{
	int		i;
	char	c;

	i = 0;
	while (i < filler->map_y)
	{
		c = filler->map[i][0];
		if (c == filler->letter)
			return (1);
		else if (c == filler->adverse_letter || \
			c == (filler->adverse_letter + 32))
			return (0);
		i++;
	}
	return (0);
}

int			go_top(t_filler *filler)
{
	int		y;
	int		x;
	int		me;
	int		bad_guy;

	bad_guy = 0;
	y = -1;
	while (filler->map[++y])
	{
		x = -1;
		while (filler->map[y][++x])
		{
			me = 0;
			if (filler->map[y][x] == filler->adverse_letter ||
			filler->map[y][x] == (filler->adverse_letter + 32))
				bad_guy = 1;
			else if (filler->map[y][x] == filler->letter)
				me = 1;
			if (me == 1 && bad_guy == 0)
			{
				if (border_reached(filler))
				{
					filler->algo->aggressive = 2;
					return (-1);
				}
				return (y);
			}
			if ((me == 1 && bad_guy == 1) || (me == 0 && bad_guy == 1))
				return (-1);
		}
	}
	return (-1);
}
