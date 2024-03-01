/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:59:53 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{
	t_info	structure;

	if (argc == 5)
	{
		store_main_arguments(argc, argv, envp, &structure);
		structure.is_here_doc = 0;
		store_variables(&structure);
		open_input_output_fds(&structure);
		create_pipes(&structure);
		allocate_memory_pid(&structure);
		create_child_processes(&structure);
		close_pipes_parent(&structure);
		wait_child_processess(&structure);
		free_variables(&structure);
	}
	else
	{
		errno = EINVAL;
		perror("Not correct number of arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
