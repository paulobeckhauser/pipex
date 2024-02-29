/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 12:52:42 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{
	int		i;
	t_info	structure;

	if (argc >= 5)
	{
		store_arguments(argc, argv, envp, &structure);
		check_here_doc(&structure);
		if (structure.is_here_doc)
			here_doc_structure(&structure);
		ft_pipes(&structure);
		i = 0;
		while (structure.fds_pipes[i])
		{
			free(structure.fds_pipes[i]);
			i++;
		}
		free(structure.fds_pipes);
	}
	else
	{
		errno = EINVAL;
		perror("Not enough arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}