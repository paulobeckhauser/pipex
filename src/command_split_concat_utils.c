/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_split_concat_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 09:33:48 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 19:30:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	*ft_free(char **strs, int count)
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

char	**check_and_free(char **array, int j)
{
	if (!(array[j]))
	{
		ft_free(array, j);
		return (NULL);
	}
	return (array);
}

void	copy_string(t_info *structure, int first_command_position)
{
	int	j;
	int	len_string;

	j = 0;
	while (first_command_position <= structure->argc - 2)
	{
		len_string = ft_strlen(structure->argv[first_command_position]);
		structure->full_string[j] = (char *)malloc((len_string + 1)
				* sizeof(char));
		ft_strlcpy(structure->full_string[j],
			structure->argv[first_command_position], len_string + 1);
		first_command_position++;
		j++;
	}
	structure->full_string[j] = NULL;
}
