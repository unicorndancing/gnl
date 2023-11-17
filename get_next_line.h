#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>


char *get_next_line(int fd);
int	ft_strlen(const char *str);
char	*ft_strdup(const char *s, int to_free);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strchr(const char *s, int c);
