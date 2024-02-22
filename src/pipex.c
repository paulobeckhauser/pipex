/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/22 18:26:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{

	// char *path_command1;
	// char *path_command2;
	// char **array_first_command;
	// char **array_second_command;

	// t_info structure;
	
	// structure.first_command = ft_split(argv[2], ' ');
	// structure.second_command = ft_split(argv[3], ' ');
	// structure.envp_values = envp;

	
	


	

	// structure = get_path_env(structure);


	// structure = command_get_first_path(structure, structure.first_command[0]);
	// structure = command_get_second_path(structure, structure.second_command[0]);


	char *path_command1;
	char *path_command2;
	char **array_first_command;
	char **array_second_command;

	t_info structure;

	int i = 2;
	int j = 0;


	structure.commands_full_string = (char **)malloc( ((argc - 3) + 1) * sizeof(char *));


	size_t len_string; 





	int g = 2;
	int l = 0;

	while (g <= argc - 2)
	{

		len_string = ft_strlen(argv[g]);
		structure.commands_full_string[l] = (char *)malloc((len_string + 1) * sizeof(char));
		ft_strlcpy(structure.commands_full_string[l], argv[g], len_string + 1);
		g++;
		l++;
		
	}
	structure.commands_full_string[l] = NULL;
	
	int n = 0;
	int m = 0;
	structure.commands = (char **)ft_calloc((l + 1), sizeof(char *));

	while (structure.commands_full_string[n])
	{
		m = 0;
		while (structure.commands_full_string[n][m] && structure.commands_full_string[n][m] != ' ')
			m++;
		structure.commands[n] = (char *)ft_calloc((m + 1), sizeof(char));

		n++;
		
	}


	int p = 0;
	int r = 0;
	while (structure.commands_full_string[p])
	{
		r = 0;
		while (structure.commands_full_string[p][r] && structure.commands_full_string[p][r] != ' ')
		{
			structure.commands[p][r] = structure.commands_full_string[p][r];
			r++;
		}
		
		p++;
	}
	structure.commands[p] = NULL;



	structure.envp_values = envp;



	

	structure = get_path_env(structure);



	int k = 0;
	while(structure.commands[k])
	{
		
		k++;
	}



	structure.path_commands = (char **)malloc((k + 1) * sizeof(char *));

	
	i = 0;
	while (structure.commands[i])
	{

		structure.possible_paths = split_concat_command(structure.path_env, ':', structure.commands[i]);
		j = 0;
		while (structure.possible_paths[j])
		{

			if (access(structure.possible_paths[j], X_OK) == 0)
				break;
			j++;
		}



		
		structure.path_commands[i] = (char *)ft_calloc( ft_strlen(structure.possible_paths[j]) + 1, sizeof(char));

		
		structure.path_commands[i] = ft_strdup(structure.possible_paths[j]);
		
		i++;
	}
	structure.path_commands[i] = NULL;


	













	int fd[2];

	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 < 0)
		return (2);

	if (pid1 == 0)
	{
		int infile_fd = open(argv[1], O_RDONLY, 0777);

		if (infile_fd < 0)
			return (4);

		dup2(infile_fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(infile_fd);
		structure.argv_commands = ft_split(structure.commands_full_string[0], ' ');
		execve(structure.path_commands[0], structure.argv_commands, envp);
		if (errno != 0)
		{
			perror("execve failed");
			exit(1);
		}
		
		
	}









	

	



	

	int pid2 = fork();
	if (pid2 < 0)
		return (3);
	if (pid2 == 0)
	{
		int output_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (output_fd < 0)
			return (5);
		dup2(output_fd, STDOUT_FILENO);
		// ft_printf("......................test!/\n");
		dup2(fd[0], STDIN_FILENO);

		close(fd[0]);
		close(fd[1]);
		close(output_fd);
		structure.argv_commands = ft_split(structure.commands_full_string[1], ' ');
		execve(structure.path_commands[1], structure.argv_commands, envp);

		
	
		
		if (errno != 0)
		{
			perror("execve failed");
			exit(1);
		}
	}










	
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);


	
	// }
	return (0);
}