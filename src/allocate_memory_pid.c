/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate_memory_pid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 21:44:20 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/01 21:44:58 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	allocate_memory_pid(t_info *structure)
{
	structure->pid = (pid_t *)ft_calloc((structure->number_commands + 1),
			sizeof(pid_t));
}
