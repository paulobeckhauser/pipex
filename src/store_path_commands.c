/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_path_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:18:33 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:18:54 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	store_path_commands(t_info *structure)
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