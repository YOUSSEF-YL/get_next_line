/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 22:57:01 by ybachar           #+#    #+#             */
/*   Updated: 2022/12/06 14:35:07 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*str[OPEN_MAX];
	char		*res;

	str[fd] = reader(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	res = get_ligne(str[fd]);
	str[fd] = get_extra(str[fd]);
	return (res);
}

// int main()
// {
//     char *str;
//     int fd = open("foo.txt", O_RDONLY);
// 	 int fd1 = open("foo1.txt", O_RDONLY);
// 	  int fd2 = open("foo2.txt", O_RDONLY);
//     // str = get_next_line(fd);
//     // printf("%s", str);

//     // while (str)
//     // {
// 	// 	str = get_next_line(fd);
// 	// 	printf("%s", str);
// 	// }

//     printf("%s", get_next_line(fd));
// 	printf("\n%s\n","file 1");
//     printf("%s", get_next_line(fd1));
// 	printf("\n%s\n","file 2");
//     printf("%s", get_next_line(fd));
//  	printf("\n%s\n","file 1");
//     printf("%s", get_next_line(fd2));
// 	printf("%s\n","file 3");
//     printf("%s", get_next_line(fd1));
// 	printf("%s", get_next_line(fd1));
// 	printf("\n%s\n","file 2");
//     //printf("%s\n", get_next_line(fd));
//     printf("%s", get_next_line(fd2));
// 	printf("%s", get_next_line(fd2));
// 	printf("\n%s\n","file 3");

	
// }