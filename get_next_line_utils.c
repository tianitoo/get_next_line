/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnait <hnait@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:51:29 by hnait             #+#    #+#             */
/*   Updated: 2022/12/03 11:08:40 by hnait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize <= 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ss;
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;

	if (!s1)
		return (0);
	if (!s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ss = (char *) malloc (sizeof(char) * (len_s1 + len_s2 + 1));
	if (!ss)
		return (0);
	i = -1;
	while (++i < len_s1)
		ss[i] = s1[i];
	j = -1;
	while (++j < len_s2)
		ss[i + j] = s2[j];
	ss[i + j] = 0;
	return (ss);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	tab = malloc(count * size);
	if (!tab)
		return (0);
	ft_bzero(tab, count * size);
	return (tab);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*ss;

	ss = (char *) s;
	i = 0;
	while (i < n)
	{
		ss[i] = 0;
		i++;
	}
}
// int main()
// {
// 	int fd = open("test.txt", O_CREAT | O_RDWR);
// 	char *ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	free(ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	free(ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	ss = get_next_line(fd);
// 	printf("|%s|\n", ss);
// 	system("leaks a.out");
// }