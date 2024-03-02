/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_single_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 14:51:13 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 15:04:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	condition_to_remove_single(t_info *structure, char *string_temp,
		int count, int k)
{
	if ((count > 0) && (count % 2 == 0))
	{
		string_temp = ft_strtrim(structure->argv_commands[k], "\'");
		structure->argv_commands[k] = ft_strdup(string_temp);
		free(string_temp);
	}
}

void	handle_single_quotes(t_info *structure)
{
	int		k;
	int		m;
	int		count;
	char	*string_temp;

	k = 0;
	m = 0;
	count = 0;
	while (structure->argv_commands[k])
	{
		count = 0;
		m = 0;
		while (structure->argv_commands[k][m])
		{
			if (structure->argv_commands[k][m] == '\'')
				count++;
			m++;
		}
		condition_to_remove_single(structure, string_temp, count, k);
		k++;
	}
}
