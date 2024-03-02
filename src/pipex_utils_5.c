/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:40:19 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 00:17:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	stop_error_commands(t_info *structure, int i)
{
	int	j;

	j = 0;
	if (execve(structure->path_commands[i], structure->argv_commands,
			structure->envp) == -1)
		free_2d_array_char(structure->argv_commands);
	free_variables(structure);
	exit(1);
}
