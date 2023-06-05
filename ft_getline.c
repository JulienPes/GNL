/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpes <jpes@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:47:58 by jpes              #+#    #+#             */
/*   Updated: 2023/06/05 14:11:57 by jpes             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_get_before_line(char *str)
{
	int	i;
	int	n;
	char *before_line;
	i = 0;
	n = 0;
	before_line = NULL;
	while(str[i] != '\n')
	{
		i ++;
	}
	//printf("i vaut %d", i);
	//before_line = (char *)malloc((i + 1)* sizeof(char));
	before_line = ft_calloc(i + 1, sizeof(char));
	//printf("calloc %zu\n", ft_strlen(before_line));
	if (before_line == NULL) 
	{
      printf("Erreur lors de l'allocation de mémoire.\n");
      return ("erreur");
	}
	while(n < i + 1)
	{
		before_line[n] = str[n];
		n ++;
	}
	//printf("calloc after %zu\n", ft_strlen(before_line));
	return(before_line);
}

char *ft_get_after_line(char *str, size_t len)
{
	size_t i;
	size_t n;
	char *after_line;

	i = 0;
	n = 0;
	after_line = NULL;
	free(after_line);
	while (str[i] != '\n')
	{
		i ++;
	}
	after_line = ft_substr(str, (unsigned int)(i + 1),(len));
	return(after_line);
}

char *ft_getline(int fd)
{
	static char *stash;
	char *line;
	char *buffer;
	int bytes_read;
	
   if (read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	bytes_read = 1;
	//buffer = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (bytes_read)
	{
		buffer = ft_bzero(buffer, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
		if (ft_strchr(stash ,'\n') != 0) // Trouve le \n
			break;
		if(bytes_read < BUFFER_SIZE && stash[0] == '\0')
		{
			free(stash);
			stash = NULL;
			return (NULL);	
		}
		/*if (bytes_read < BUFFER_SIZE)
		{
			line = stash;
			free(stash);
			stash = NULL;
			return (line);	
		}*/
	}
	//line = (char *)malloc((ft_strlen(ft_get_before_line(stash)))* sizeof(char));
	line = ft_get_before_line(stash);
	//system("leaks a.out");
	stash = ft_get_after_line(stash,ft_strlen(stash));
	//printf("%zu stash\n", ft_strlen(stash));
	free(buffer);
	//printf("%zu line\n", ft_strlen(line));
	system("leaks a.out");
	return (line);
}