/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:26:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/26 10:52:35 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	number_commands(t_info *structure)
{
	if (structure->is_here_doc)
	{
		structure->number_commands = structure->argc - 4;
	}
	else
		structure->number_commands = structure->argc - 3;
}


void store_variables(t_info *structure)
{
	number_commands(structure);
	commands_full_string_store(structure);
	commands_allocate_memory(structure);
	commands_store(structure);
	get_path_env(structure);
	path_commands_store(structure);
}


void free_variables(t_info *structure)
{
		free_commands_full_string(structure);
		free_commands(structure);

		free(structure->path_env);

		free_path_commands(structure);
		// free_fds_pipes(structure);
		free(structure->pid);
}

void pipes_structure(t_info *structure)
{
		structure->input_fd = open(structure->argv[1], O_RDONLY, 0777);
		if (structure->input_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		structure->output_fd = open(structure->argv[structure->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (structure->output_fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		pipes_creation(structure);
		structure->pid = (pid_t *)ft_calloc((structure->number_commands + 1),
				sizeof(pid_t));

		pipes_utilization(structure);
		close_pipes(structure);
		wait_child_processess(structure);
}