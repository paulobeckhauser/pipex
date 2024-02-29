/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:04:04 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/29 11:35:51 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	check_here_doc(t_info *structure)
{
	int	here_doc_bool;

	if (ft_strlen(structure->argv[1]) > ft_strlen("here_doc"))
		here_doc_bool = ft_strncmp(structure->argv[1], "here_doc",
				ft_strlen(structure->argv[1]));
	else
		here_doc_bool = ft_strncmp(structure->argv[1], "here_doc",
				ft_strlen("here_doc"));
	if (here_doc_bool == 0)
		structure->is_here_doc = 1;
	else
		structure->is_here_doc = 0;
}

static int	lenght_test_value(t_info *structure, char *input)
{
	int	lenght_test;

	if (ft_strlen(structure->argv[2]) > (ft_strlen(input) - 1))
		lenght_test = ft_strncmp(structure->argv[2], input,
				ft_strlen(structure->argv[2]));
	else
		lenght_test = ft_strncmp(input, structure->argv[2], ft_strlen(input)
				- 1);
	return (lenght_test);
}

void	here_doc_structure(t_info *structure)
{
	char	*input;
	int		lenght_test;
	int		i;

	ft_printf("heredoc> ");
	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		lenght_test = lenght_test_value(structure, input);
		if (lenght_test == 0)
			break ;
		ft_printf("heredoc> ");
		structure->here_doc_file = open("here_doc",
				O_WRONLY | O_CREAT | O_APPEND, 0777);
		i = 0;
		while (input[i])
		{
			write(structure->here_doc_file, &input[i], 1);
			i++;
		}
		free(input);
		close(structure->here_doc_file);
	}
	free(input);
}
