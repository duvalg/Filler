/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 10:49:00 by gduval            #+#    #+#             */
/*   Updated: 2017/06/09 14:45:37 by gduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strsub_clean(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (!(sub = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[len] = '\0';
	ft_strdel(&s);
	return (sub);
}

char			*ft_strjoin_clean(char *s1, char *s2, int option)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str)
	{
		while (s1[++i])
			str[i] = s1[i];
		if (option == 1 || option == 3)
			ft_strdel(&s1);
		while (s2[j])
			str[i++] = s2[j++];
		if (option == 2 || option == 3)
			ft_strdel(&s2);
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

int				read_overtake(char **overtake, char *tmp, char **line, int ret)
{
	int i;
	int overtake_size;

	overtake_size = ft_strlen(*overtake);
	if (*overtake && overtake_size > 0 && ret == 0)
	{
		i = 0;
		tmp = (char *)ft_memalloc(overtake_size);
		while ((*overtake)[i] != '\0' && (*overtake)[i] != '\n')
		{
			tmp[i] = (*overtake)[i];
			i++;
		}
		i = ((*overtake)[i] == '\n') ? i + 1 : i;
		tmp[i] = '\0';
		*overtake = ft_strsub_clean(*overtake, i, ft_strlen(*overtake) - i);
		*line = tmp;
		if ((*overtake[0]) == '\0')
			overtake = NULL;
		return (1);
	}
	return (0);
}

int				add_in_tmp(char *buff, char *tmp, char **line, char **overtake)
{
	int	i;

	i = 0;
	tmp = ft_memalloc(BUFF_SIZE + ft_strlen(*overtake) + 1);
	if (*overtake)
	{
		buff = ft_strjoin(*overtake, buff);
		ft_strdel(overtake);
	}
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		tmp[i] = buff[i];
		i++;
	}
	tmp[i] = '\0';
	if (!*line)
		*line = ft_strnew(ft_strlen(tmp));
	*line = ft_strjoin_clean(*line, tmp, 1);
	ft_strdel(&tmp);
	if (buff[i] == '\n')
	{
		*overtake = ft_strsub_clean(buff, i + 1, ft_strlen(buff) - i);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int			ret;
	char		*buff;
	char		*tmp;
	static char	*overtake = NULL;

	if (fd < 0 || !line)
		return (-1);
	tmp = NULL;
	*line = NULL;
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (add_in_tmp(buff, tmp, (char **)line, &overtake) == 1)
			return (1);
	}
	ft_strdel(&buff);
	if (read_overtake(&overtake, tmp, line, ret) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	else if (ret == 0 && ft_strlen(*line) > 0)
		return (1);
	return (ret == 0) ? 0 : 1;
}
