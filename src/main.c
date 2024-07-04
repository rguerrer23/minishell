/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:03:39 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/04 22:11:41 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int g_mutex = 0;

/*
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
*/

int main() {
    char *prompt = "ls | grep .c > output.txt";

    // Ejemplo de uso de las funciones principales
    printf("Prompt original: %s\n", prompt);

    // Validación de pipes y redirecciones
    if (validating_pipes_reds(prompt)) {
        printf("Pipes y redirecciones válidos.\n");
    } else {
        printf("Error en la validación de pipes y redirecciones.\n");
        return 1;
    }

    // Separación del prompt en comandos individuales
    char **commands = cmd_trim(prompt);
    printf("Comandos separados:\n");
    for (int i = 0; commands[i] != NULL; i++) {
        printf("- %s\n", commands[i]);
    }

    // Expansión de variables en los comandos
    char **expanded_commands = ft_expand_vars(commands);
    printf("Comandos expandidos:\n");
    for (int i = 0; expanded_commands[i] != NULL; i++) {
        printf("- %s\n", expanded_commands[i]);
    }

    // Limpieza de memoria
    ft_charppfree(commands);
    ft_charppfree(expanded_commands);

    return 0;
}