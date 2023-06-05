/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpes <jpes@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:48 by jpes              #+#    #+#             */
/*   Updated: 2023/06/05 12:37:29 by jpes             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line;
	line = ft_getline(fd);
	return (line);
	/*line = 0;
	if (fd == -1)
	{
		printf("Erreur lors de l'ouverture du fichier");
		//return ("-1");
	}
	else
	{
		printf ("LA");
		line = ft_getline(fd);
	}
	return (line);*/
}

// char	*get_next_line(int fd)
// {
// 	static t_list *stash;
// 	char		*line;
// 	int	readed;
	
// 	stash = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
// 	{
// 		return (NULL);
// 	}
// 	readed = 1;
// 	line = NULL;
// }

// int	main	(void)
// {
// 	int	fd;
// 	char	*line;
	
// 	fd = open("file.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		printf("Résultat ligne -> %s", line);
// 		free(line);
// 	}
// 	return (0);
// }

int	main	(void)
{
	int fd;
	char *str;
	char *teste = NULL;
	printf("%s\n", teste);
	fd = open("file.txt", O_RDONLY);
	printf("fd -> %d\n", fd);
	str = get_next_line(fd);
	printf("get_next_line 1 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 2 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 3 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 4 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 5 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 6 %s", str);
	str = get_next_line(fd);
	printf("get_next_line 7 %s", str);
	printf("get_nxt_line 8 %s", get_next_line(fd));
	printf("get_nxt_line 9 -%s-\n", get_next_line(fd));
	printf("get_nxt_line 10 -%s-\n", get_next_line(fd));
	// str = get_next_line(fd);
	// printf("get_next_line 8 %s", str);
	// system("leaks a.out");
	// printf("%s", str);
	// str = get_next_line(fd);
	// system("leaks a.out");
	// printf("%s\n", str);
	
	return (0);
}