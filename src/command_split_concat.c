/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_concat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:57:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 15:51:31 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	int len_command;
	// const int len_command = ft_strlen(command);
	int total_size;

	if (command == NULL)
	{
		return (NULL);
	}
	len_command = ft_strlen(command);
	
	i = 0;
	total_size = end - start + 1 + 1 + len_command;
	word = (char *)ft_calloc(total_size, sizeof(char));
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
	ft_strlcat(word, command, total_size);
	word[i + len_command] = '\0';
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

char	**split_concat_command(char const *s, char c, char *command)
{
	char	**array;
	size_t	i;
	int		j;
	int		s_word;
	size_t	s_len;

	ft_initiate_vars(&i, &j, &s_word);
	s_len = ft_strlen(s);
	array = ft_calloc((word_count(s, c) + 2), sizeof(char *));
	if (!array)
		return (NULL);
	while (i < s_len)
	{
		if (s[i] != c && s_word < 0)
			s_word = i;
		else if ((s[i] == c || i == s_len) && s_word >= 0)
		{
			array[j] = fill_word(s, s_word, i, command);
			if (!(array[j]))
			{
				ft_free(array, j);
				free(array);
				return (NULL);
			}
			s_word = -1;
			j++;
		}
		i++;
	}
	array[j] = NULL;
	return (array);
}
