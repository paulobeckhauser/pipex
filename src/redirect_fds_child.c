/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fds_child.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:13:08 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 13:45:56 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	redirect_fds_child(t_info *structure, int i)
{
	int	dev_null_fd;

	if (i == 0)
	{
		if (structure->input_fd != 0)
		{
			dup2(structure->input_fd, STDIN_FILENO);
			close(structure->input_fd);
		}
		else
		{
			dev_null_fd = open("/dev/null", O_RDONLY);
			dup2(dev_null_fd, STDIN_FILENO);
			close(dev_null_fd);
		}
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
}
