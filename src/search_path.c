/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:37 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/22 17:24:46 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

t_info get_path_env(t_info structure)
{
	int		i;
	int		len_path;
	
	i = 0;
	len_path = 0;
	while (structure.envp_values[i])
	{
		if (ft_strncmp(structure.envp_values[i], "PATH=", 5) == 0)
		{
			len_path = ft_strlen(structure.envp_values[i]);
			break ;
		}
		i++;
	}
	structure.path_env = (char *)malloc((len_path - ft_strlen("PATH=") + 1 ) * sizeof(char));
	// IMPLEMENT PROTECTION
	
	structure.path_env = ft_strdup(structure.envp_values[i] + 5);
	return(structure);
}

// t_info command_get_first_path(t_info structure, char *command)
// {
// 	int i;
// 	int j;
	
// 	structure.possible_paths = split_concat_command(structure.path_env, ':', command);

// 	// ft_printf("%s\n", structure.possible_paths);

// 	i = 0;
// 	j = 0;
// 	while (structure.possible_paths[i])
// 	{
// 		if (access(structure.possible_paths[i], F_OK) == 0)
// 		{
// 			j++;
// 			if (access(structure.possible_paths[i], X_OK) == 0)
// 			break;
// 		}
// 		i++;
// 	// 	if (access(structure.possible_paths[i], X_OK) == 0)
// 	// 		break;
// 	// 	i++;
// 	}
// 	if (j == 0)
// 	{
// 		perror("Error");
// 		// return(NULL);
		
// 	}
// 	else if (access(structure.possible_paths[i], X_OK) != 0)
// 	// else if (access("/usr/bin/sudo", X_OK) != 0)
// 	{
// 		perror(".Error");
// 		// return (NULL);
		
// 	}
// 	else
// 	// ft_printf("%s\n", structure.possible_paths[i]);
	

// 	// ft_printf("/usr/bin/sudo");
// 	// int test;
// 	// test = access("/usr/bin/jlkdshsdj", F_OK);
// 	// test = access("/usr/bin/ksdjsd", X_OK);
	

// 	// printf("%d\n", test);
	

// 		structure.path_first_command = ft_strdup(structure.possible_paths[i]);
// 	return(structure);

// }

// t_info command_get_second_path(t_info structure, char *command)
// {
// 	int i;
	
// 	structure.possible_paths = split_concat_command(structure.path_env, ':', command);

// 	i = 0;
// 	while (structure.possible_paths[i])
// 	{
// 		if (access(structure.possible_paths[i], X_OK) == 0)
// 			break;
// 		i++;
// 	}

// 	structure.path_second_command = ft_strdup(structure.possible_paths[i]);
// 	return(structure);

// }
