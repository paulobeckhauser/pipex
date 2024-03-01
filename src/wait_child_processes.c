/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_child_processes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:50:55 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:51:49 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
