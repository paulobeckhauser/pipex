/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:01:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 22:01:53 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	execute_commands(t_info *structure, int i)
{
	int	j;
	int	l;

	j = 0;
	while (j < structure->number_commands - 1)
	{
		close_pipes_child(structure, j);
		j++;
	}
	structure->argv_commands = ft_split(structure->full_string[i], ' ');
	l = 0;
	while (structure->argv_commands[l])
	{
		structure->argv_commands[l] = ft_strtrim(structure->argv_commands[l],
				"\'");
		structure->argv_commands[l] = ft_strtrim(structure->argv_commands[l],
				"\"");
		l++;
	}
	stop_error_commands(structure, i);
}