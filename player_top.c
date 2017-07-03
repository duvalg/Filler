/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:39:22 by gduval            #+#    #+#             */
/*   Updated: 2017/06/14 17:39:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h> // DEBUG

static int	standard_start(t_filler *filler)
{
	int		y;

	y = 0;
	while (filler->map[y])
	{
		if (filler->map[y][filler->map_x - 1] == filler->letter)
			return (-1);
		y++;
	}
	ALGO->start_y = 0;
	ALGO->start_x = filler->map_x - 1;
	return (0);
}

static int	found_start(t_filler *filler)
{
	int		y;

	y = 0;
	is_aggressive(filler);
	if (standard_start(filler) == -1)
	{
		if (filler->map[filler->map_y - 1][0] == filler->letter)
		{
			ALGO->start_y = filler->map_y / 2;
			ALGO->start_x = filler->map_x / 2;
		}
		else
		{
			ALGO->start_y = filler->map_y - 1;
			ALGO->start_x = 0;
		}
		return (0);
	}
	return (0);
}

int			player_top(t_filler *filler)
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
