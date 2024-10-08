/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:05:38 by jortiz-m          #+#    #+#             */
/*   Updated: 2024/10/08 12:05:40 by jortiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* Valida si existe el file1 y el file2, si el file2 no existe, lo crea */
bool	fd_validation(const char *file1, const char *file2)
{
	if (access(file1, F_OK | R_OK) == 0)
	{
		if (access(file2, F_OK | W_OK) == -1)
		{
			exec_touch(file2);
			printf("FD NO EXISTIA, SE HA CREADO");
		}
		printf("FD VÁLIDO");
		return (true);
	}
	return (false);
}
