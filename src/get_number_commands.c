/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number_commands.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:07:13 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:07:22 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_number_commands(t_info *structure)
{
	if (structure->is_here_doc == 1)
		structure->number_commands = structure->argc - 4;
	else
		structure->number_commands = structure->argc - 3;
}
