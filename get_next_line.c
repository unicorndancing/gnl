#include "get_next_line.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE = 5
# endif

void	writestuff(int trucecri, char *str)
{
	write(1, str, trucecri);
}
int	ft_readstuff(int fd, int truclis, char *stock)
{
	int		i;
	char	*truc;
	int		veriftruc;

	veriftruc = 0;
	truc = NULL;
	i = 0;
	stock = malloc(sizeof (char) * (BUFFER_SIZE + 1));
	if (!stock)
		return (0);
	while (stock[i] != '\n')
	{
		i = 0;
		truclis = read(fd, stock, BUFFER_SIZE);
		veriftruc += truclis;
		stock[truclis] = '\0';
		truc = ft_strjoin(truc, stock);
		while (i < truclis && stock[i] != '\n')
			i++;
	}
	i = 0;
	while (truc[i++] != '\n'){}	
	writestuff(i, truc);
	return (i);
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
	//buffer = ft_copystuff(truclis, stock);
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
