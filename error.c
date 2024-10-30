/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:11:40 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/25 14:12:02 by jortiz-m         ###   ########.fr       */
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
