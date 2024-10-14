/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:55:14 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/14 11:30:15 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		*pipe;
	pid_t	child;

	argc--;
	argv++;
	validate_arguments(argc, argv);
	pipe = create_pipe();
	child = fork();
	child_process(argv, pipe, argv[1], child);
	parent_process(argv, pipe, argv[2]);
	exit(EXIT_SUCCESS);
}
