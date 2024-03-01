/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_command_full_string.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:10:51 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:11:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	store_command_full_string(t_info *structure)
{
	int	first_command_position;

	if (structure->is_here_doc == 1)
		first_command_position = 3;
	else
		first_command_position = 2;
	structure->full_string = (char **)malloc(((structure->argc - 3) + 1)
			* sizeof(char *));
	if (!structure->full_string)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	copy_string(structure, first_command_position);
}
