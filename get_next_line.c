/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:05 by hnait             #+#    #+#             */
/*   Updated: 2022/11/17 09:51:17 by hnait            ###   ########.fr       */
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

	printf("index buffer = %d\n", index_buffer);
	printf("return length = %d\n", return_length);
	printf("buff = %s\n", buff);
	printf("old return = %s\n", old_return);
	printf("new return = %s\n\n", new_return);
	int i = 0;
	while (i < 200000000)
	{
		i++;
	}
	

	if (buff == NULL)
		buff = (char *) calloc (sizeof(char), BUFF_SIZE + 1);
	if (index_buffer == 0)
	{
		read(fd, buff, BUFF_SIZE);
		printf("%s\n", buff);
		new_return = (char *)calloc(sizeof(char), return_length + 1);
		if (old_return != NULL)
		{
			ft_strlcpy(new_return, old_return, ft_strlen(old_return) + 1);
			free(old_return);
		}
	}
	else
	{
		new_return = ft_strjoin((char *)malloc(1), &buff[index_buffer]);
		index_buffer = 0;
		return (get_next_line(fd));
	}
	while (buff[index_buffer] != '\0' && index_buffer < 20)
	{
		printf("index_buffer : %d, buff %c\n", index_buffer, buff[index_buffer]);
		new_return[return_length + index_buffer - BUFF_SIZE] = buff[index_buffer];
		index_buffer++;
		if (buff[index_buffer] == '\n')
		{
			index_buffer++;
			old_return = new_return;
			return (new_return);
		}
		if (buff[index_buffer] == '\0')
		{
			return_length += BUFF_SIZE;
			old_return = new_return;
			index_buffer = 0;
			return (get_next_line(fd));
		}
	while (i < 200000000)
	{
		i++;
	}
	}
	return (new_return);
}