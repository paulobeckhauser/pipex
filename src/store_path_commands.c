/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_path_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:18:33 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 02:37:48 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	checking_access(t_info *structure)
{
	int	j;

	j = 0;
	while (structure->path_commands[j])
	{
		if (access(structure->path_commands[j], X_OK) != 0)
		{
			ft_printf("%s: command not found\n", structure->path_commands[j]);
			if (j == structure->number_commands - 1)
			{
				structure->output_fd = open(structure->argv[structure->argc
						- 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
				close(structure->output_fd);
				free_2d_array_char(structure->full_string);
				free_2d_array_char(structure->commands);
				free(structure->path_env);
				free_2d_array_char(structure->path_commands);
				exit(127);
			}
		}
		j++;
	}
}

void	store_path_commands(t_info *structure)
{
	int	i;
	int	j;

	allocate_memory_path_commands(structure);
	i = 0;
	j = 0;
	while (structure->commands[i])
	{
		structure->possible_paths = split_concat_command(structure->path_env,
				':', structure->commands[i]);
		get_path_command(structure, i, j);
		j = -1;
		while (structure->possible_paths[++j] != NULL)
			free(structure->possible_paths[j]);
		free(structure->possible_paths);
		i++;
	}
	structure->path_commands[i] = NULL;
	checking_access(structure);
}
