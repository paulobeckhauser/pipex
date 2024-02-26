/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:20:16 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/26 10:35:31 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	commands_full_string_store(t_info *structure)
{
	int		j;
	size_t	len_string;
	int first_command_position;

	if (structure->is_here_doc)
		first_command_position = 3;
	else 
		first_command_position = 2;
	structure->commands_full_string = (char **)malloc(((structure->argc - 3)
				+ 1) * sizeof(char *));
	if (!structure->commands_full_string)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (first_command_position <= structure->argc - 2)
	{
		len_string = ft_strlen(structure->argv[first_command_position]);
		structure->commands_full_string[j] = (char *)malloc((len_string + 1)
				* sizeof(char));
		ft_strlcpy(structure->commands_full_string[j],
			structure->argv[first_command_position], len_string + 1);
		first_command_position++;
		j++;
	}
	structure->commands_full_string[j] = NULL;
}

void	commands_allocate_memory(t_info *structure)
{
	int	i;
	int	j;

	i = 0;
	structure->commands = (char **)ft_calloc((structure->argc - 2),
			sizeof(char *));
	if (!structure->commands)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	while (structure->commands_full_string[i])
	{
		j = 0;
		while (structure->commands_full_string[i][j]
			&& structure->commands_full_string[i][j] != ' ')
			j++;
		structure->commands[i] = (char *)ft_calloc((j + 1), sizeof(char));
		i++;
	}
}

void	commands_store(t_info *structure)
{
	int	i;
	int	j;

	i = 0;
	while (structure->commands_full_string[i])
	{
		j = 0;
		while (structure->commands_full_string[i][j]
			&& structure->commands_full_string[i][j] != ' ')
		{
			structure->commands[i][j] = structure->commands_full_string[i][j];
			j++;
		}
		i++;
	}
	structure->commands[i] = NULL;
}

void	path_commands_store(t_info *structure)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (structure->commands[i])
	{
		i++;
	}
	structure->path_commands = (char **)malloc((i + 1) * sizeof(char *));
	if (!structure->path_commands)
	{
		perror("Memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (structure->commands[i])
	{
		structure->possible_paths = split_concat_command(structure->path_env,
				':', structure->commands[i]);
		if (structure->possible_paths == NULL)
		{
			free(structure->path_env);
			free(structure->commands[i]);
		}
		else
		{
			j = 0;
			while (structure->possible_paths[j])
			{
				if (access(structure->possible_paths[j], X_OK) == 0)
					break ;
				j++;
			}
			if (structure->possible_paths[j] != NULL)
				structure->path_commands[i] = ft_strdup(structure->possible_paths[j]);
			else
				structure->path_commands[i] = NULL;
		}
		k = 0;
		while (structure->possible_paths[k] != NULL)
		{
			free(structure->possible_paths[k]);
			k++;
		}
		free(structure->possible_paths);
		i++;
	}
	structure->path_commands[i] = NULL;
}
