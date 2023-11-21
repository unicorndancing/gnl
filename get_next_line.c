/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2023/11/21 20:22:35 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		str[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		str[i] = line[i];
		i++;
	}
	str[i] = '\0';
	free(line);
	return (str);
}

void	ft_new_stock(char *stock)
{
	int		i;
	int		j;

	i = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	j = 0;
	if (stock[i] == '\n')
		i++;
	while (stock[i])
		stock[j++] = stock[i++];
	stock[j] = '\0';
}

char	*ft_read_and_stock(int fd, char *stock)
{
	char	*temp_buffer;
	int		read_bytes;
	// static int con = 2;

	temp_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp_buffer)
	{
		free(temp_buffer);
		return (NULL);
	}
	temp_buffer[0] = '\0';
	read_bytes = 1;
	temp_buffer = ft_strjoin(temp_buffer, stock);
	while (!ft_strchr(stock, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, stock, BUFFER_SIZE);
		// con--;
		// if (con == 0)
		// 	read_bytes = -1;
		if ((read_bytes == 0 && stock[0] == '\0') || read_bytes < 0)
		{
			free(temp_buffer);
			return (NULL);
		}
		stock[read_bytes] = '\0';
		temp_buffer = ft_strjoin(temp_buffer, stock);
	}
	return (temp_buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	stock[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (0);
	line = ft_read_and_stock(fd, stock);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	line = ft_line(line);
	ft_new_stock(stock);
	return (line);
}

// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>
// #include <stdio.h>

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