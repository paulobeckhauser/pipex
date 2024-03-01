/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_variables.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:25:54 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:26:07 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	store_variables(t_info *structure)
{
	get_number_commands(structure);
	store_command_full_string(structure);
	allocate_memory_commands(structure);
	store_commands(structure);
	get_path_env(structure);
	store_path_commands(structure);
}
