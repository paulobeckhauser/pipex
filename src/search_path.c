/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:37 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 22:34:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	get_path_env(t_info *structure)
{
	int	i;
	int	len_path;

	i = 0;
	len_path = 0;
	while (structure->envp[i])
	{
		if (ft_strncmp(structure->envp[i], "PATH=", 5) == 0)
		{
			len_path = ft_strlen(structure->envp[i]);
			break ;
		}
		i++;
	}
	structure->path_env = ft_strdup(structure->envp[i] + 5);
}
