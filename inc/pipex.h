/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 15:01:47 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// Made libraries
# include "../libs/libft/inc/ft_printf.h"
# include "../libs/libft/inc/get_next_line.h"
# include "../libs/libft/inc/libft.h"

// Other libraries
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_info
{
	int 	argc;
	char 	**argv;
	char 	**envp;
	
	char	**commands_full_string;
	char	**commands;

	
	char	*path_env;

	
	char	**possible_paths;
	char	**path_commands;
	char	**argv_commands;

	int input_fd;
	int output_fd;

	int **fds_pipes;
	pid_t *pid;
	int is_here_doc;

	int number_commands;

	

}			t_info;

void	store_arguments(int argc, char **argv, char **envp, t_info *structure);
// void	commands_full_string_store(t_info *structure);
void	commands_full_string_store(t_info *structure, int first_command_position);
void commands_allocate_memory(t_info *structure);
void commands_store(t_info *structure);
void path_commands_store(t_info *structure);
// t_info		get_path_env(t_info structure);
void	get_path_env(t_info *structure);
char		**split_concat_command(char const *s, char c, char *command);
void pipes_creation(t_info *structure);
void pipes_utilization(t_info *structure);
void close_pipes(t_info *structure);
void wait_child_processess(t_info *structure);
void check_here_doc(t_info *structure);
void number_commands(t_info *structure);



void free_commands_full_string(t_info *structure);
void free_commands(t_info *structure);
void free_possible_paths(t_info *structure);
void free_path_commands(t_info *structure);
void    free_fds_pipes(t_info *structure);
void free_variables(t_info *structure);


#endif