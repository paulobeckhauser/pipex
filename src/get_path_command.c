/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:28:12 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 00:11:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_path_command(t_info *structure, int i, int j)
{
	if (structure->possible_paths == NULL)
	{
		free(structure->path_env);
		free(structure->commands[i]);
	}
	else
	{
		j = 0;
		while (structure->possible_paths[j])
		{
			if (access(structure->possible_paths[j], X_OK) == 0)
				break ;
			j++;
		}
		condition_dup(structure, i, j);
	}
}
