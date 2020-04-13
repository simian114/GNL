/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nam <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 09:26:45 by nam               #+#    #+#             */
/*   Updated: 2020/04/09 16:55:18 by sanam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			ft_free(char **buf)
{
	free(*buf);
	*buf = 0;
}

static int		new_line(char **buf, char **line, int readed)
{
	int		len;
	char	*temp;

	len = 0;
	while ((*buf)[len] != '\n' && (*buf)[len] != 0)
		len++;
	if ((*buf)[len] == '\n')
	{
		*line = ft_substr(*buf, 0, len);
		temp = ft_strdup(&(*buf)[len + 1]);
		free(*buf);
		*buf = temp;
		if (buf[0] == 0)
			ft_free(buf);
	}
	else
	{
		*line = ft_strdup(*buf);
		ft_free(buf);
		if (readed == 0)
			return (0);
	}
	return (1);
}

static char		*last(void)
{
	char	*ret;

	ret = (char *)malloc(sizeof(char) * 1);
	*ret = 0;
	return (ret);
}

static int		output(char **buf, char **line, int readed)
{
	if (readed == -1)
		return (-1);
	else if (readed == 0 && *buf == NULL)
	{
		*line = last();
		return (0);
	}
	else
		return (new_line(buf, line, readed));
}

int				get_next_line(int fd, char **line)
{
	int				readed;
	char			*tmp;
	char			*temp;
	static char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == 0)
		return (-1);
	if (!(temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((readed = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[readed] = '\0';
		if (!buf)
			buf = ft_strdup(temp);
		else
		{
			tmp = ft_strjoin(buf, temp);
			free(buf);
			buf = tmp;
		}
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(temp);
	return (output(&buf, line, readed));
}
