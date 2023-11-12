#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 5
# endif

int	ft_readstuff(int fd, int truclis, char *stock)
{
	int	i;

	i = 0;
	stock = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!stock)
		return (0);
	while (stock[i] != '\n')
	{
		i = 0;
		truclis = read(fd, stock, BUFFER_SIZE);
		stock[truclis] = '\0';
		ft_copystuff(truclis, stock);
		while (i < truclis && (stock[i] != '\n' || stock[i] != '\0'))
			i++;
	}
	return (truclis);
}

char	*ft_copystuff(int truclis, char *stock)
{
	char	*truc;
	int		i;

	i = 0;
	truc = malloc(sizeof (char) * truclis);
	if (!truc)
		return (NULL);
	while (i < truclis)
	{
		truc[i] = stock[i];
		i++;
	}
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
	truclis = ft_readstuff(fd, truclis, stock);
	buffer = ft_copystuff(truclis, stock);
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
		free(a);
	}
}
