/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_aggressive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 11:42:59 by gduval            #+#    #+#             */
/*   Updated: 2017/06/19 11:43:03 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_aggressive(t_filler *filler)
{
	int		i;
	int		player_here;

	i = -1;
	if (filler->algo->aggressive == 0)
	{
		while (filler->map[++i])
		{
			player_here = 0;
			if (ft_strchr(filler->map[i], 'x') || ft_strchr(filler->map[i], 'X'))
				player_here++;
			if (ft_strchr(filler->map[i], 'o') || ft_strchr(filler->map[i], 'O'))
				player_here++;
			if (player_here == 2)
			{
				filler->algo->aggressive = 1;
				return (1);
			}
		}
	}
	return (0);
}
