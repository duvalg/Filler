/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 17:39:22 by gduval            #+#    #+#             */
/*   Updated: 2017/06/14 17:39:23 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coord(int y, int x, t_filler *filler)
{
	ft_putnbr((ALGO->start_y + y) - PIECE->diff_y);
	ft_putchar(' ');
	ft_putnbr((ALGO->start_x + x) - PIECE->diff_x);
	ft_putchar('\n');
}
