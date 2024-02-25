/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:26:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 01:15:57 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void number_commands(t_info *structure)
{

    
    if (structure->is_here_doc)
    {
        structure->number_commands = structure->argc - 4;
    }
    else
        structure->number_commands = structure->argc - 3;



    
    
}

