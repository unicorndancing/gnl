/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2021/09/05 14:05:59 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *stock)
{
	int		i;
	char	*str;

	i = 0;
	if (!stock[0])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (stock[i] && stock[i] != '\n')
	{
		str[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		str[i] = stock[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_stock(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (stock[i])
		str[j++] = stock[i++];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*ft_read_and_stock(int fd, char *stock)
{
	char	*temp_buffer;
	int		read_bytes;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stock, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, temp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp_buffer);
			return (NULL);
		}
		temp_buffer[read_bytes] = '\0';
		stock = ft_strjoin(stock, temp_buffer);
	}
	free(temp_buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	stock = ft_read_and_stock(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_line(stock);
	stock = ft_new_stock(stock);
	return (line);
}

#include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
	   #include <stdio.h>

// int main ()
// {
// 	int fd;
// 	char *a;

// 	fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		a = get_next_line(fd);
// 		if (a == NULL)
// 			return (0);
// 		printf("%s", a);
// 		free(a);
// 	}
// }