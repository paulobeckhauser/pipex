/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:15:59 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 22:30:29 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_commands_full_string(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->commands_full_string[i])
	{
		free(structure->commands_full_string[i]);
		i++;
	}
	free(structure->commands_full_string);
}

void	free_commands(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->commands[i])
	{
		free(structure->commands[i]);
		i++;
	}
	free(structure->commands);
}

void	free_possible_paths(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->possible_paths[i])
	{
		free(structure->possible_paths[i]);
		i++;
	}
	free(structure->possible_paths);
}

void	free_path_commands(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->path_commands[i])
	{
		free(structure->path_commands[i]);
		i++;
	}
	free(structure->path_commands);
}

void	free_fds_pipes(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->fds_pipes[i])
	{
		free(structure->fds_pipes[i]);
		i++;
	}
	free(structure->fds_pipes);
}
