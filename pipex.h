/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:55:32 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/14 15:16:48 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <fcntl.h>
# include "lib/libft/libft.h"

# ifndef LINUX_PATH
#  define LINUX_PATH "/home/jortiz-m/.pyenv/shims:/home/jortiz-m/.pyenv/bin:\
/home/jortiz-m/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:\
/bin:/usr/games:/usr/local/games:/snap/bin"

# endif

char	**split_paths(char *envp);
char	**concat_paths(char **splitted_paths, char *cmd);
char	*cmdcat(char *s1, char *s2);
bool	path_validation(char **cmd_path);
bool	cmd_validation(char *cmd1, char *cmd2);

bool	fd_validation(const char *file1);

void	exec_cmd(char *cmd_arg);

void	free_matrix(char **matrix);
int		ft_matrixlen(char **matrix);

int		*create_pipe(void);

void	validate_arguments(int argc, char **argv);
char	*get_path(char **cmd_paths);
int		open_file(char *file, int mode);

void	child_process(char **argv, int *pipe, char *cmd, pid_t child);
void	parent_process(char **argv, int *pipe, char *cmd);

#endif