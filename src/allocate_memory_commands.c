/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:13:26 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:15:55 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	allocate_memory_commands(t_info *structure)
{
	int	i;
	int	j;

	i = 0;
	structure->commands = (char **)ft_calloc((structure->argc - 2),
			sizeof(char *));
	if (!structure->commands)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	while (structure->full_string[i])
	{
		j = 0;
		while (structure->full_string[i][j]
			&& structure->full_string[i][j] != ' ')
			j++;
		structure->commands[i] = (char *)ft_calloc((j + 1), sizeof(char));
		i++;
	}
}
