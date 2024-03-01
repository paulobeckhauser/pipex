/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_main_arguments.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:39:05 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 20:57:02 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	store_main_arguments(int argc, char **argv, char **envp,
		t_info *structure)
{
	structure->argc = argc;
	structure->argv = argv;
	structure->envp = envp;
}
