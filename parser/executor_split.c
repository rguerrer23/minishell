/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartos- <jmartos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 02:25:24 by jmartos-          #+#    #+#             */
/*   Updated: 2024/07/24 03:25:33 by jmartos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int pipe_counter(char **str)
{
    int i = 0;
    int cont = 1;
    while (str[i])
    {
        if (strcmp(str[i], "|") == 0)
            cont++;
        i++;
    }
    return cont;
}

char **allocate_array(int size) {
    char **array = (char **)malloc((size + 1) * sizeof(char *));
    if (!array) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i <= size; ++i) {
        array[i] = NULL;
    }
    return array;
}

void parse_command(char **split_cmd, int *index, t_cmd *cmd_struct)
{
    int arg_count = 0;
    int in_count = 0;
    int out_count = 0;

    // Asignamos memoria para los arrays, tamaño inicial 10
    cmd_struct->args = allocate_array(10);
    cmd_struct->incmd = allocate_array(10);
    cmd_struct->outcmd = allocate_array(10);

    while (split_cmd[*index] && strcmp(split_cmd[*index], "|") != 0)
    {
        if (strcmp(split_cmd[*index], "<") == 0 || strcmp(split_cmd[*index], "<<") == 0)
        {
            cmd_struct->incmd[in_count++] = strdup(split_cmd[*index]);
            (*index)++;
            if (split_cmd[*index])
			{
                cmd_struct->incmd[in_count++] = strdup(split_cmd[*index]);
				(*index)++;
			}
        }
        else if (strcmp(split_cmd[*index], ">") == 0 || strcmp(split_cmd[*index], ">>") == 0)
        {
            cmd_struct->outcmd[out_count++] = strdup(split_cmd[*index]);
            (*index)++;
            if (split_cmd[*index])
			{
                cmd_struct->outcmd[out_count++] = strdup(split_cmd[*index]);
				(*index)++;
			}
        }
        else
        {
            if (cmd_struct->cmd == NULL)
            {
                cmd_struct->cmd = strdup(split_cmd[*index]);
            }
            else
            {
                cmd_struct->args[arg_count++] = strdup(split_cmd[*index]);
            }
            (*index)++;
        }
    }

    // Set NULL terminator for args, incmd, and outcmd
    cmd_struct->args[arg_count] = NULL;
    cmd_struct->incmd[in_count] = NULL;
    cmd_struct->outcmd[out_count] = NULL;
}

void executor_split(t_shell *shell)
{
    t_cmd **cmds;
    int i = 0;
    int cmd_index = 0;
    int pipe_count = pipe_counter(shell->split_cmd);

    cmds = (t_cmd **)malloc(sizeof(t_cmd *) * (pipe_count + 1));
    if (!cmds)
        return;
    while (shell->split_cmd[i])
    {
        cmds[cmd_index] = (t_cmd *)malloc(sizeof(t_cmd));
        if (!cmds[cmd_index])
            return;
        cmds[cmd_index]->cmd = NULL;
        cmds[cmd_index]->args = NULL;
        cmds[cmd_index]->incmd = NULL;
        cmds[cmd_index]->outcmd = NULL;
        parse_command(shell->split_cmd, &i, cmds[cmd_index]);
        if (shell->split_cmd[i] && strcmp(shell->split_cmd[i], "|") == 0)
            i++;
        cmd_index++;
    }
    cmds[pipe_count] = NULL;
    shell->cmds = cmds;
}