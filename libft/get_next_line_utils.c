/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:52:18 by ddelladi          #+#    #+#             */
/*   Updated: 2022/01/21 16:19:09 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && *(src + i) != 0)
	{
		*(dst + i) = *(src + i);
		i++;
	}
	if (*(dst + i))
		*(dst + i) = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin_plus(char *s1, char *s2)
{
	int		i;
	int		i2;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	i2 = 0;
	while (s2[i2])
		ret[i++] = s2[i2++];
	ret[i] = '\0';
	free(s1);
	return (ret);
}
