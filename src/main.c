/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/04 19:01:43 by jmartos-         ###   ########.fr       */
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
	shell->prompt = readline("Minishell$~ ");
	if (!shell->prompt)
	{
		ft_putstr_fd("exit\n", STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (ft_strlen(shell->prompt) > 0)
		add_history(shell->prompt);
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
		shell_read();
		init_prompt(&av); // jmartos-
		shell_execute(); // ricardo
	} 
	return (0);
}
