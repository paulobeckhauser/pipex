/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:20:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:54:50 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	command_full_string_store(t_info *structure)
{
	int	first_command_position;

	if (structure->is_here_doc == 1)
		first_command_position = 3;
	else
		first_command_position = 2;
	structure->full_string = (char **)malloc(((structure->argc - 3) + 1)
			* sizeof(char *));
	if (!structure->full_string)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	copy_string(structure, first_command_position);
}

void	commands_allocate_memory(t_info *structure)
{
	int	i;
	int	j;

	i = 0;
	structure->commands = (char **)ft_calloc((structure->argc - 2),
			sizeof(char *));
	if (!structure->commands)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	while (structure->full_string[i])
	{
		j = 0;
		while (structure->full_string[i][j]
			&& structure->full_string[i][j] != ' ')
			j++;
		structure->commands[i] = (char *)ft_calloc((j + 1), sizeof(char));
		i++;
	}
}

void	commands_store(t_info *structure)
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

void	path_commands_store(t_info *structure)
{
	int	i;
	int	j;

	allocate_memory_path(structure);
	i = 0;
	while (structure->commands[i])
	{
		structure->possible_paths = split_concat_command(structure->path_env,
				':', structure->commands[i]);
		condition_possible_paths(structure, i, j);
		fail_paths(structure, i);
		j = -1;
		while (structure->possible_paths[++j] != NULL)
			free(structure->possible_paths[j]);
		free(structure->possible_paths);
		i++;
	}
	structure->path_commands[i] = NULL;
}

/***
 * void exit_program(t_data *data, INT I, CHA\R *MESSAGE)
 * {
 * 		FRE
 * }
*/