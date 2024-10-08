/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:07:13 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/08 12:07:16 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(int fd, t_pipe pipe, char *cmd)
{
	dup2(fd, STDIN_FILENO);
	close(pipe.read_pipe);
	if (dup2(pipe.write_pipe, STDOUT_FILENO) == -1)
	{
		perror("child dup2: Error duplicating file descriptors");
		exit(EXIT_FAILURE);
	}
	exec_cmd_to_file(cmd);
}

void	ft_parent(int fd, t_pipe pipe, char *cmd)
{
	dup2(fd, STDOUT_FILENO);
	close(pipe.write_pipe);
	if (dup2(pipe.read_pipe, STDIN_FILENO) == -1)
	{
		perror("parent dup2: Error duplicating file descriptors");
		exit(EXIT_FAILURE);
	}
	exec_cmd_to_file(cmd);
}