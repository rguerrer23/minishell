/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:21:51 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/09 19:26:02 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/*
int	check_condition(t_var *var)
{
	return (var->aux[1] == '\0' || var->aux[1] == ' '
		|| var->aux[1] == '=' || var->aux[1] == '\"'
		|| var->aux[1] == '\'' || var->aux[1] == '?'
		|| var->aux[1] == '|' || var->aux[1] == '$');
}

// Si encontramos un carater dolar $ ...
void	is_dolar(t_var *var)
{
	char	*tmp;

	tmp = ft_itoa(var->exit_status);
	var->var_copy = ft_replace(var->var_copy, var->var_copy + var->var_pos_1, var->var_copy + var->var_pos_1 + 2, tmp);
	var->var_pos_1 += ft_strlen(tmp);
	free(tmp);
}

char	*get_var(char *cmd)
{
	t_var	var;

	init_var(&var, cmd);
	if (cmd[0] == '\''
		&& ((cmd[ft_strlen(cmd) - 1] == '\'') || !ft_strchr(var.var_copy, '$')))
		return (var.var_copy);
	while (var.var_copy[var.var_pos_1])
	{
		if (var.var_copy[var.var_pos_1] == '$'
			&& var.var_copy[var.var_pos_1 + 1] == '?')
			is_dolar(&var);
		var.aux = ft_strchr(var.var_copy + var.var_pos_1, '$');
		if (!var.aux)
			break ;
		var.var_pos_2 = ft_get_index(var.var_copy,
				ft_strchr(var.var_copy + var.var_pos_1, '$'));
		if (check_condition(&var))
			var.var_pos_1++;
		//ft_aux_get_var(&var);
	}
	return (var.var_copy);
}

char	**expand_var(char **cmd)
{
	char	**ret;
	int		i;

	i = -1;
	ret = NULL;
	if (!cmd)
		return (NULL);
	while (cmd[++i])
		ret = ft_strd_add(ret, get_var(cmd[i]));
	ft_strd_free(cmd);
	return (ret);
}
*/

