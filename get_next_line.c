/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yiliu <yiliu@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:22:55 by yiliu             #+#    #+#             */
/*   Updated: 2024/05/11 18:31:32 by yiliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*result;
	char	**buffer;
	int		maximumlinelength;
	int		bytesread;
	int		i;

	maximumlinelength = 128;
	buffer = (char **)malloc(maximumlinelength * sizeof(char *));
	if (!buffer)

	bytesread = read(fd, buffer, sizeof(buffer));
	result = (char *)malloc(bytesread * sizeof(char));
	if (!result)

	i = 0;
	while (i < bytesread)
	{
		result[i] == buffer[i];
		i++;
	}
	free (buffer);
	return (result);
}
