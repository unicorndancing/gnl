/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2023/11/14 14:35:23 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	len;

	len = ft_strlen((char *)s) + 1;
	result = malloc(sizeof(char) * len);
	if (!result)
		return (0);
	result = ft_memmove(result, s, len);
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	totlen;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup((char *)s1));
	if (!s1 && s2)
		return (ft_strdup((char *)s2));
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	totlen = s1_len + s2_len + 1;
	result = malloc(sizeof(char) * totlen);
	if (!result)
		return (0);
	ft_memmove(result, s1, s1_len);
	ft_memmove(result + s1_len, s2, s2_len);
	result[totlen - 1] = '\0';
	return (result);
}
void	*ft_memcpy(void *dest, const void *src, int n)
{
	int				i;
	unsigned char	*destcpy;
	unsigned char	*srccpy;

	destcpy = (unsigned char *) dest;
	srccpy = (unsigned char *) src;
	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
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
	ft_memcpy(dest, src, n);
	return (dest);
}

