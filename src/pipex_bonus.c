/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 11:23:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{
	int		i;
	t_info	structure;

	if (argc >= 5)
	{
		store_main_arguments(argc, argv, envp, &structure);
		check_here_doc(&structure);
		if (structure.is_here_doc == 1)
			here_doc_structure(&structure);
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
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
