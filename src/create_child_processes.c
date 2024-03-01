/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:49:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 22:02:23 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	create_child_processes(t_info *structure)
{
	int	i;

	i = 0;
	while (i < structure->number_commands)
	{
		structure->pid[i] = fork();
		if (structure->pid[i] == 0)
		{
			conditions_child(structure, i);
			execute_commands(structure, i);
		}
		i++;
	}
}
