/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coordinates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 14:57:21 by gduval            #+#    #+#             */
/*   Updated: 2017/06/14 15:04:34 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_coordinates(t_filler *filler)
{
	int	i;

	i = 0;
	while (PIECE->piece[i])
	{
		PIECE->piece[i][0] -= PIECE->diff_y;
		PIECE->piece[i][1] -= PIECE->diff_x;
		i++;
	}
}
