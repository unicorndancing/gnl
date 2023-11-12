/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 14:10:08 by mlapique          #+#    #+#             */
/*   Updated: 2023/11/12 14:10:40 by mlapique         ###   ########.fr       */
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