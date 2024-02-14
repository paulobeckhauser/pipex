/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:12:18 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/21 15:30:50 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dst;
	size_t			i;

	ptr_src = (unsigned char *)src;
	ptr_dst = (unsigned char *)dst;
	i = -1;
	if (dst < src && (ptr_dst != NULL || ptr_src != NULL))
	{
		while (++i < len)
			ptr_dst[i] = ptr_src[i];
	}
	else if (ptr_dst != NULL || ptr_src != NULL)
	{
		while (len > 0)
		{
			len--;
			ptr_dst[len] = ptr_src[len];
		}
	}
	return (dst);
}
