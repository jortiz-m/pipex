/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:05:38 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/11/06 12:33:36 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	fd_valid(const char *file1, char *cmd_name)
{
	if (access(file1, F_OK) == -1)
	{
		error_fd(file1);
		return (false);
	}
	if (access(file1, R_OK) == -1)
	{
		error_per(file1, cmd_name);
		return (false);
	}
	return (true);
}
