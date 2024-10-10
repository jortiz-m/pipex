/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:05:38 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/10 10:10:57 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

bool	fd_validation(const char *file1)
{
	if (access(file1, F_OK | R_OK) == 0)
		return (true);
	perror("fd");
	return (false);
}
