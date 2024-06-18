/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 19:07:38 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include "libft/libft.h" // libft
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // redline, printf
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h> // redline
# include <readline/history.h> // redline

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN_FILENO 0 // entrada estandar de informacion (por la terminal)
# define STDOUT_FILENO 1 // salida estandar de informacion (en la terminal)
# define STDERR_FILENO 2 // error en la salida estandar (en la terminal)

# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

typedef struct	s_prompt
{
	char		*line;
	char		**envp;
	pid_t		pid;
	t_minishell	*cmds;
}				t_prompt;

typedef struct	s_minishell // estructura principal
{
	char		**full_cmd;
	char		*full_path;
	int			infile;
	int			outfile;
}				t_minishell;

/*******/
/* SRC */
/*******/
int		main(int argc, char **argv, char **envp);
int     ft_echo(char **args);

#endif