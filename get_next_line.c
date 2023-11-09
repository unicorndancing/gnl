#include "get_next_line.h"

int readstuff(int fd, int BUFFER_SIZE, int truclis)
{
    char *stock;
    int i;

    i = 0;
    stock = malloc(sizeof (char) * (BUFFER_SIZE + 1));
    if (!stock)
        return (NULL);
    while (stock[i] != '\n')
    {
        i = 0;
        truclis = read(fd, stock, BUFFER_SIZE);
        stock[truclis] = '\0';
        while (stock[i] != '\n' || stock[i] != '\0')
            i++;
    }
    return (truclis);
}

char *copystuff(int truclis)
{
    char *truc;
    int i;

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

char *get_next_line(int fd)
{
    static char *stock;
    char *buffer;
    int truclis;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    buffer = NULL;
    truclis = 0;
    truclis = readstuff(fd, BUFFER_SIZE, truclis);
    buffer = copystuff(truclis);
}


