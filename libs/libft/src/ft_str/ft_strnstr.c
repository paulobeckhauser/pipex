/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:48:06 by pabeckha          #+#    #+#             */
/*   Updated: 2023/11/26 13:59:33 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_initiate_vars(size_t *i, size_t *j, size_t *g);
static void	increment_vars(size_t *i, size_t *g);
static char	*increment_string(size_t g, const char *haystack);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	g;

	ft_initiate_vars(&i, &j, &g);
	while ((len > i) && haystack[i] && needle[j] && haystack[i] != needle[j])
	{
		increment_vars(&i, &g);
	}
	while ((len > i) && haystack[i] && needle[j])
	{
		if (haystack[i] == needle[j])
			j++;
		else
		{
			i = i - j;
			g++;
			j = 0;
		}
		i++;
	}
	if (j == ft_strlen(needle))
		return (increment_string(g, haystack));
	else
		return (NULL);
}

static void	ft_initiate_vars(size_t *i, size_t *j, size_t *g)
{
	*i = 0;
	*j = 0;
	*g = 0;
}

static void	increment_vars(size_t *i, size_t *g)
{
	*i = *i + 1;
	*g = *g + 1;
}

static char	*increment_string(size_t g, const char *haystack)
{
	while (g-- > 0)
	{
		haystack++;
	}
	return ((char *)haystack);
}
