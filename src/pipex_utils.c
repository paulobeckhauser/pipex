/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:58:53 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 13:46:31 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	execute_pipex_structure(t_info *structure)
{
	store_variables(structure);
	open_input_output_fds(structure);
	create_pipes(structure);
	allocate_memory_pid(structure);
	create_child_processes(structure);
	close_pipes_parent(structure);
	wait_child_processess(structure);
	free_variables(structure);
}
