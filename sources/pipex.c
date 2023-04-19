/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:10:37 by ffarkas           #+#    #+#             */
/*   Updated: 2023/04/16 10:39:04 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_append_here_doc(char **av, int *p_fd)
{
	char	*buffer;
	int		limit_len;

	limit_len = ft_strlen(av[2]);
	close(p_fd[0]);
	while (1)
	{
		buffer = ft_get_next_line(0);
		if (ft_strncmp(buffer, av[2], limit_len) == 0 \
			&& buffer[limit_len] != '\0')
		{
			free(buffer);
			exit(0);
		}
		ft_putstr_fd(buffer, p_fd[1]);
		free(buffer);
	}
}

void	ft_here_doc(char **av)
{
	int		p_fd[2];
	pid_t	pid;

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		ft_append_here_doc(av, p_fd);
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
		wait(NULL);
	}
}

void	ft_run_command(char *cmd, char **env)
{
	char	**single_cmd;
	char	*path;

	single_cmd = ft_split(cmd, ' ');
	path = ft_get_cmd_path(single_cmd[0], env);
	if (execve(path, single_cmd, env) == -1)
	{
		ft_putstr_fd(ft_strjoin(ft_strjoin("pipex: ", single_cmd[0]), \
": command not found\n"), 2);
		ft_clear_arr(single_cmd);
		exit(1);
	}
}

void	ft_pipeline(char *cmd, char **env, int *i)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		close(p_fd[0]);
		dup2(p_fd[1], 1);
		ft_run_command(cmd, env);
	}
	else
	{
		close(p_fd[1]);
		dup2(p_fd[0], 0);
	}
	(*i)++;
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		fd_in;
	int		fd_out;

	if (ac < 5)
		ft_usage();
	if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		if (ac < 6)
			ft_usage();
		i = 3;
		fd_out = ft_open_file(av[ac - 1], 2);
		ft_here_doc(av);
	}
	else
	{
		i = 2;
		fd_in = ft_open_file(av[1], 0);
		fd_out = ft_open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		ft_pipeline(av[i], env, &i);
	dup2(fd_out, 1);
	ft_run_command(av[ac - 2], env);
}
