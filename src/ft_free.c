/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:17:49 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:24:57 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_2d_array_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_2d_array_int(int **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_variables(t_info *structure)
{
	if (structure->full_string)
		free_2d_array_char(structure->full_string);
	if (structure->commands)
		free_2d_array_char(structure->commands);
	if (structure->path_env)
		free(structure->path_env);
	if (structure->path_commands)
		free_2d_array_char(structure->path_commands);
	if (structure->pid)
		free(structure->pid);
	if (structure->fds_pipes)
		free_2d_array_int(structure->fds_pipes);
}
