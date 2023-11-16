#include "get_next_line.h"
#include <stdio.h>
// #ifndef BUFFER_SIZE
// # define BUFFER_SIZE = 5
// # endif

char *theline(char *str)
{
	int i;
	int j;
	char *truc;

	i = 0;
	j = 0;
	while (str[i] != '\n' || str[i] != '\0')
		i++;
	truc = malloc (sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != '\n' || str[i] != '\0')
	{
		truc[i] = str[i];
		i++;
	}
	truc[i] = '\0';
	free(str);
	str = NULL;
	return (truc);
}

char *thenextline(char *stock)
{
	int i;
	int j;
	char *truc;
	while (stock[i] != '\n' || stock[i] != '\0')
		i++;
	truc = malloc(sizeof (char) * (BUFFER_SIZE - i + 1));
	if (!truc)
		return (NULL);
	while (stock[i])
	{
		truc[j] = stock[i];
		i++;
		j++;
	}
	truc[j] = '\0';
	free(stock);
	stock = NULL;
	return (truc);
}

char	*ft_readstuff(int fd, int truclis, char *stock)
{
	int		i;
	char	*truc;
	int		veriftruc;

	veriftruc = 0;
	truclis = BUFFER_SIZE;
	truc = NULL;
	i = 1;
	stock = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!stock)
		return (0);
	while (truclis == BUFFER_SIZE)
	{
		truclis = read(fd, stock, BUFFER_SIZE);
		stock[truclis] = '\0';
		truc = ft_strjoin(truc, stock);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	free(stock);
	stock = NULL;
	return (truc);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*buffer;
	int			truclis;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = NULL;
	truclis = 0;
	stock = ft_readstuff(fd, truclis, stock);
	if (!stock)
		return (NULL);
	buffer = theline(stock);
	stock = thenextline(stock);
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
