/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/07/22 22:30:39 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	valgrind --leak-check=full ./minishell
*/

#ifndef MINISHELL_H
# define MINISHELL_H

# define _XOPEN_SOURCE 700	// Macro utilizada para evitar errores por
							// inicializaciones o estructuras incompletas.

# include "libft/includes/libft.h" // libft
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>  // redline
# include <readline/readline.h> // redline
# include <stdio.h>             // redline
# include <signal.h>            // señales
# include <sys/types.h>
# include <sys/wait.h>
# include <dirent.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define NO_QUOTE 0
# define DQ_OPEN 1
# define SQ_OPEN 2

# define STDIN_FILENO 0  // entrada estandar de informacion (por la terminal)
# define STDOUT_FILENO 1 // salida estandar de informacion (en la terminal)
# define STDERR_FILENO 2 // error en la salida estandar (en la terminal)

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

# define NC "\033[0m"
# define RED "\033[31;1m"

/*
	Variable Global:
		0 = close
		1 = open
*/
extern int	g_error;

/*
	Usaremos esta estructura para guardar los estados de pipes y redirecciones.
*/
typedef struct s_pipe_red
{
	int		pipe;
	int		red;
}			t_pipe_red;

/*
	Esta estructura de la expansion de las variabes de entorno.
*/
typedef struct s_var
{
	char	*key;
	char	*value;
}			t_var;

/*
	- *prompt		= linea de comandos leida por el shell, sin parsear.
	- **env			= matriz de punteros a las variables de entorno del shell.
	- pid			= id del proceso actual de la consola.
	- *cmds			= puntero a la estructura de comandos.
	- **full_prompt	= matriz bidimensional de la linea de comandos ya parseada
						y spliteada.
	- *cmd_path		= ruta del primer comandos encontrado en el input.
	- inline		= file descriptor a leer para ejecutar un comando.
	- outline		= file descriptor a escribir para ejecutar un comando.
*/
typedef struct s_shell
{
	char	*prompt;
	char	*parsed_prompt;
	char	**env;
	char	**full_cmd;
	char	*cmd_path;
	int		g_status;
	int		infile;
	int		fdin;
	int		pin;
	int		outfile;
	int		fdout;
	int		pout;
	pid_t	pid;
	int		exit;
	int		exec_signal;
}			t_shell;

int			main(int argc, char **argv, char **envp);
void		init_pipe_red(t_pipe_red *value);
void		init_prompt(t_shell *shell);
int			check_cmd(t_shell *shell);
int			check_quotes(char quote, int state);
int			check_first_pipe(char *prompt);
int			check_last_pipe_red(char *prompt);
int			check_mixes(char *prompt, int *pos);
int			validating_pipes_reds(char *prompt);
void		set_pipe_red(t_pipe_red *value, int flag);
int			handle_pipe_red(char c, t_pipe_red *value, char *prompt, int *pos);
int			update_quote_state(char c, int quote_state);
int			validating_pipes_reds(char *prompt);
char		*process_token(char *prompt, int *pos);
char		**super_split(char *prompt);
char		**parse_input(char *prompt);
char		*process_dq(char *prompt, int *pos);
char		*process_sq(char *prompt, int *pos);
char		*process_pipe(char *prompt, int *pos);
char		*process_red1(char *prompt, int *pos);
char		*process_red2(char *prompt, int *pos);
int			strlen_end_word(char *prompt, int pos);
char		*process_char(char *prompt, int *pos);
t_var		**init_envp(char **envp);
char		*get_var(t_var **list_var, char *key);
char		*key_x_value(t_var **env_list, char *str, t_shell *shell);
void		expand_env_var(t_shell *shell, char **envp);
char		*find_varname(char *str, int pos);
void		remove_dquotes(char *str);
void		handler(int signal);
void		if_signal(void);
void		ft_cd(char **full_cmd, t_shell *shell);
void		ft_echo(char **args);
void		ft_env(t_shell *shell, char **full_cmd);
void		ft_exit(char **cmd, t_shell *shell);
void		ft_export(char **full_cmd, t_shell *shell);
void		ft_pwd(t_shell *shell, char **full_cmd);
void		ft_unset(char **name_var, t_shell *shell);
int			is_builtin(char *cmd);
void		execute_builtin(t_shell *shell, char **full_cmd);
void		ft_env_error(int bad_env, char *env);
int			is_bad_env(char *env);
void		ft_new_env(char *name_var, char *value_var, t_shell *shell);
/* executor */
int			execute_ins(t_shell *shell, char **cmd);
void		exec_choose(t_shell *shell, char **cmd);
void		execute(t_shell *shell);
/*redirection*/
void		apply_redirections(char **prompt, t_shell *shell);
void		apply_outfile(char **name, t_shell *shell, int i);
void		apply_infile(char **name, t_shell *shell, int i);
void		apply_pipe(t_shell *shell, char **cmd, int *prev_fd);
void		apply_heredoc(char *delimiter, t_shell *shell);
void		reset_redirections(t_shell *shell);
void		setup_redirections(t_shell *shell);
/*clean*/
void		ft_close_resets(t_shell *shell);

#endif