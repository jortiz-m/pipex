/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:02:57 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/25 14:20:35 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	cmd_validation(char *cmd1, char *cmd2)
{
	char	**splitted_paths;
	char	**cmd1_path;
	char	**cmd2_path;
	char	**cmd;
	bool	res;

	res = false;
	splitted_paths = split_paths(LINUX_PATH);
	cmd = ft_split(cmd1, ' ');
	cmd1_path = concat_paths(splitted_paths, cmd[0]);
	free_matrix(cmd);
	cmd = ft_split(cmd2, ' ');
	cmd2_path = concat_paths(splitted_paths, cmd[0]);
	if (path_validation(cmd1_path, cmd1))
	{
		if (path_validation(cmd2_path, cmd2))
			res = true;
	}
	free_matrix(splitted_paths);
	free_matrix(cmd1_path);
	free_matrix(cmd2_path);
	free_matrix(cmd);
	return (res);
}

char	**split_paths(char *envp)
{
	char	**splitted_paths;

	splitted_paths = ft_split(envp, ':');
	if (!splitted_paths)
	{
		perror("Error checking command routes\n");
		exit(EXIT_FAILURE);
	}
	return (splitted_paths);
}

char	**concat_paths(char **splitted_paths, char *cmd)
{
	char	**full_path;
	int		i;

	i = 0;
	full_path = malloc((ft_matrixlen(splitted_paths) + 1) * sizeof(char *));
	if (!full_path)
		return (NULL);
	while (splitted_paths[i])
	{
		full_path[i] = cmdcat(splitted_paths[i], cmd);
		i++;
	}
	full_path[i] = NULL;
	return (full_path);
}

char	*cmdcat(char *s1, char *s2)
{
	char	*cmd_concat;
	char	*temp;

	temp = ft_strjoin(s1, "/");
	if (!temp)
		return (NULL);
	cmd_concat = ft_strjoin(temp, s2);
	free(temp);
	return (cmd_concat);
}

bool	path_validation(char **cmd_path, char *cmd)
{
	int	i;

	i = 0;
	while (cmd_path[i])
	{
		if (access(cmd_path[i], F_OK | X_OK) == 0)
			return (true);
		i++;
	}
	error_cmd(cmd);
	return (false);
}
