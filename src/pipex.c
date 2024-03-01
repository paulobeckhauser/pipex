/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:58:02 by pabeckha         ###   ########.fr       */
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
		ft_pipes(&structure);
	}
	else
	{
		errno = EINVAL;
		perror("Not correct number of arguments");
		exit(EXIT_FAILURE);
	}
	return (0);
}
