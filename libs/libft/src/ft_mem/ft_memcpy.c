/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:07:41 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/21 15:33:58 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned long	i;
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	ptr_dest = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dst);
}
