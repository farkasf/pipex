/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:10:37 by ffarkas           #+#    #+#             */
/*   Updated: 2023/04/15 03:36:14 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_run_command(char *cmd, char **env)
{
	char	**single_cmd;
	char	*path;

	single_cmd = ft_split(cmd, ' ');
	path = ft_get_cmd_path(single_cmd[0], env);
	if (execve(path, single_cmd, env) == -1)
	{
		ft_putstr_fd(ft_strjoin("pipex: command not found: ", single_cmd[0]), 2);
		ft_putstr_fd("\n", 2);
		ft_clear_tab(single_cmd);
		exit(0);
	}
}

void	ft_pipeline(char *cmd, char **env, int *i)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
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
		ft_usage(1);
	i = 2;
	fd_in = ft_open_file(av[1], 0);
	fd_out = ft_open_file(av[ac - 1], 1);
	dup2(fd_in, 0);
	while (i < ac - 2)
		ft_pipeline(av[i], env, &i);
	dup2(fd_out, 1);
	ft_run_command(av[ac - 2], env);
}
