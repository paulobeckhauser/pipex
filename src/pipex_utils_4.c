/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 10:43:49 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 18:43:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	conditions_child(t_info *structure, int i)
{
	if (i == 0)
	{
		dup2(structure->input_fd, STDIN_FILENO);
		close(structure->input_fd);
	}
	else
		dup2(structure->fds_pipes[i - 1][0], STDIN_FILENO);
	if (i == structure->number_commands - 1)
	{
		dup2(structure->output_fd, STDOUT_FILENO);
		close(structure->output_fd);
	}
	else
		dup2(structure->fds_pipes[i][1], STDOUT_FILENO);
}

void	execution_commands(t_info *structure, int i)
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

void	ft_pipes(t_info *structure)
{
	store_variables(structure);
	pipes_structure(structure);
	free_variables(structure);
}
