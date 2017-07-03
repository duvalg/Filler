/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:39:15 by gduval            #+#    #+#             */
/*   Updated: 2017/06/16 10:34:34 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> // DEBUG

static int	standard_start(t_filler *filler)
{
	int		y;
	int		x;

	y = 0;
	while (filler->map[y])
	{
		x = 0;
		while (filler->map[y][x])
		{
			if (filler->map[y][x] == filler->letter && y == 0)
			{
				ALGO->aggressive = 2;
				return (-1);
			}
			x++;
		}
		y++;
	}
	ALGO->start_y = 0;
	ALGO->start_x = filler->map_x / 4 * 3;
	return (0);
}

static int	found_start(t_filler *filler)
{
	int		y;

	y = 0;
	is_aggressive(filler);
	if ((y = go_top(filler)) != -1 && ALGO->aggressive == 1)
	{
		ALGO->start_y = y;
		ALGO->start_x = 0;
	}
	else if ((y = go_bottom(filler)) != -1 && ALGO->aggressive == 2)
	{
		if (ft_strchr(filler->map[filler->map_y - 1], filler->letter))
		{
			ALGO->start_y = filler->map_y / 2;
			ALGO->start_x = 0;
		}
		else
		{
			ALGO->start_y = filler->map_y - 1;
			ALGO->start_x = filler->map_x / 2;
		}
	}
	else
	{
		if (standard_start(filler) == -1)
		{
			ALGO->start_y = (filler->map_y / 3) * 2;
			ALGO->start_x = 0;
			return (0);
		}
	}
	return (0);
}

int			player_bottom(t_filler *filler)
{
	int		y;
	int		x;

	y = 0;
	ALGO->radius = 1;
	while (ALGO->radius <= filler->map_x)
	{
		y = ALGO->radius * -1;
		while (y <= ALGO->radius)
		{
			x = ALGO->radius * -1;
			found_start(filler);
			if (y == ALGO->radius || y == (ALGO->radius) * -1)
			{
				while (x <= ALGO->radius)
				{
					if (point_is_viable(ALGO->start_y + y, ALGO->start_x + x, filler))
					{
						print_coord(y, x, filler);
						return (1);
					}
					x++;
				}
			}
			else
			{
				if (point_is_viable(ALGO->start_y + y, ALGO->start_x + ALGO->radius, filler))
				{
					print_coord(y, ALGO->radius, filler);
					return (1);
				}
				else if (point_is_viable(ALGO->start_y + y, ALGO->start_x - ALGO->radius, filler))
				{
					print_coord(y, ALGO->radius * -1, filler);
					return (1);
				}
			}
			y++;
		}
		ALGO->radius++;
	}
	printf("0 0\n");
	filler->finish = 1;
	return (0);
}
