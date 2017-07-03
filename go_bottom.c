/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_bottom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 13:47:50 by gduval            #+#    #+#             */
/*   Updated: 2017/06/19 13:48:06 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			go_bottom(t_filler *filler)
{
	int		y;
	int		x;
	int		bad_guy;

	bad_guy = 0;
	y = filler->map_y;
	while (--y >= 0)
	{
		x = filler->map_x;
		while (--x >= 0)
		{
			if (filler->map[y][x] == filler->letter)
				return (y);
			if (filler->map[y][x] == filler->adverse_letter || \
				filler->map[y][x] == filler->adverse_letter + 32)
				break;
		}
	}
	return (-1);
}
