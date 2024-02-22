/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/22 17:20:49 by pabeckha         ###   ########.fr       */
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
#include <errno.h>

typedef struct s_info
{

    char **commands_full_string; //where I am saving the strings of the commands
    char **commands; //array storing only the commands
    


    char **envp_values;
    char *path_env;


    char **possible_paths; // POSSIBLE PATHS THAT WILL BE STORED AND THEN DELETED

    char **path_commands; // FINAL PATHS OF THE COMMANDS

    char **argv_commands; 


    char **first_command;
    char **second_command;
    
    // char **envp_values;
    
    // char *path_env;
    
    // char **possible_paths; 

    
    // char *path_first_command;
    // char *path_second_command;

    // char **path_commands;

    
}   t_info;

// Functions
t_info get_path_env(t_info structure);
// t_info command_get_path(t_info structure, char *command);
t_info command_get_first_path(t_info structure, char *command);
t_info command_get_second_path(t_info structure, char *command);

char	**split_concat_command(char const *s, char c, char *command);

#endif