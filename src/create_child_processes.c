/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:49:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/04 11:06:49 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_fds_parents(t_info *structure, int i)
{
	close(structure->fds_pipes[i][0]);
	if (i != structure->number_commands - 1)
		close(structure->fds_pipes[i + 1][1]);
}

void	create_child_processes(t_info *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_commands)
	{
		structure->pid[i] = fork();
		if (structure->pid[i] == 0)
		{
			redirect_fds_child(structure, i);
			execute_commands(structure, i);
		}
		i++;
	}
}
