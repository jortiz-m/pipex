/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:07:13 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/10 12:33:53 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, t_pipe pipe, char *cmd, pid_t child)
{
	int	fd;

	if (child == -1)
	{
		perror("fork: error at child process");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		fd = open_file(av[0], READ);
		dup2(pipe.write_pipe, STDOUT_FILENO);
		dup2(fd, STDIN_FILENO);
		close(pipe.read_pipe);
		close(pipe.write_pipe);
		exec_cmd(cmd);
	}
}

void	parent_process(char **av, t_pipe pipe, char *cmd)
{
	int	fd;

	fd = open_file(av[3], WRITE);
	dup2(pipe.read_pipe, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(pipe.write_pipe);
	close(pipe.read_pipe);
	exec_cmd(cmd);
}
