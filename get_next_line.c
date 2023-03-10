/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:52:56 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/16 17:33:00 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*reader(int fd, char *str)
{
	char	*buffer;
	int		len;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	len = 1;
	while (!(ft_strchr(str, '\n')) && len != 0)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == 0)
			break ;
		if (len == -1)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[len] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*res;
	if(fd < 0 || fd == 1 || fd == 2)
		return (NULL);
	str = reader(fd, str);
	if (!str)
		return (NULL);
	res = get_ligne(str);
	str = get_extra(str);
	return (res);
}

int main()
{
    char *str;
    // int fd = open("foo.txt", O_RDONLY);
    // str = get_next_line(fd);
    // printf("%s", str);
	str = get_next_line(1);
	printf("%s", str);
    // while (str)
    // {
	// 	str = get_next_line(fd);
	// 	printf("%s", str);
	// }

    // str = get_next_line(fd);
    // printf("%s", str);

    // str = get_next_line(fd);
    // printf("%s", str);
    // str = get_next_line(fd);
    // printf("%s", str);

    // // str = get_next_line(fd);
    // printf("%s", get_next_line(fd));
    // printf("%s", get_next_line(fd));
    // //printf("%s\n", get_next_line(fd));
    // printf("%s", get_next_line(fd));
}
