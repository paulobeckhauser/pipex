/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:01:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 14:57:20 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	stop_error_commands(t_info *structure, int i)
{
	int	j;

	j = 0;
	if (execve(structure->path_commands[i], structure->argv_commands,
			structure->envp) == -1)
		free_2d_array_char(structure->argv_commands);
	free_variables(structure);
	exit(1);
}

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
	handle_single_quotes(structure);
	handle_double_quotes(structure);
	stop_error_commands(structure, i);
}
