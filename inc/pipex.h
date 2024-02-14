/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/14 15:25:43 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

// Made libraries
# include "../libs/libft/inc/libft.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/ft_printf.h"

// Other libraries
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>

// Functions
char *path_commands(char *path_var, char **envp, char *command);

char	**ft_split_concat(char const *s, char c, char *command);

#endif