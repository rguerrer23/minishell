/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/04 19:01:42 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/includes/libft.h"	// libft
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>				// señales (server/client)
# include <stdio.h> 				// redline
# include <readline/readline.h>		// redline
# include <readline/history.h>		// redline

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define NO_QUOTE 0
# define DQ_OPEN 1
# define SQ_OPEN 2

# define STDIN_FILENO 0 // entrada estandar de informacion (por la terminal)
# define STDOUT_FILENO 1 // salida estandar de informacion (en la terminal)
# define STDERR_FILENO 2 // error en la salida estandar (en la terminal)

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

# define NC		"\033[0m"
# define RED	"\033[31;1m"

/*
	Usaremos esta estructura para guardar los estados de pipes y redirecciones.
*/
typedef struct s_pipe_red
{
	int			pipe;
	int			red;
}				t_pipe_red;

/*
	- *prompt	= linea de comandos leida por el shell, sin parsear.
	- **env		= matriz de punteros a las variables de entorno del shell.
	- pid		= id del proceso actual de la consola.
	- *cmds		= puntero a la estructura de comandos.
*/
typedef struct s_shell
{
	char	*prompt; // jmartos-
	char	*parsed_prompt; // jmartos-
	char	**env;
	pid_t	pid;
	t_list	*cmd;
}			t_shell;

/*	
	- **full_prompt	= matriz bidimensional de la linea de comandos ya parseada y spliteada.
	- *cmd_path		= ruta del primer comandos encontrado en el input.
	- inline		= (STDIN 0) file descriptor a leer para ejecutar un comando.
	- outline		= (STDOUT 1)file descriptor a escribir para ejecutar un comando.
*/
typedef struct s_cmd
{
	char	**checked_prompt; // jmartos-
	char	*cmd_path;
	int		infile;
	int		outfile;
}			t_cmd;


int		main(int ac, char **av, char **envp);

#endif