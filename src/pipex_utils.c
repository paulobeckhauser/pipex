/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:18:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 10:51:54 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipes_creation(t_info *structure)
{
	int	i;

	structure->fds_pipes = (int **)ft_calloc((structure->number_commands),
			sizeof(int *));
	if (structure->fds_pipes == NULL)
	{
		perror("Memory allocation failed");
		return ;
	}
	i = 0;
	while (i < structure->number_commands - 1)
	{
		structure->fds_pipes[i] = (int *)ft_calloc(2 + 1, sizeof(int));
		if (structure->fds_pipes[i] == NULL)
		{
			perror("Memory allocation failed");
			free_fds_pipes(structure);
			return ;
		}
		if (pipe(structure->fds_pipes[i]) == -1)
			perror("Pipe creation failed");
		i++;
	}
	structure->fds_pipes[i] = NULL;
}

void	pipes_utilization(t_info *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_commands)
	{
		structure->pid[i] = fork();
		if (structure->pid[i] == 0)
		{
			conditions_child(structure, i);
			execution_commands(structure, i);
		}
		i++;
	}
}

void	close_pipes(t_info *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_commands - 1)
	{
		close(structure->fds_pipes[i][0]);
		close(structure->fds_pipes[i][1]);
		i++;
	}
}

void	wait_child_processess(t_info *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_commands)
	{
		waitpid(structure->pid[i], NULL, 0);
		i++;
	}
}
