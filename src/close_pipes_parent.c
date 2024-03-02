/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes_parent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:33:28 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 13:46:04 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	close_pipes_parent(t_info *structure)
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
