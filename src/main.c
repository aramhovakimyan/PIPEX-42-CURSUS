/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:11:32 by ahovakim          #+#    #+#             */
/*   Updated: 2023/07/01 18:32:57 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**find_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (ft_split(ft_strchr(envp[i], '/'), ':'));
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	args;

	if (argc < 5)
		return (0);
	args.argc = argc;
	args.argv = argv;
	args.envp = envp;
	args.path = find_path(envp);
	if (!args.path)
		return (1);
	args.fd1 = open(argv[1], O_RDONLY);
	args.fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	pipex(args);
	while (wait(NULL) != -1)
		;
	free_2d(args.path);
	return (0);
}
