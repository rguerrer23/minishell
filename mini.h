/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rguerrer <rguerrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:51:36 by rguerrer          #+#    #+#             */
/*   Updated: 2024/06/18 17:23:14 by rguerrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

# define STDIN_FILENO 0
# define STDOUT_FILENO 1
# define STDERR_FILENO 2


# define SHELL_NAME "minishell"
# define SHELL_PROMPT "minishell$ "

typedef struct s_prompt
{
	t_list	*cmds;
    char    *line;
	char	**envp;
	pid_t	pid;
}		t_prompt;

typedef struct s_mini
{
	char	**full_cmd;
	char	*full_path;
	int	infile;
	int	outfile;
}		t_mini;

int		main(int argc, char **argv, char **envp);
int     ft_echo(char **args);

#endif