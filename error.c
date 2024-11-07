/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:11:40 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/11/07 11:27:53 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_cmd(char *cmd)
{
	char	*error_msg;
	char	*test;

	error_msg = ft_strdup("command not found: ");
	test = ft_strjoin(error_msg, cmd);
	free(error_msg);
	error_msg = ft_strjoin(test, "\n");
	ft_putstr_fd(error_msg, 2);
	free(test);
	free(error_msg);
}

void	error_fd(const char *file)
{
	char	*error_msg;
	char	*test;

	error_msg = ft_strdup("no such file or directory: ");
	test = ft_strjoin(error_msg, file);
	free(error_msg);
	error_msg = ft_strjoin(test, "\n");
	ft_putstr_fd(error_msg, 2);
	free(test);
	free(error_msg);
}

void	error_per(const char *fd, char *cmd_name)
{
	char	*error_msg;
	char	*placeholder;

	placeholder = ft_strjoin(cmd_name, ": ");
	error_msg = ft_strjoin(placeholder, fd);
	free(placeholder);
	placeholder = ft_strjoin(error_msg, ": Permission denied\n");
	free(error_msg);
	ft_putstr_fd(placeholder, 2);
	free(placeholder);
}
