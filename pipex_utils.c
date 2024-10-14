/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:06:56 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/14 13:30:51 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	validate_arguments(int argc, char **argv)
{
	if (argc == 4)
	{
		if (!fd_validation(argv[0]) || !cmd_validation(argv[1], argv[2]))
			exit(EXIT_FAILURE);
	}
	else
	{
		ft_putstr_fd("invalid format: ./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
}

char	*get_path(char **cmd_paths)
{
	char	*cmd_dir;
	int		i;

	i = 0;
	while (cmd_paths[i])
	{
		if (access(cmd_paths[i], F_OK | X_OK) == 0)
		{
			cmd_dir = ft_strdup(cmd_paths[i]);
			return (cmd_dir);
		}
		i++;
	}
	return (NULL);
}

int	open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open_file: Error opening file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
