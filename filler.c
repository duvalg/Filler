/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:55:38 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 14:55:39 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_player(t_filler *filler)
{
	char	*line;
	int		ret;

	line = NULL;
	if ((ret = get_next_line(0, &line)) < 0)
		return (0);
	if (!(filler->player = ft_atoi(line + 10)))
		return (0);
	filler->letter = (filler->player == 1) ? 'O' : 'X';
	filler->adverse_letter = (filler->letter == 'O') ? 'X' : 'O';
	ft_memdel((void **)&line);
	return (1);
}

static int		get_maps_infos(t_filler *filler)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if ((ret = get_next_line(0, &line)) < 0)
		return (0);
	if ((filler->map_y = ft_atoi(line + 8)) <= 0)
		return (0);
	if ((filler->map_x = ft_atoi(line + 11)) <= 0)
		return (0);
	ft_memdel((void **)&line);
	return (1);
}

static int		first_read(t_filler *filler)
{
	if (!get_player(filler))
		return (0);
	if (!get_maps_infos(filler))
		return (0);
	return (1);
}

int				main(void)
{
	int			i;
	t_filler	*filler;

	filler = init_struct();
	if (!first_read(filler))
	{
		ft_exit(filler);
		return (0);
	}
	i = 0;
	while (filler->finish == 0)
	{
		if (!(parse(filler)))
		{
			ft_exit(filler);
			return (0);
		}
		if (!(ft_strcmp("bottom", filler->position)))
			player_bottom(filler);
		else
			player_top(filler);
	}
	ft_exit(filler);
	return (1);
}
