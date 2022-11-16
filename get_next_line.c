/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:05 by hnait             #+#    #+#             */
/*   Updated: 2022/11/16 23:48:52 by hnait            ###   ########.fr       */
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

	if (buff == NULL)
		buff = (char *) calloc (sizeof(char), BUFF_SIZE + 1);
	// printf("my index buffer start of function %d\n", index_buffer);
	// printf("my old return start of function %s\n", old_return);
	if (index_buffer == 0)
	{
		read(fd, buff, BUFF_SIZE);
		printf("here");
		return_length += BUFF_SIZE;
		new_return = (char *)calloc(sizeof(char), return_length + 1);
		if (old_return != NULL)
		{
			ft_strlcpy(new_return, old_return, ft_strlen(old_return) + 1);
			free(old_return);
		}
	}
	else
	{
		// printf("am here %s\n", &buff[index_buffer]);
		old_return = (char *)calloc(sizeof(char), BUFF_SIZE + 1);
		ft_strlcpy(old_return, &buff[index_buffer], BUFF_SIZE + 1);
		// printf("old return : %s, buff : %c, index buff : %d\n", old_return, buff[index_buffer], index_buffer);// got here loop
		index_buffer = 0;
		printf("no");

		return (get_next_line(fd));
	}
	while (buff[index_buffer++] != '\0')
	{
		new_return[return_length + index_buffer - BUFF_SIZE] = buff[index_buffer];
		// printf("%c\n",buff[index_buffer]);
		// printf("old return : %s, buff : %d, index buff : %d\n", old_return, buff[index_buffer], index_buffer);// got here loop
		if (buff[index_buffer] == '\n')
		printf("yes");
		{
		printf("hello");
			index_buffer++;
			// printf("my index buffer %d\n\n", index_buffer);
			return (new_return);
		}
		if (buff[index_buffer] == '\0')
		{
			old_return = new_return;
		printf("cool");
			index_buffer = 0;
			return (get_next_line(fd));
		}
	}
	return (new_return);
}