/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:14 by pabeckha          #+#    #+#             */
/*   Updated: 2024/02/14 19:04:53 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

int main(int argc, char **argv, char **envp)
{
    char *path_command1;
    char *path_command2;
    char **array_first_command;
    char **array_second_command;

    array_first_command = ft_split(argv[2], ' ');
    array_second_command = ft_split(argv[3], ' ');

    path_command1 = path_commands(path_command1, envp, array_first_command[0]);
    path_command2 = path_commands(path_command1, envp, array_second_command[0]);
    

    int fd[2];

    if (pipe(fd) == -1)
        return (1);

    int pid1 = fork();
    if (pid1 < 0)
        return (2);
    
    if (pid1 == 0)
    {
        int input_fd = open(argv[1], O_RDONLY);
        
        if (input_fd < 0)
            return (4);
        
        dup2(input_fd, STDIN_FILENO);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(input_fd);
        execve(path_command1, array_first_command, envp);
        // check for execve
        // probablyn exit(1)
    }

    int pid2 = fork();
    if(pid2 < 0 )
        return (3);
    if (pid2 == 0)
    {
        int output_fd = open(argv[4], O_WRONLY | O_CREAT, 0777);
        if (output_fd < 0)
            return (5);
    
        dup2(fd[0], STDIN_FILENO);
        dup2(output_fd, STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        close(output_fd);
        execve(path_command2, array_second_command, envp);
        
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}