/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlouveni < wlouveni@student.21-school.r    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:04:51 by wlouveni          #+#    #+#             */
/*   Updated: 2022/01/31 17:05:06 by wlouveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pipex.h"
#include "./libft/libft.h"

void	cmd_error(char *cmd)
{
	write(2, "Error! Command: ", 16);
	ft_putstr_fd(cmd, 2);
	write(2, " not found.\n", 12);
	exit(1);
}

char	*find_path(char *envp[], char *cmd)
{
	char	*path;
	char	**paths;
	char	*desired_path;
	char	**cmds;
	int		i;

	i = 0;
	cmds = ft_split(cmd, ' ');
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		desired_path = ft_strjoin(path, cmds[0]);
		free(path);
		if (access(desired_path, F_OK) == 0)
			return (desired_path);
		i++;
	}
	if (!paths[i])
		cmd_error(cmd);
	return (0);
}

void	open_files(int fd_file[2], char **argv)
{
	fd_file[0] = open(argv[1], O_RDONLY);
	if (fd_file[0] == -1)
	{
		write(2, "Error! Occurred with opening infile.\n", 37);
		exit(1);
	}
	fd_file[1] = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_file[1] == -1)
	{
		write(2, "Error! Occurred with opening or creating outfile.\n", 50);
		exit(1);
	}
}
