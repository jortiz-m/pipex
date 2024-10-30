/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:08:14 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/25 14:08:24 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*create_pipe(void)
{
	int	*pipe_fd;

	pipe_fd = malloc(2 * sizeof(int));
	if (pipe(pipe_fd) == -1)
	{
		perror("Error creating a pipe");
		exit(EXIT_FAILURE);
	}
	return (pipe_fd);
}
