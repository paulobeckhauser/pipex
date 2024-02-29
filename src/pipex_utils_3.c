/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:41:23 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 10:42:49 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipes_definition(t_info *structure)
{
	pipes_creation(structure);
	structure->pid = (pid_t *)ft_calloc((structure->number_commands + 1),
			sizeof(pid_t));
	pipes_utilization(structure);
	close_pipes(structure);
	wait_child_processess(structure);
}

void	close_pipes_child(t_info *structure, int j)
{
	close(structure->fds_pipes[j][0]);
	close(structure->fds_pipes[j][1]);
}
