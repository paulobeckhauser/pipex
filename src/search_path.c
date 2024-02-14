/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:56:37 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/14 17:49:31 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"


char *path_commands(char *path_var, char **envp, char *command)
{
    int i;
    int len_path;
    char *str_path;
    

    i = 0;
    len_path = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            len_path = ft_strlen(envp[i]);
            break;
        }
        i++;
    }
    
    // REPLACE THE HARD CODED NUMBERS
    // 1 = NULL TERMINATOR
    //5 IS THE LENGHT OF "PATH="
    path_var = (char *)malloc((len_path + 1 - 5) * sizeof(char));
    if (!path_var)
        return (NULL);

    path_var = ft_strdup(envp[i] + 5);

    

    char **array;

    array = ft_split_concat(path_var, ':', command);




    int l = 0;

    int ret_acc;
    
    while (array[l])
    {
        
        // ft_printf("%s\n", array[l]);
        ret_acc = access(array[l], X_OK);
        if (access(array[l], X_OK) == 0)
        {
            // ft_printf("%s\n", array[l]);
            // ft_printf("This is the correct folder\n");
            break ;
        }
        l++;
    }

    // ft_printf("%s\n", array[l]);

    
    char *correct_path;

    correct_path = ft_strdup(array[l]);



    
    

    
    

    
    return (correct_path);
    

}

