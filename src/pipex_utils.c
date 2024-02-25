/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:18:58 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 16:21:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void pipes_creation(t_info *structure)
{
    int i;


    // structure->fds_pipes = (int **)ft_calloc((structure->number_commands - 1), sizeof(int *));
	structure->fds_pipes = (int **)ft_calloc((structure->number_commands), sizeof(int *));
	if(structure->fds_pipes == NULL)
	{
		perror("Memory allocation failed");
		return ;
	}

	i = 0;
	while(i < structure->number_commands - 1)
	{
		structure->fds_pipes[i] = (int *)ft_calloc( 2 + 1 , sizeof(int));
		if (structure->fds_pipes[i] == NULL)
		{
			perror("Memory allocation failed");
			free_fds_pipes(structure);
			return;
		}

		if (pipe(structure->fds_pipes[i]) == -1)
		{
			perror("Pipe creation failed");
		}
		
		// pipe(structure->fds_pipes[i]);
		i++;
	}
	structure->fds_pipes[i] = NULL;
}


void pipes_utilization(t_info *structure)
{
    int i;
    int j;
	int k;
    
    i = 0;

	while (i < structure->number_commands)
	{
		structure->pid[i] = fork();

		if (structure->pid[i] == 0)
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

			j = 0;
			while (j < structure->number_commands - 1)
			{
				close(structure->fds_pipes[j][0]);
				close(structure->fds_pipes[j][1]);
				j++;
			}

			structure->argv_commands = ft_split(structure->commands_full_string[i],
					' ');
			execve(structure->path_commands[i], structure->argv_commands, structure->envp);

			// k = 0;
			// while (structure->argv_commands[k])
			// {
			// 	free(structure->argv_commands[k]);
			// 	k++;
			// }
			// free(structure->argv_commands);
		}
		i++;
	}
}

void close_pipes(t_info *structure)
{
    int i;
    
    i = 0;
	while (i < structure->number_commands - 1)
	{
		close(structure->fds_pipes[i][0]);
		close(structure->fds_pipes[i][1]);
		i++;
	}
}

void wait_child_processess(t_info *structure)
{
    int i;
    
    i = 0;
	while (i < structure->number_commands)
	{
		waitpid(structure->pid[i], NULL, 0);
		i++;
	}
}
