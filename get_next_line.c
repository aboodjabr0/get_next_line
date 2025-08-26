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

char *ft_join(char *full_file, char *s_chunk)
{
    char *tmp;

    tmp = ft_strjoin(full_file, s_chunk);
    free (full_file);
    return(tmp);
}
char *read_file(int fd, char *full_file)
{
    char *s_chunk;
    int bytes_read;

    if (!full_file)
        full_file = ft_calloc(1, 1);
    s_chunk = ft_calloc(BUFF_SIZE + 1, sizeof(char));
    bytes_read = 1;
    while (bytes_read > 0)
    {
        bytes_read = read(fd, s_chunk, BUFF_SIZE);
        if (bytes_read == -1)
        {
            free(s_chunk);
            return (NULL);
        }
        s_chunk[bytes_read] = '\0';
        full_file = ft_join(full_file, s_chunk);
        if (ft_strchr(full_file, '\n'))
            break;
    }
    free(s_chunk);
    return (full_file);
}

// char *get_next_line(int fd)
// {
     
// }

int main()
{
    int fd;
    char *buff = NULL;
    fd = open("hello.txt", O_RDONLY);
    buff = read_file(fd, buff);
    printf("%s", buff);
    close(fd);
    free (buff);

}