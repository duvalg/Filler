/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 14:29:30 by gduval            #+#    #+#             */
/*   Updated: 2017/06/12 14:35:19 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_dimensions(t_filler *filler)
{
	char	*line;
	int		ret;

	line = NULL;
	ret = 0;
	if ((ret = get_next_line(0, &line)) == -1)
		return (0);
	if (ft_strlen(line) < 10)
		return (0);
	if ((PIECE->piece_y = ft_atoi(line + 6)) == 0)
		return (0);
	if ((PIECE->piece_x = ft_atoi(line + 8)) == 0)
		return (0);
	ft_memdel((void **)&line);
	return (1);
}

static char	*basic_piece_gestion(char *piece, char *line, t_filler *filler)
{
	char	*tmp;

	tmp = NULL;
	if (piece != NULL)
	{
		if (!(tmp = ft_strjoin(piece, line)))
			return (NULL);
	}
	else
	{
		if (!(tmp = ft_strdup(line)))
			return (NULL);
	}
	if (!(tmp = ft_strjoin_free(tmp, "\n", 1)))
		return (NULL);
	if (piece)
		ft_memdel((void **)&piece);
	return (tmp);
}

static char	*get_basic_piece(t_filler *filler)
{
	char	*piece;
	char	*line;
	int		i;
	int		ret;

	piece = NULL;
	line = NULL;
	i = 0;
	ret = 0;
	while ((ret = get_next_line(0, &line) > 0))
	{
		piece = basic_piece_gestion(piece, line, filler);
		i++;
		if (ret == 0)
			break;
		if (i == PIECE->piece_y)
			break;
	}
	return (ret < 0) ? NULL : piece;
}

int			get_piece(t_filler *filler)
{
	char	*basic_piece;
	int		*diff;

	basic_piece = NULL;
	if (!get_dimensions(filler))
		return (0);
	if (!(basic_piece = get_basic_piece(filler)))
		return (0);
	if (!(diff = get_coordinates(basic_piece, filler)))
		return (0);
	PIECE->diff_y = diff[0];
	PIECE->diff_x = diff[1];
	init_coordinates(filler);
	ft_memdel((void **)&basic_piece);
	return (1);
}
