/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:05 by hnait             #+#    #+#             */
/*   Updated: 2022/12/03 23:17:13 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*advance_buffer(char *buffer, int i)
{
	int	j;

	j = 0;
	while (buffer[i])
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	while (buffer[j])
		buffer[j++] = '\0';
	return (buffer);
}

int	find_nl(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	return (i);
}
void allocate_buffer(char **buffer, int fd)
{
	if (!(*buffer))
	{
		*buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!*buffer || read(fd, *buffer, BUFFER_SIZE) <= 0)
		{	
			free(*buffer);
			*buffer = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ss;
	char		*new_ss;
	int			i_j[2];
	int			eof;

	if (fd < 0)
		return (NULL);
	i_j[0] = 0;
	i_j[1] = 0;
	eof = 1;
	allocate_buffer(&buffer, fd);
	if (!buffer)
		return (NULL);
	ss = (char *)ft_calloc(sizeof(char), find_nl(buffer) + 1);
	if (!ss)
		return (free(buffer), buffer = NULL, NULL);
	while (buffer[i_j[0]] != '\n')
	{
		if (buffer[i_j[0]] != '\0')
			ss[i_j[1]++] = buffer[i_j[0]++];
		if (eof != 0 && buffer[i_j[0]] == '\0')
		{
			ft_bzero(buffer, BUFFER_SIZE);
			eof = read(fd, buffer, BUFFER_SIZE);
			if (eof <= 0)
			{
				if (ft_strlen(ss) == 0 || eof < 0)
					return (free(ss), free(buffer), buffer = NULL, NULL);
				return (free(buffer), buffer = NULL, ss);
			}
			new_ss = (char *)ft_calloc(sizeof(char),
					ft_strlen(ss) + find_nl(buffer) + 1);
			if (!new_ss)
				return (free(ss), free(buffer), buffer = NULL, NULL);
			ft_strlcpy(new_ss, ss, ft_strlen(ss) + 1);
			free(ss);
			ss = new_ss;
			i_j[0] = 0;
		}
	}
	if (buffer[i_j[0]] == '\n')
		ss[i_j[1]] = '\n';
	return (advance_buffer(buffer, i_j[0] + 1), ss);
}
