/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:07:13 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/14 14:17:44 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **argv, int *pipe, char *cmd, pid_t child)
{

	int	fd;

	if (child == -1)
	{
		perror("fork: error at child process");
		exit(EXIT_FAILURE);
	}
	else if (child == 0)
	{
		fd = open_file(argv[0], 0);
		dup2(fd, STDIN_FILENO);
		close(fd);
		dup2(pipe[1], STDOUT_FILENO);
		close(pipe[0]);
		close(pipe[1]);
		exec_cmd(cmd);
	}
}

void	parent_process(char **argv, int *pipe, char *cmd)
{
	int	fd;

	fd = open_file(argv[3], 1);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	close(pipe[1]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	exec_cmd(cmd);
}
