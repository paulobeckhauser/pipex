/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:40:02 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/16 19:50:38 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned long	i;
	int				len_src;
	size_t			len_dst;
	size_t			j;

	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	j = len_dst;
	if (dstsize >= (j + 1))
	{
		while ((i < dstsize - len_dst - 1) && src[i])
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
		if (dstsize > len_src + len_dst)
			return (len_src + len_dst);
		else
			return (len_src + len_dst);
	}
	else
		return (len_src + dstsize);
}
