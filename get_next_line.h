#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFF_SIZE
#define BUFF_SIZE 42
#endif

 void	*ft_calloc(size_t nmemb, size_t size);
 int	ft_strlen(const char *s);
 void	*ft_bzero(void *s, size_t n);
 char	*ft_strchr(const char *s, int c);
 char	*ft_strjoin(char const *s1, char const *s2);
//char *get_next_line(int fd);

#endif