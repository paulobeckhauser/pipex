/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:04:04 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/24 16:07:54 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void check_here_doc(t_info *structure)
{
    int here_doc_bool;
    
	if (ft_strlen(structure->argv[1]) > ft_strlen("here_doc"))
		here_doc_bool = ft_strncmp(structure->argv[1], "here_doc", ft_strlen(structure->argv[1]));
	else
		here_doc_bool = ft_strncmp(structure->argv[1], "here_doc", ft_strlen("here_doc"));

    if(here_doc_bool == 0)
        structure->is_here_doc = 1;
    else
        structure->is_here_doc = 0;
}