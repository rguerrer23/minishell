/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:06:35 by ezhou             #+#    #+#             */
/*   Updated: 2024/03/06 13:11:01 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	char	*ft_current_path(void)
{
	char	*cwd;

	cwd = ft_calloc(PATH_MAX, 1);
	if (!cwd)
		return (printf("Malloc Error\n"), NULL);
	if (getcwd(cwd, PATH_MAX))
	{
		return (cwd);
	}
	else
	{
		printf("Getcwd Error\n");
		return (NULL);
	}
}

static	void	ft_update_oldpwd(char **env)
{
	int		i;
	char	*temp;
	char	*cwd;

	cwd = ft_current_path();
	if (!cwd)
		return ;
	i = 0;
	while (cmd->env[i])
	{
		if (cmd->env && ft_strncmp(cmd->env[i], "OLDPWD", 6))
		{
			temp = ft_strjoin("OLDPWD=", cwd);
			free(cmd->env[i]);
			cmd->env[i] = temp;
		}
		i++;
	}
}

static	void	ft_update_pwd(char **env)
{
	int		i;
	char	*temp;
	char	*cwd;

	cwd = ft_current_path();
	if (!cwd)
		return ;
	i = 0;
	while (cmd->env[i])
	{
		if (cmd->env && ft_strncmp(cmd->env[i], "PWD", 6))
		{
			temp = ft_strjoin("PWD=", cwd);
			free(cmd->env[i]);
			cmd->env[i] = temp;
		}
		i++;
	}
}

int	ft_cd(t_cmd **cmd)
{
	int		i;
	char	*temp;

	i = 0;
	ft_update_oldpwd((*cmd)->env);
	if ((*cmd)->num_arg == 0)
	{
		chdir(getenv("HOME"));
		ft_update_pwd((*cmd)->env);
		return (SUCCESS);
	}
	if (chdir(temp) == -1)
		printf("bash: cd: %s: No such file or directory\n", temp);
	else
	{
		free(temp);
		ft_update_pwd((*cmd)->env);
		return (SUCCESS);
	}
	free(temp);
	return (ERROR);
}
