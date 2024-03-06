/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 12:42:47 by rguerrer          #+#    #+#             */
/*   Updated: 2024/03/06 15:49:58 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR 1
# define SUCCESS 0

typedef struct s_env
{
	char			**env;
	int				env_size;
}					t_env;

typedef struct s_cmd
{
	struct s_cmd	*next;
	// t_fds           pipes;
	char			*cmd_path;
	char			**arg;
	t_env			*env;
	int				num_arg;
}					t_cmd;

int					main(int argc, char **argv, char **envp);
int	ft_pwd(void);

#endif