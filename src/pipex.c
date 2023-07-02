/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:54:20 by ahovakim          #+#    #+#             */
/*   Updated: 2023/07/01 18:41:33 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipes(t_data *args)
{
	int	i;

	args->fds = (int **)malloc(sizeof(int *) * (args->argc - 4));
	if (!args->fds)
		error_message();
	i = 0;
	while (i < args->argc - 4)
	{
		args->fds[i] = (int *)malloc(sizeof(int) * 2);
		if (!args->fds[i])
			error_message();
		if (pipe(args->fds[i]) == -1)
			error_pipe(*args, i);
		i++;
	}
}

static void	pipex_helper(t_data args, int ind)
{
	pid_t	ret;
	char	**cmd;

	cmd = ft_split(args.argv[ind], ' ');
	if (!cmd)
		error_message();
	if (cmd[0] && !ft_strchr(cmd[0], '/'))
		cmd[0] = find_cmd(args, cmd);
	ret = fork();
	if (ret < 0)
		error_message();
	else if (ret == 0)
	{
		child_proc(args, ind);
		execve(cmd[0], cmd, args.envp);
		error_message();
	}
	free_2d(cmd);
}

void	pipex(t_data args)
{
	int	i;

	i = 2;
	pipes(&args);
	while (i < args.argc - 1)
	{
		pipex_helper(args, i);
		++i;
	}
	close(args.fd1);
	close(args.fd2);
	close_fds(args);
}
