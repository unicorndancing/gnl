/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:43:18 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/05 14:17:37 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}


char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	c = (char) c;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdup(char *s, int to_free)
{
	char	*result;
	size_t	len;

	len = ft_strlen((char *)s) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	result = ft_memmove(result, s, len);
	if (to_free == 1)
		free ((void*)s);
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	totlen;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup((char *)s1, 1));
	if (!s1 && s2)
		return (ft_strdup((char *)s2, 0));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	totlen = s1_len + s2_len + 1;
	result = malloc(sizeof(char) * totlen);
	if (!result)
	{
		free((void*)s1);
		return (0);
	}
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result[totlen - 1] = '\0';
	free ((void*)s1);
	return (result);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;
	unsigned char	*srccpy;
	unsigned char	*destcpy;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (n--)
		{
			destcpy[n] = srccpy[n];
		}
		return (dest);
	}
	else 
	{
		while (i < n)
		{
			destcpy[i] = srccpy[i];
			i++;
		}
	}
	return (dest);
}