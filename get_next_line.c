/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpes <jpes@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:12:48 by jpes              #+#    #+#             */
/*   Updated: 2023/06/05 20:57:40 by jpes             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_get_before_line(int fd, char *buffer, char *stash)
{
	int bytes_read;
   char *temp;

   bytes_read = 1;
   while (bytes_read)
   {
      bytes_read = read(fd, buffer, BUFFER_SIZE);
      if (bytes_read == -1)
      {
         return (0);
      }
      if (bytes_read == 0)
      {
         break;
      }
      if (!stash)
      {
         stash = ft_strdup("");
      }
      temp = stash;
      stash = ft_strjoin(temp, buffer);
      free(temp);
      temp = NULL;
      if (ft_strchr(buffer, '\n'))
      {
         break;
      }
      buffer[bytes_read] = '\0';
   }
   return (stash);
}

static char *ft_get_after_line(char *line)
{
   size_t   n;
   char     *stash;

   n = 0;
   while (line[n] != '\n' && line[n] != '\0')
   {
      n ++;
   }
   if (line[n] == '\0'|| line[1] == '\0')
   {
      return (0);
   }
   stash = ft_substr(line, n + 1, ft_strlen(line) - n);
   if (stash[0] == '\0')
   {
      free(stash);
      stash = NULL;
   }
   line[n + 1] = '\0';
   return (stash);
}

char	*get_next_line(int fd)
{
	
	char *line;
	char *buffer;
	static char *stash;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (0);
	}
	line = ft_get_before_line(fd, buffer, stash);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (NULL);
	}
	stash = ft_get_after_line(line);
	return (line);
}


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