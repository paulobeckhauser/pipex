/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_commands_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:14:33 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/02 02:28:39 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	condition_dup(t_info *structure, int i, int j)
{
	if (structure->possible_paths[j] != NULL)
		structure->path_commands[i] = ft_strdup(structure->possible_paths[j]);
	else
		structure->path_commands[i] = ft_strdup(structure->possible_paths[--j]);
}
