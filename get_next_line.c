/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:05 by hnait             #+#    #+#             */
/*   Updated: 2022/11/16 12:06:42 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	index_buffer;
	static int	return_length;
	static char	*buff;
	static char	*old_return;
	static char	*new_return;

	buff = (char *) calloc (sizeof(char), 20 + 1);
	if (index_buffer == 0)
	{
		read(fd, buff, 20);
		return_length += 20;
		new_return = (char *)calloc(sizeof(char), return_length);
		if (old_return != NULL)
		{
			printf("s");
			ft_strlcpy(new_return, old_return, ft_strlen(old_return));
			free(old_return);
		}
	}
	while (buff[index_buffer] != '\0')
	{
		new_return[return_length + index_buffer - 20] = buff[index_buffer];
		index_buffer++;
		if (buff[index_buffer] == '\n')
		{
			old_return = new_return;
			return (new_return);
		}
		if (buff[index_buffer] == '\0')
		{
			index_buffer = 0;
			return (get_next_line(fd));
		}
	}
	return (new_return);
}
