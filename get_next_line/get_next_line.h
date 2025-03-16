
#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define  BUFFER_SIZE 1234
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
int     ft_strlen(const char *str);
char    *ft_strcat(char *dest, char *src);
char    *ft_strcpy(char *dest, const char *src);
char    *ft_strncpy(char *dest, const char *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

#endif