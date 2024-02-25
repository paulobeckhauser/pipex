/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/25 16:19:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"


int	main(int argc, char **argv, char **envp)

{
	t_info structure;

	// structure.argc = argc;
	// structure.argv = argv;
	// structure.envp = envp;
	store_arguments(argc, argv, envp, &structure);



	check_here_doc(&structure);

	if (structure.is_here_doc)
	{
		number_commands(&structure);

		char *input;
		int lenght_test;
		int second_fd;

		ft_printf("heredoc> ");
		while (1)
		{
			input = get_next_line(STDIN_FILENO);

			if (ft_strlen(argv[2]) > (ft_strlen(input) - 1))
				lenght_test = ft_strncmp(argv[2], input, ft_strlen(argv[2]));
			else
				lenght_test = ft_strncmp(input, argv[2], ft_strlen(input) - 1);

			if (lenght_test == 0)
				break ;

			ft_printf("heredoc> ");

			second_fd = open("here_doc", O_WRONLY | O_CREAT | O_APPEND, 0777);
			int m = 0;

			while (input[m])
			{
				write(second_fd, &input[m], 1);
				m++;
			}
			free(input);
			close(second_fd);
		}
		// close(second_fd);
		free(input);

		commands_full_string_store(&structure, 3);
		commands_allocate_memory(&structure);
		commands_store(&structure);
		get_path_env(&structure);


		path_commands_store(&structure);

		structure.input_fd = open(argv[1], O_RDONLY, 0777);
		// if (structure.input_fd == -1)
		// {
		// 	perror("open");
		// 	exit(EXIT_FAILURE);
		// }

		structure.output_fd = open(structure.argv[structure.argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		// if (structure.output_fd == -1)
		// {
		// 	perror("open");
		// 	exit(EXIT_FAILURE);
		// }
		pipes_creation(&structure);
		structure.pid = (pid_t *)ft_calloc((structure.number_commands + 1),
				sizeof(pid_t));
		if(!structure.pid)
		{
			perror("Memory allocation failed!\n");
			exit(EXIT_FAILURE);
		}

		pipes_utilization(&structure);
		close_pipes(&structure);
		wait_child_processess(&structure);


		free_commands_full_string(&structure);
		free_commands(&structure);

		
		free(structure.path_env);

		free_path_commands(&structure);
		free_fds_pipes(&structure);
		free(structure.pid);



	// 	// int i;

	// 	// i = 0;
	// 	// while(structure.argv_commands[i])
	// 	// {
	// 	// 	free(structure.argv_commands[i]);
	// 	// 	i++;

	// 	// }
	// 	// free(structure.argv_commands);

	// 	// close(structure.input_fd);

		

		
		
		
		
	}
	// else
	// {
	// 	number_commands(&structure);
	// 	commands_full_string_store(&structure, 2);
	// 	commands_allocate_memory(&structure);
	// 	commands_store(&structure);
	// 	structure = get_path_env(structure);
	// 	path_commands_store(&structure);
	// 	structure.input_fd = open(argv[1], O_RDONLY, 0777);
	// 	structure.output_fd = open(structure.argv[structure.argc - 1],
	// 			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	// 	pipes_creation(&structure);
	// 	structure.pid = (pid_t *)ft_calloc((structure.number_commands + 1),
	// 			sizeof(pid_t));

	// 	pipes_utilization(&structure);
	// 	close_pipes(&structure);
	// 	wait_child_processess(&structure);
	// }
	return (0);
}