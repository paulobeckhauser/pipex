/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_concat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:57:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/14 15:24:48 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

static void	ft_initiate_vars(size_t *i, int *j, int *s_word)
{
	*i = 0;
	*j = 0;
	*s_word = -1;
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	*fill_word(const char *str, int start, int end, char *command)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1 + 1 + ft_strlen(command)) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
    word[i] = '/';
    i++;
    ft_strlcat(word, command, ft_strlen(command) + ft_strlen(word) + 1);
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}


char	**ft_split_concat(char const *s, char c, char *command)
{
	char	**array;
	size_t	i;
	int		j;
	int		s_word;

	ft_initiate_vars(&i, &j, &s_word);
	array = ft_calloc((word_count(s, c) + 1), sizeof(char *));
	if (!array)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == ft_strlen(s)) && s_word >= 0)
		{
			array[j] = fill_word(s, s_word, i, command);
			if (!(array[j]))
				return (ft_free(array, j));
			s_word = -1;
			j++;
		}
		i++;
	}
	return (array);
}
