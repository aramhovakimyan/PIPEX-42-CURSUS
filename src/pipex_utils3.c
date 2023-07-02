/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:01:13 by ahovakim          #+#    #+#             */
/*   Updated: 2023/06/25 16:20:23 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_2d(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		++i;
	}
	free(path);
}

void	error_message(void)
{
	perror("Error");
	exit(1);
}

void	error_close(t_data args)
{
	close_fds(args);
	error_message();
}

void	close_fds(t_data args)
{
	int	i;

	i = 0;
	while (i < args.argc - 4)
	{
		close(args.fds[i][0]);
		close(args.fds[i][1]);
		free(args.fds[i]);
		args.fds[i] = NULL;
		++i;
	}
	free(args.fds);
}

void	error_pipe(t_data args, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		close(args.fds[i][0]);
		close(args.fds[i][1]);
		free(args.fds[i]);
		args.fds[i] = NULL;
		++i;
	}
	free(args.fds);
	error_message();
}
