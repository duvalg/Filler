/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:23:12 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 15:29:53 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_exit(t_filler *filler)
{
	ft_memdel((void **)&(filler->algo));
	ft_memdel((void **)&(filler->piece));
	ft_memdel((void **)&(filler->map));
	ft_memdel((void **)&filler);
}
