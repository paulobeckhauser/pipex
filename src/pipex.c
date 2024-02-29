/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 11:33:50 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{
	int		i;
	t_info	structure;

	store_arguments(argc, argv, envp, &structure);
	check_here_doc(&structure);
	if (structure.is_here_doc)
		here_doc_structure(&structure);
	store_variables(&structure);
	pipes_structure(&structure);
	free_variables(&structure);
	i = 0;
	while (structure.fds_pipes[i])
	{
		free(structure.fds_pipes[i]);
		i++;
	}
	free(structure.fds_pipes);
	return (0);
}
