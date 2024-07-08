/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevlar <kevlar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/08 14:26:44 by kevlar           ###   ########.fr       */
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
	Esta estructura definira la expansion de las variabes de entorno.
*/
typedef struct s_var
{
	char		*var_copy;
	int			var_pos_1;
	int			var_pos_2;
	int			exit_status;
	char		*aux;
}				t_var;

/*
	- *prompt	= linea de comandos leida por el shell, sin parsear.
	- 
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

/*********************/
/* FUNCIONES COMUNES */
/*********************/
int		main(int ac, char **av, char **envp);
/*******************************/
/* FUNCIONES JMARTOS- (PARSER) */
/*******************************/
/* init.c */
void	init_pipe_red(t_pipe_red *value);
void	init_prompt(char **av);
void	init_var(t_var *var, char *cmd);
/* command.c */
int		check_cmd(t_shell *shell);
/* check_quotes.c */
int		check_quotes(char quote, int state);
/* pipes_redirections.c */
int		check_first_pipe(char *prompt);
int		validating_pipes_reds(char *prompt);
/* parse.c */
char	**cmd_trim(char *prompt);
char	**parse_input(char *prompt);
/* parse_utils_1.c */
char	*process_dq(char *prompt, int *pos);
char	*process_sq(char *prompt, int *pos);
char	*process_pipe(char *prompt, int *pos);
char	*process_red1(char *prompt, int *pos);
char	*process_red2(char *prompt, int *pos);
/* parse_utils_2.c */
int		strlen_end_word(char *prompt, int pos);
char	*process_char(char *prompt, int *pos);
/* parse_utils_3.c */
int		check_condition(t_var *var);
void	is_dolar(t_var *var);
char	*get_var(char *cmd);
char	**expand_var(char **cmd);
/* parse_utils_4.c */
// HAY QUE REVISAR ESTAS FUNCIONES, SOLO COPIADAS PARA ENTENDER CODIGO!!!
int		ft_get_index(char *str, char *index);
char	*ft_replace(char *str, char *start, char *end, char *replace);

#endif