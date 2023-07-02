/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahovakim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:37:00 by ahovakim          #+#    #+#             */
/*   Updated: 2023/07/01 18:56:54 by ahovakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fd1;
	int		fd2;
	int		argc;
	int		**fds;
	char	**argv;
	char	**envp;
	char	**path;
}	t_data;

char	**ft_split(char const *s, char c);
char	*find_cmd(t_data args, char **cmd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_2d(char **path);
void	error_message(void);
void	error_pipe(t_data args, int index);
void	error_close(t_data args);
void	close_fds(t_data args);
void	pipes(t_data *args);
void	pipex(t_data args);
void	child_proc(t_data args, int index);

#endif // PIPEX_H
