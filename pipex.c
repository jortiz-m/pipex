/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:55:14 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/10 10:09:13 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av)
{
	t_pipe	pipe;
	pid_t	child;

	ac--;
	av++;
	validate_arguments(ac, av);
	pipe = create_pipe();
	child = fork();
	child_process(av, pipe, av[1], child);
	parent_process(av, pipe, av[2]);
	exit(EXIT_SUCCESS);
}
