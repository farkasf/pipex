/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:10:48 by ffarkas           #+#    #+#             */
/*   Updated: 2023/04/16 00:04:16 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_usage(void)
{
	ft_putstr_fd("pipex: usage: ./pipex infile cmd1 \
cmd2 ... cmdn outfile\n", 2);
	ft_putstr_fd("              ./pipex here_doc LIMITER \
cmd1 cmd2 ... cmdn outfile\n", 2);
	exit(1);
}

int	ft_open_file(char *file, int mode)
{
	int	fd;

	if (mode == 0)
		fd = open(file, O_RDONLY, 0777);
	if (mode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (mode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
	{
		ft_putstr_fd(ft_strjoin(ft_strjoin("pipex: ", file), \
": failed to open file\n"), 2);
		exit(1);
	}
	return (fd);
}

char	*ft_get_env_var(char **env)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		var = ft_substr(env[i], 0, j);
		if (ft_strncmp(var, "PATH", ft_strlen(var)) == 0)
		{
			free(var);
			return (env[i] + j + 1);
		}
		free(var);
		i++;
	}
	return (NULL);
}

char	*ft_get_cmd_path(char *cmd, char **env)
{
	int		i;
	char	*cmd_path;
	char	**env_var_path;
	char	*file_path;
	char	**single_cmd;

	i = 0;
	env_var_path = ft_split(ft_get_env_var(env), ':');
	single_cmd = ft_split(cmd, ' ');
	while (env_var_path[i])
	{
		file_path = ft_strjoin(env_var_path[i], "/");
		cmd_path = ft_strjoin(file_path, single_cmd[0]);
		free(file_path);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_clear_tab(single_cmd);
			return (cmd_path);
		}
		free(cmd_path);
		i++;
	}
	ft_clear_tab(env_var_path);
	ft_clear_tab(single_cmd);
	return (cmd);
}

void	ft_clear_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
