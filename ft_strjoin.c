/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpes <jpes@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:35:13 by jpes              #+#    #+#             */
/*   Updated: 2023/06/01 13:28:11 by jpes             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		s1len;
	int		s2len;
	size_t	i;
	size_t	n;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
   //printf("s1len -> %d\n", s1len);
	s2len = ft_strlen(s2);
   //printf("s2len -> %d\n", s1len);
	ptr = malloc(s1len + s2len + 1 * sizeof (char));
	i = 0;
	n = 0;
	if (ptr == NULL || (s1 == NULL && s2 == NULL))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[n] != '\0')
	{
		ptr[i + n] = s2[n];
		n++;
	}
	ptr[i + n] = '\0';
	return (ptr);
}