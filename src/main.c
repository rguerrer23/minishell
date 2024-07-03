/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/03 22:44:01 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;


void	shell_prompt(void)
{
	//char	*user;
	//user = getcwd(NULL, 0);
	ft_printf("Minishell$~ ");
}

void	shell_read(t_shell *shell)
{
	shell->line = readline("Minishell$~ ");
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
	t_shell		shell;

	if (ac < 2)
	{
		ft_putstr_fd(RED"minishell: invalid arguments\n"NC, STDERR_FILENO);
		return (EXIT_FAILURE);
	}
 	while (1)
	{	
		shell_prompt();
		shell_read(&shell);
		init_prompt(&av, &envp); // jmartos-
		shell_execute(&shell, &prompt); // ricardo
	} 
	return (0);
}
