/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:19 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:56:13 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	stop_error_commands(t_info *structure, int i)
{
	int	j;

	j = 0;
	if (structure->path_commands[i] == NULL)
	{
		write(structure->fds_pipes[i][1], "", 1);
		free_variables(structure);
		j = 0;
		while (structure->fds_pipes[j])
		{
			free(structure->fds_pipes[j]);
			j++;
		}
		free(structure->fds_pipes);
		exit(127);
	}
	else
		execve(structure->path_commands[i], structure->argv_commands,
			structure->envp);
}
