/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:04:47 by wlouveni          #+#    #+#             */
/*   Updated: 2022/01/31 17:04:14 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include "pipex.h"
#include "./libft/libft.h"

void	cmd1_exec(int fd_file_1, int pipe_fd[2], char **envp, char *cmd1)
{
	int	pipe_fd_0;
	int	pipe_fd_1;

	pipe_fd_0 = pipe_fd[0];
	pipe_fd_1 = pipe_fd[1];
	close(pipe_fd_0);
	dup2(fd_file_1, STDIN_FILENO);
	dup2(pipe_fd_1, STDOUT_FILENO);
	execve(find_path(envp, cmd1), ft_split(cmd1, ' '), envp);
	close(pipe_fd_1);
}

void	cmd2_exec(int fd_file_2, int pipe_fd[2], char **envp, char *cmd2)
{
	int	pipe_fd_0;
	int	pipe_fd_1;

	pipe_fd_0 = pipe_fd[0];
	pipe_fd_1 = pipe_fd[1];
	close(pipe_fd_1);
	dup2(pipe_fd_0, STDIN_FILENO);
	dup2(fd_file_2, STDOUT_FILENO);
	execve(find_path(envp, cmd2), ft_split(cmd2, ' '), envp);
	close(pipe_fd[0]);
	wait(0);
}

void	error_handling(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> file2\n", 1);
		exit(1);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_file[2];
	pid_t	pid;
	int		pipe_fd[2];

	if (argc == 5)
	{
		open_files(fd_file, argv);
		if (pipe(pipe_fd) == -1)
			return (4);
		pid = fork();
		if (pid == -1)
			return (3);
		if (pid == 0)
			cmd1_exec(fd_file[0], pipe_fd, envp, argv[2]);
		else
			cmd2_exec(fd_file[1], pipe_fd, envp, argv[3]);
	}
	error_handling(argc);
	return (0);
}
