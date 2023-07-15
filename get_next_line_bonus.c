/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 20:23:00 by ogregoir          #+#    #+#             */
/*   Updated: 2023/01/25 16:08:02 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_buf(int fd, char *buf)
{
	int			ret;
	char		*temp;

	ret = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		buf = ft_calloc(1, 1);
	while (ret > 0)
	{
		ret = read(fd, temp, BUFFER_SIZE);
		if (ret < 0)
		{
			free(temp);
			free(buf);
			return (NULL);
		}
		temp[ret] = '\0';
		buf = ft_strjoin(buf, temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(temp);
	return (buf);
}

char	*ft_get_line(char *buf)
{
	int		i;
	char	*line;

	i = 0;
	if (!buf[i])
		return (0);
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
	{
		line[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
	{
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line[i] = '\0';
	return (line);
}

char	*nextbuf(char *buf)
{
	char	*newbuf;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (!buf[i])
	{
		free(buf);
		return (0);
	}
	newbuf = malloc(sizeof(char) * (ft_strlen(buf) - (i)));
	i++;
	while (buf[i] != '\0')
	{
		newbuf[j] = buf[i];
		i++;
		j++;
	}
	newbuf[j] = '\0';
	free(buf);
	return (newbuf);
}

char	*get_next_line(int fd)
{
	static char	*buf[OPEN_MAX];
	char		*line;

	if (fd < 0)
	{
		if (buf[fd])
		{
			free(buf[fd]);
			buf[fd] = 0;
		}
		return (NULL);
	}
	buf[fd] = get_buf(fd, buf[fd]);
	if (!buf[fd])
	{
		free(buf[fd]);
		return (NULL);
	}
	line = ft_get_line(buf[fd]);
	buf[fd] = nextbuf(buf[fd]);
	return (line);
}
