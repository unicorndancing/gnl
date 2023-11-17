#include "get_next_line.h"
#include <stdio.h>
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE = 5
// # endif

char 	*theline(char *str)
{
	int i;
	char *truc;

	i = 0;
	while (str[i - 1] != '\n' && str[i] != '\0')
		i++;
	truc = malloc (sizeof(char) * (i + 1));
	i = 0;
	while (str[i - 1] != '\n' && str[i] != '\0')
	{
		truc[i] = str[i];
		i++;
	}
	truc[i] = '\0';
	return (truc);
}

void 	thenextline(char *stock)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (stock[i - 1] != '\n' && stock[i] != '\0')
		i++;
	while (stock[i])
	{
		stock[j] = stock[i];
		i++;
		j++;
	}
	stock[j] = '\0';
}

char	*ft_readstuff(int fd, int truclis, char *stock)
{
	char	*truc;
	
	truclis = BUFFER_SIZE;
	truc = NULL;
	while (truclis == BUFFER_SIZE)
	{
		truclis = read(fd, stock, BUFFER_SIZE);
		stock[truclis] = '\0';
		truc = ft_strjoin(truc, stock);
		if (truclis <= 0)
			return (NULL);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	return (truc);
}

char	*get_next_line(int fd)
{
	static char	stock[BUFFER_SIZE + 1];
	char		*buffer;
	int			truclis;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	truclis = 0;
	buffer = stock;
	if (stock [0] == '\0')
		buffer = ft_readstuff(fd, truclis, stock);
	if (buffer == NULL)
		return (NULL);
	buffer = theline(buffer);
	thenextline(stock);
	return (buffer);
}

int main ()
{
	char	*a;
	int		file;

	file = open("test.txt", O_RDONLY);
	while (1)
	{
		a = get_next_line(file);
		if (a == NULL)
			return (0);
		printf("%s", a);
		free(a);
	}
}
