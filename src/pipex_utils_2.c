/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:26:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:56:41 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	number_commands(t_info *structure)
{
	if (structure->is_here_doc == 1)
		structure->number_commands = structure->argc - 4;
	else
		structure->number_commands = structure->argc - 3;
}

void	store_variables(t_info *structure)
{
	number_commands(structure);
	command_full_string_store(structure);
	commands_allocate_memory(structure);
	commands_store(structure);
	get_path_env(structure);
	path_commands_store(structure);
}

void	free_variables(t_info *structure)
{
	if (structure->full_string)
		free_2d_array_char(structure->full_string);
	if (structure->commands)
		free_2d_array_char(structure->commands);
	if (structure->path_env)
		free(structure->path_env);
	if (structure->path_commands)
		free_2d_array_char(structure->path_commands);
	if (structure->pid)
		free(structure->pid);
	if (structure->fds_pipes)
		free_2d_array_int(structure->fds_pipes);
}

void	pipes_structure(t_info *structure)
{
	structure->input_fd = open(structure->argv[1], O_RDONLY, 0777);
	if (structure->input_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (structure->is_here_doc == 1)
		structure->output_fd = open(structure->argv[structure->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		structure->output_fd = open(structure->argv[structure->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (structure->output_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	pipes_definition(structure);
}
