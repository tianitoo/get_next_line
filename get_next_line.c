/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:48:05 by hnait             #+#    #+#             */
/*   Updated: 2022/12/01 19:13:47 by hnait            ###   ########.fr       */
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

void fail(int number_of_strings, ...)
{
	int		i;
	char	*ss;
	va_list	vl;
	
	i = 0;
	va_start(vl, number_of_strings);
	while (i < number_of_strings)
	{
		ss = va_arg(vl, char *);
		printf("%p", ss);
		free(ss);
		ss = NULL;
		i++;
	}
	
}

int	find_nl(char *buffer)
{
	int	i;

	printf("%p\n", buffer);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		buffer[i++] = 'p';
	if (buffer[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*ss;
	char		*new_ss;
	int			i;
	int			j;
	int			eof;

	if (fd < 0)
		return (NULL);
	i = 0;
	j = 0;
	eof = 1;
	if (!buffer)
	{
		buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		eof = read(fd, buffer, BUFFER_SIZE);
		if (eof <= 0)
		{
			free(buffer);
			return (buffer = NULL, NULL);
		}
	}
	printf("%p\n", buffer);
	ss = (char *)ft_calloc(sizeof(char), find_nl(buffer) + 1);
	if (!ss)
	{
		free(buffer);
		buffer = NULL;
		return (0);
	}
	while (buffer[i] != '\n')
	{
		if (buffer[i] != '\0')
			ss[j++] = buffer[i];
		i++;
		if (eof != 0 && buffer[i] == '\0')
		{
			ft_bzero(buffer, BUFFER_SIZE);
			eof = read(fd, buffer, BUFFER_SIZE);
			if (eof <= 0)
			{
				fail(1, buffer);
				if (ft_strlen(ss) == 0 || eof < 0)
					return (free(ss), NULL);
				return (ss);
			}
			new_ss = (char *)ft_calloc(sizeof(char),
					ft_strlen(ss) + find_nl(buffer) + 1);
			if (!new_ss)
			{
				fail(1, buffer);
				return (fail(1, ss), NULL);
			}
			ft_strlcpy(new_ss, ss, ft_strlen(ss) + 1);
			free(ss);
			ss = new_ss;
			i = 0;
		}
	}
	if (buffer[i] == '\n')
		ss[j] = '\n';
	advance_buffer(buffer, i + 1);
	return (ss);
}
