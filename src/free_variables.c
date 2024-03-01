/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 01:15:59 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:30:48 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
