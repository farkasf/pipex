/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:11:16 by ffarkas           #+#    #+#             */
/*   Updated: 2023/04/15 03:38:46 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char	*ft_get_env_var(char **env);
char	*ft_get_cmd_path(char *cmd, char **env);
void	ft_run_command(char *cmd, char **env);
void	ft_pipeline(char *cmd, char **env, int *i);
void	ft_usage(int status);
int		ft_open_file(char *file, int mode);
void	ft_clear_tab(char **tab);

#endif
