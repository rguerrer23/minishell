/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:32:27 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/16 16:39:53 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

// SIGINT(2) = CTRL + 'C' = cerramos proceso y creamos nueva linea.
// SIGKILL(9) = CTRL + 'D' = termina el shell forzosamente (no se puede manejar)
// SIGQUIT(3) = CTRL + '\' = salida de teclado (no hace nada).
void	handler(int signal)
{
    if (signal == SIGINT)
    {
        rl_on_new_line(); // Nos hemos movido a una nueva línea.
        rl_redisplay(); // Refrescamos el buffer actual de visualización.
        ft_putstr_fd("  \n", 1); // Pasamos esto al fd 1.
        rl_replace_line("  ", 0); // Borramos el buffer.
        rl_on_new_line(); // Nos movemos de nuevo a una nueva línea.
        rl_redisplay(); // Refrescamos de nuevo el buffer para recibir nuevos comandos.
        g_error = 130;
    }
    else if (signal == SIGQUIT)
    {
        rl_on_new_line();        // Mueve el cursor a una nueva línea
        rl_replace_line("  ", 0); // Borramos el buffer.
        rl_redisplay();          // Redibuja la línea de entrada
		g_error = 131;
    }
}

void	if_signal(void)
{
    struct sigaction sig;

    sig.sa_handler = &handler;
    sig.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sig, NULL);
    sigaction(SIGQUIT, &sig, NULL);
}
