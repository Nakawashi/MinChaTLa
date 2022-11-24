/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:15:50 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/24 07:45:56 by hrolle           ###   ########.fr       */
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

int	exec_cmd(t_cmdli *cmdli, char *read)
{
	if (!is_builtin(cmdli))
		cmdli->cmd = get_absolute_path(cmdli->cmd, ft_get_var("PATH"));
	if (!cmdli->cmd)
		return (1);
	if (cmdli->pipe_out)
		if (pipe(cmdli->pipe_out) == -1)
			exit(1);//---------------------------------------------------------message d'erreur
	cmdli->pid = fork();
	if (cmdli->pid == -1)
	{
		g_errno = errno;
		ft_printfd(2, "#+wminishell#0:#/r %s#0\n", strerror(g_errno));
		return (g_errno);
	}
	else if (!cmdli->pid)
	{
		set_redirection(cmdli);
		if (exec_builtin(&cmdli, read) == 1)
			exit(0);
		if (execve(cmdli->cmd, cmdli->cmd_args, ft_get_str_env()) == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s: #/r%s#0\n",
				cmdli->cmd_args[0], strerror(g_errno));
			close(STDIN_FILENO);
			close(STDOUT_FILENO);
			exit(g_errno);
		}
	}
	return (close_and_free(cmdli));
}
