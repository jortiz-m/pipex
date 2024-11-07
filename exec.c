/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:05:57 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/11/06 11:18:35 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char *cmd_arg)
{
	char	**splitted_paths;
	char	**cmd_paths;
	char	*cmd_dir;
	char	**matrix_for_exec;

	splitted_paths = split_paths(LINUX_PATH);
	matrix_for_exec = ft_split(cmd_arg, ' ');
	cmd_paths = concat_paths(splitted_paths, matrix_for_exec[0]);
	cmd_dir = get_path(cmd_paths, matrix_for_exec[0]);
	if (execve(cmd_dir, matrix_for_exec, NULL) == -1)
	{
		free(cmd_dir);
		free_matrix(cmd_paths);
		free_matrix(splitted_paths);
		free_matrix(matrix_for_exec);
		perror("execve: error executing commands");
		exit(EXIT_FAILURE);
	}
}
