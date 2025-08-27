/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asauafth <asauafth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:10:23 by asauafth          #+#    #+#             */
/*   Updated: 2025/08/27 16:20:26 by asauafth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *full_file, char *s_chunk)
{
	char	*tmp;

	if (!s_chunk)
		return (full_file);
	tmp = ft_strjoin(full_file, s_chunk);
	free(full_file);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*read_file(int fd, char *full_file)
{
	char	*s_chunk;
	int		bytes_read;

	if (!full_file)
		full_file = ft_calloc(1, 1);
	s_chunk = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!s_chunk)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, s_chunk, BUFFER_SIZE);
		if (bytes_read == -1)
			free(full_file);
		if (bytes_read >= 0)
			s_chunk[bytes_read] = '\0';
		full_file = ft_join(full_file, s_chunk);
		if (!full_file)
			break ;
		if (ft_strchr(full_file, '\n'))
			break ;
	}
	free(s_chunk);
	return (full_file);
}

char	*del_line(char *full_file)
{
	int		i;
	int		j;
	char	*new_buff;

	i = 0;
	if (!full_file)
		return (NULL);
	while (full_file[i] != '\0' && full_file[i] != '\n')
		i++;
	if (!full_file[i])
	{
		free (full_file);
		return (NULL);
	}
	new_buff = ft_calloc(ft_strlen(full_file) - i + 1, sizeof(char));
	if (!new_buff)
	{
		free(full_file);
		return (NULL);
	}
	j = 0;
	while (full_file[++i] != '\0')
		new_buff[j++] = full_file[i];
	free (full_file);
	return (new_buff);
}

char	*read_1st_line(char *full_file)
{
	char	*line;
	int		i;

	i = 0;
	if (!full_file[i])
	{
		return (NULL);
	}
	while (full_file[i] != '\0' && full_file[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (full_file[i] != '\0' && full_file[i] != '\n')
	{
		line[i] = full_file[i];
		i++;
	}
	if (full_file[i] != '\0' && full_file[i] == '\n')
	{
		line[i++] = '\n';
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buff)
		{
			free(buff);
			buff = NULL;
		}
		return (NULL);
	}
	buff = read_file(fd, buff);
	if (!buff)
		return (NULL);
	line = read_1st_line(buff);
	if (!line)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	buff = del_line(buff);
	return (line);
}

// int main()
// {
//     int fd;
//     char *buff;

//     fd = open("hello.txt", O_RDONLY);
//     if (fd < 0)
//         return(0);
//     while ((buff = get_next_line(fd)) != NULL)
//     {
//         printf("%s", buff);
//         free(buff);
//     }
//     close(fd);
//     return 0;
// }
