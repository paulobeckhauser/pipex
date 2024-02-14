/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 11:09:09 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/17 20:55:03 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;

	c = (unsigned char)c;
	string = (char *)s;
	while (*string != c)
	{
		if (*string != '\0')
			string++;
		else
			return (NULL);
	}
	return (string);
}
