/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/20 17:03:19 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;


void	shell_prompt(t_shell *shell)
{

}

void	shell_read(t_shell *shell)
{
	shell->line = readline("minishell$ ");
	if (!shell->line)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (ft_strlen(shell->line) > 0)
		add_history(shell->line);
}


int	main(int ac, char **av, char **envp)
{
	t_cmd		prompt;
	char		*str_in;
	char		*str_out;

	if (ac < 2)
	{
		ft_putstr_fd(RED"minishell: invalid arguments\n"NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
 	while (1)
	{	
		shell_prompt(&shell);
		shell_read(&shell);
		init_prompt(&av, &envp);
		shell_execute(&shell);
	} 
	return (0);
}