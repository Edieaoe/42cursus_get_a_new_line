/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yxu <yxu@student.42tokyo.jp>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:22:55 by yiliu             #+#    #+#             */
/*   Updated: 2024/06/15 23:07:12 by yxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *save)
{
	char	*buffer;
	int		readbyte;

	buffer = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readbyte = 1;
	while (readbyte != 0)
	{
		readbyte = read(fd, buffer, BUFF_SIZE);
		if (readbyte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readbyte] = '\0';
		save = ft_strjoin(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_line(char *save)
(
	char	*line;
	int		i;

	i = 0;
	while (!save[i] && save[i] != '\n')
		i++;
	line = (char *)malloc((i + 2) * sizeof(char))
	if (!line)
		return (NULL);
	i = 0;
	while (!save[i] && save[i] != '\n')
		line[i++] == save[i++];
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
)

char	*afterline(char *save)
{
	char	*line;
	int		i;
	int		n;

	line = get_line(save);
	i = ft_strlen(line) + 1;
	n = 0;
	while (!save[i])
		save[n++] = save[i++];
	save[n] = '\0';
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	save = ft_read(fd, save);
	line = get_line(save);
	save = afterline(save);
	return (line);
}
