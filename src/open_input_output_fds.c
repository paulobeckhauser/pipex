/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_input_output_fds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:28:32 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:34:45 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	open_input_output_fds(t_info *structure)
{
	structure->input_fd = open(structure->argv[1], O_RDONLY, 0777);
	if (structure->input_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	if (structure->is_here_doc == 1)
		structure->output_fd = open(structure->argv[structure->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		structure->output_fd = open(structure->argv[structure->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (structure->output_fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
}
