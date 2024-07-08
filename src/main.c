/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/08 12:04:45 by kevlar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;

/*
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
*/
int	main(int argc, char **argv __attribute__((unused)), char **envp)
{
	char	*line;
	char	**cmds;
	int		check;
    t_shell shell;
    t_cmd   cmd;
    (void)envp;

    check = 0;
	if (argc != 1)
		exit(0);
	while (1)
	{
		line = readline("Minishell$~ ");
		init_prompt(&shell);
        execute(&shell, &cmd);
		if (check == 1)
		{
			cmds = parse_input(line);
			ft_strd_free(cmds);
			free(line);
		}
		else if (check == 0)
        {
			ft_printf(RED"minishell syntax error\n"NC);
            exit (0);
        }
    }
}
