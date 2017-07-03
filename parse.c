/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 16:51:49 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 16:51:50 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		get_basic_map(t_filler *filler)
{
	char	*line;
	char	*tmp;
	int		ret;
	int		count;

	count = 1;
	ret = 0;
	tmp = NULL;
	line = NULL;
	while ((ret = get_next_line(0, &line) > 0) && (count <= filler->map_y))
	{
		if (ft_isdigit(line[0]))
		{
			if (filler->basic_map != NULL)
			{
				if (!(tmp = ft_strjoin(filler->basic_map, line + 4)))
					return (0);
			}
			else
			{
				if (!(tmp = ft_strdup(line + 4)))
					return (0);
			}
			if (!(tmp = ft_strjoin_free(tmp, "\n", 1)))
				return (0);
			if (filler->basic_map)
				ft_memdel((void **)&filler->basic_map);
			filler->basic_map = tmp;
			count++;
			if (count > filler->map_y)
				break;
		}
		ft_memdel((void **)&line);
	}
	return (ret < 0) ? 0 : 1;
}

static int		get_position(t_filler *filler)
{
	int		i;

	i = 0;
	if (filler->position)
		return (1);
	while (filler->basic_map[i])
	{
		if (filler->basic_map[i] != '.' && filler->basic_map[i] != '\n')
		{
			if (filler->basic_map[i] == filler->letter)
				filler->position = "top";
			else
				filler->position = "bottom";
			return (1);
		}
		i++;
	}
	return (0);
}

static int		get_map(t_filler *filler)
{
	if (!(filler->map = ft_strsplit(filler->basic_map, '\n')))
		return (0);
	ft_memdel((void **)&filler->basic_map);
	return (1);
}

int				parse(t_filler *filler)
{
	if (!(get_basic_map(filler)))
		return (0);
	if (!(get_position(filler)))
		return (0);
	if (!(get_map(filler)))
		return (0);
	if (!(get_piece(filler)))
		return (0);
	return (1);
}
