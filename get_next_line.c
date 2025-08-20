/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:36:56 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/20 18:31:08 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

// char *get_next_line(int fd)
// {
     
// }

static char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)(s + i));
		}
		i++;
	}
	if ((char)c == '\0')
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

int main()
{
    static char *buff;
    int fd;
    int bytes_read;
    fd = open("hello.txt", O_RDONLY);
    buff = malloc (sizeof(char) * BUFF_SIZE);
    if (!buff)
    {
        return (NULL);
    }
    if (fd == -1)
    return (-1);
    bytes_read = read(fd, buff, sizeof(buff));
    ft_strchr(buff, '\n');
    
    close(fd);
    return(fd);
    
}
