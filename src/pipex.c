/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 14:07:15 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{
	int		i;
	t_info	structure;

	if (argc == 5)
	{
		store_arguments(argc, argv, envp, &structure);
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
		perror("Not correct number of arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
