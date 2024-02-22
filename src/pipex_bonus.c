/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/22 17:14:32 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	main(int argc, char **argv, char **envp)

{

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




	int infile_fd;
	int outfile_fd;

	int fds[argc - 4][2];
	
	pid_t pid[argc - 3];

	// CREATION OF PIPES
	i = 0;
	while (i < argc - 4)
	{
		pipe(fds[i]);

		i++;
	}


	
	// EXECUTE COMMANDS
	i = 0;
	while (i < argc - 3)
	{
		pid[i] = fork();
		// ft_printf("Fork number: %d\n", i+1);


		if(pid[i] == 0) // Child process
		{
			if (i == 0)
			{
				infile_fd = open(argv[1], O_RDONLY, 0777);
				dup2(infile_fd, STDIN_FILENO);
				close(infile_fd);
			}
			else
			{
				dup2(fds[i - 1][0], STDIN_FILENO);
			}
			if (i == argc - 4)
			{
				outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
				dup2(outfile_fd, STDOUT_FILENO);
				close(outfile_fd);
			}
			else
			{
				dup2(fds[i][1], STDOUT_FILENO);
			}


			// CLOSE PIPE FDS
			j = 0;
			while (j < argc - 4)
			{
				close(fds[j][0]);
				close(fds[j][1]);
				j++;
			}

			structure.argv_commands = ft_split(structure.commands_full_string[i], ' ');
			execve(structure.path_commands[i], structure.argv_commands, envp);


		}

		
		i++;

	}

	i = 0;
	while(i < argc - 4)
	{
		close(fds[i][0]);
		close(fds[i][1]);
		i++;
	}

	
	i = 0;
	while (i < argc - 3)
	{
		waitpid(pid[i], NULL, 0);
		i++;
	}

	

	
	return (0);
}