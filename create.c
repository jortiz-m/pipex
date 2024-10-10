/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:14 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/10 10:11:46 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_pipe	create_pipe(void)
{
	t_pipe	pipe_struct;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
	{
		perror("Error creating a pipe");
		exit(EXIT_FAILURE);
	}
	pipe_struct.read_pipe = pipe_fd[0];
	pipe_struct.write_pipe = pipe_fd[1];
	return (pipe_struct);
}
