/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory_path_commands.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 22:18:02 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 22:18:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	allocate_memory_path_commands(t_info *structure)
{
	int	i;

	i = 0;
	while (structure->commands[i])
		i++;
	structure->path_commands = (char **)malloc((i + 1) * sizeof(char *));
	if (!structure->path_commands)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
}