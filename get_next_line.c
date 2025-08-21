/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@Amman.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:36:56 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/21 18:43:07 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

// char *get_next_line(int fd)
// {
     
// }


int main()
{
    static char *buff;
    int fd;
    int bytes_read;
    fd = open("hello.txt", O_RDONLY);
    buff = ft_calloc(sizeof(char), 100);
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
