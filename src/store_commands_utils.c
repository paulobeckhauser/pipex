/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:14:33 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 23:32:48 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	condition_dup(t_info *structure, int i, int j)
{
	if (structure->possible_paths[j] != NULL)
		structure->path_commands[i] = ft_strdup(structure->possible_paths[j]);
	else
	{
		structure->path_commands[i] = ft_strdup(structure->possible_paths[--j]);
		// ft_printf("%s: command not found\n", structure->commands[i]);
		
	}
}

// void	get_path_command(t_info *structure, int i, int j)
// {
// 	if (structure->possible_paths == NULL)
// 	{
// 		free(structure->path_env);
// 		free(structure->commands[i]);
// 	}
// 	else
// 	{
// 		j = 0;
// 		while (structure->possible_paths[j])
// 		{
// 			if (access(structure->possible_paths[j], X_OK) == 0)
// 				break ;
// 			j++;
// 		}
// 		condition_dup(structure, i, j);
// 	}
// }

void	fail_paths(t_info *structure, int i)
{
	if (structure->path_commands[i] == NULL)
		ft_printf("%s: command not found!!!\n", structure->commands[i]);
}
