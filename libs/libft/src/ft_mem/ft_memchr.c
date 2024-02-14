/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:18:41 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/21 12:55:55 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *)s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == c)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}
