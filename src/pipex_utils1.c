/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 16:54:37 by ahovakim          #+#    #+#             */
/*   Updated: 2023/07/01 18:04:11 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_proc(t_data args, int index)
{
	if (index == 2)
	{
		if (dup2(args.fd1, STDIN_FILENO) == -1)
			error_close(args);
		if (dup2(args.fds[index - 2][1], STDOUT_FILENO) == -1)
			error_close(args);
	}
	else if (index == args.argc - 2)
	{
		if (dup2(args.fds[index - 3][0], STDIN_FILENO) == -1)
			error_close(args);
		if (dup2(args.fd2, STDOUT_FILENO) == -1)
			error_close(args);
	}
	else
	{
		if (dup2(args.fds[index - 3][0], STDIN_FILENO) == -1)
			error_close(args);
		if (dup2(args.fds[index - 2][1], STDOUT_FILENO) == -1)
			error_close(args);
	}
	close(args.fd1);
	close(args.fd2);
	close_fds(args);
	free_2d(args.path);
}

char	*find_cmd(t_data args, char **cmd)
{
	char	*cmd_path;
	char	*cmd_slash;
	int		i;

	i = 0;
	cmd_slash = ft_strjoin("/", cmd[0]);
	while (args.path[i])
	{
		cmd_path = ft_strjoin(args.path[i], cmd_slash);
		if (!access(cmd_path, X_OK))
		{
			free(cmd[0]);
			free(cmd_slash);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	free(cmd_slash);
	return (cmd[0]);
}
