/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 21:40:30 by kevlar            #+#    #+#             */
/*   Updated: 2024/07/22 01:00:26 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_pipe_red(t_pipe_red *value)
{
	value->pipe = 0;
	value->red = 0;
}

t_var **init_envp(char **envp)
{
	t_var **list_var;
	int c;
	int i;

	i = 0;
	c = ft_strd_len(envp);
	list_var = ft_calloc(sizeof(t_var *), c + 1); // +1 para NULL.
	if (!list_var)
        return (NULL); // error por falta de memoria.
	while (i < c)
	{
		list_var[i] = ft_calloc(sizeof(t_var), 1);
		if (!list_var[i])
        {
            while (i-- > 0)
            {
                free(list_var[i]->key);
                free(list_var[i]->value);
                free(list_var[i]);
				
            }
            free(list_var);
            return (NULL); // error por falta de memoria.
		}
		list_var[i]->key = ft_strndup(envp[i], ft_strchr(envp[i], '=') - envp[i]);
		list_var[i]->value = ft_strdup(ft_strchr(envp[i], '=') + 1);
		i++;
	}
	list_var[i] = NULL;
	return (list_var);
}

void	init_prompt(t_shell *shell)
{
	int i;
	
	i = 0;
	if (!check_cmd(shell))
	{
		ft_printf(RED"ERROR! (init_prompt)"NC);
		exit (EXIT_FAILURE);
	}
	shell->full_cmd = parse_input(shell->prompt, shell);
	expand_env_var(shell, shell->env);
	while(shell->full_cmd[i] != NULL)
	{
		remove_dquotes(shell->full_cmd[i]);
		printf("prompt = %s\n", shell->full_cmd[i]);
		i++;
	}
}
