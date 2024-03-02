/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:20:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 12:06:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	store_commands(t_info *structure)
{
	int	i;
	int	j;

	i = 0;
	while (structure->full_string[i])
	{
		j = 0;
		while (structure->full_string[i][j]
			&& structure->full_string[i][j] != ' ')
		{
			structure->commands[i][j] = structure->full_string[i][j];
			j++;
		}
		i++;
	}
	structure->commands[i] = NULL;
}
