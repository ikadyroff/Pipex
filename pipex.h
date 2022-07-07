/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:04:39 by wlouveni          #+#    #+#             */
/*   Updated: 2022/01/31 17:06:30 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "./libft/libft.h"

char	*find_path(char *envp[], char *cmd);
void	open_files(int fd_file[2], char **argv);
void	cmd1_exec(int fd_file_1, int pipe_fd[2], char **envp, char *cmd1);
void	cmd2_exec(int fd_file_2, int pipe_fd[2], char **envp, char *cmd2);
void	cmd_error(char *cmd);

#endif