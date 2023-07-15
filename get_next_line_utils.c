/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogregoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:21:55 by ogregoir          #+#    #+#             */
/*   Updated: 2023/01/25 16:07:54 by ogregoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	str = malloc(sizeof(*s1) * (ft_strlen(s1) + (ft_strlen(s2))) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (i <= j)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	free (s1);
	str[j] = 0;
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (size > 4294967295 || count > 4294967295)
		return (0);
	str = malloc(size * count);
	if (!str)
		return (0);
	while (i != size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strchr(char *str, char s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
			return (str + i);
		i++;
	}
	if (s == 0)
		return (str + ft_strlen(str));
	return (0);
}
