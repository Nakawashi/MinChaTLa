/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:50 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/26 03:07:38 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	close_pipe(int *pipe)
{
	if (pipe)
	{
		close(pipe[0]);
		close(pipe[1]);
	}
	return (0);
}

int	close_and_free(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close_pipe(cmdli->pipe_in);
	if (cmdli->cmd && is_builtin(cmdli) == 0)
	{
		free(cmdli->cmd);
		cmdli->cmd = NULL;
	}
	if (cmdli->file_in)
	{
		free_tab(cmdli->file_in);
		cmdli->file_in = NULL;
	}
	if (cmdli->file_out)
	{
		free_file(cmdli->file_out);
		cmdli->file_out = NULL;
	}
	return (0);
}

void	write_heredoc(t_cmdli *cmdli)
{
	if (!cmdli->here_doc)
		return ;
	if (!cmdli->pipe_in)
	{
		cmdli->pipe_in = malloc(2 * sizeof(int));
		if (!cmdli->pipe_in)
			return (void_error(1, "memory allocation failed"));
	}
	else
		close_pipe(cmdli->pipe_in);
	if (pipe(cmdli->pipe_in) == -1)
		return (void_error(errno, NULL));
	if (write(cmdli->pipe_in[1],
			cmdli->here_doc, ft_strlen(cmdli->here_doc)) == -1)
		return (void_error(errno, NULL));
}

int	exec_cmd(t_cmdli *cmdli, char *read)
{
	cmdli->cmd = get_absolute_path(cmdli->cmd, ft_get_var("PATH"));
	if (!cmdli->cmd)
		return (1);
	write_heredoc(cmdli);
	if (cmdli->pipe_out)
		if (pipe(cmdli->pipe_out) == -1)
			return (return_error(errno, NULL));
	cmdli->pid = fork();
	if (cmdli->pid == -1)
		return (return_error(errno, NULL));
	else if (!cmdli->pid)
	{
		set_redirection(cmdli);
		if (exec_builtin(&cmdli, read) == 1)
			exit(g_errno);
		if (execve(cmdli->cmd, cmdli->cmd_args, ft_get_str_env()) == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s: #/r%s#0\n",
				cmdli->cmd_args[0], strerror(g_errno));
			exit(g_errno);
		}
	}
	return (close_and_free(cmdli));
}
