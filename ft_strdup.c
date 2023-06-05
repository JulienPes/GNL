/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpes <jpes@student.42nice.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:10:52 by jpes              #+#    #+#             */
/*   Updated: 2023/05/31 14:17:25 by jpes             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(char *src)
{
   int     size;
   int     i;
   int     j;
   char    *dest;
   
	i = 0;
   j = 0;
   size = ft_strlen(src);
   dest = malloc ((size + 1) * sizeof (char));
   if (dest == NULL)
	{
		return (0);
	}
   while (src[i] != '\0')
   {
      dest[j] = src[i];
      i++;
      j++;
   }
   dest[i] = '\0';
   return (dest);
}