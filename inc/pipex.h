/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:58:36 by pabeckha          #+#    #+#             */
/*   Updated: 2024/03/04 11:07:28 by pabeckha         ###   ########.fr       */
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
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAX_FD 1024

typedef struct s_info
{
	int		argc;
	char	**argv;
	char	**envp;
	int		is_here_doc;
	int		number_commands;
	char	**full_string;
	char	**commands;
	char	*path_env;
	char	**possible_paths;
	char	**path_commands;
	char	**argv_commands;
	int		input_fd;
	int		output_fd;
	int		here_doc_file;
	int		**fds_pipes;
	pid_t	*pid;

}			t_info;

void		store_main_arguments(int argc, char **argv, char **envp,
				t_info *structure);
void		store_command_full_string(t_info *structure);
void		commands_allocate_memory(t_info *structure);
void		allocate_memory_path_commands(t_info *structure);
void		allocate_memory_pid(t_info *structure);
void		store_commands(t_info *structure);
void		store_path_commands(t_info *structure);
void		get_path_env(t_info *structure);
void		allocate_memory_commands(t_info *structure);
void		get_path_command(t_info *structure, int i, int j);
void		copy_string(t_info *structure, int first_command_position);
void		*ft_free(char **strs, int count);
char		**check_and_free(char **array, int j);
void		condition_dup(t_info *structure, int i, int j);
char		**split_concat_command(char const *s, char c, char *command);
void		conditions_child(t_info *structure, int i);
void		execute_commands(t_info *structure, int i);
void		create_pipes(t_info *structure);
void		create_child_processes(t_info *structure);
void		stop_error_commands(t_info *structure, int i);
void		close_pipes_parent(t_info *structure);
void		wait_child_processess(t_info *structure);
void		check_here_doc(t_info *structure);
void		here_doc_structure(t_info *structure);
void		get_number_commands(t_info *structure);
void		store_variables(t_info *structure);
void		pipes_structure(t_info *structure);
void		pipes_definition(t_info *structure);
void		close_pipes_child(t_info *structure, int j);
void		free_2d_array_char(char **array);
void		free_fds_pipes(t_info *structure);
void		free_variables(t_info *structure);
void		free_2d_array_int(int **array);
void		open_input_output_fds(t_info *structure);

void		redirect_fds_child(t_info *structure, int i);
void		execute_pipex_structure(t_info *structure);

void		condition_to_remove_single(t_info *structure, char *string_temp,
				int count, int k);
void		condition_to_remove_double(t_info *structure, char *string_temp,
				int count, int k);

void		handle_single_quotes(t_info *structure);
void		handle_double_quotes(t_info *structure);
void		close_fds_parent(void);

#endif