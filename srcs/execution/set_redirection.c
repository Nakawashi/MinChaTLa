/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 03:10:11 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/01 02:22:52 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	set_file_in(t_cmdli *cmdli)
{
	unsigned int	i;

	i = 0;
	while (cmdli->file_in[i])
	{
		if (cmdli->fd_in != -1)
			close(cmdli->fd_in);
		cmdli->fd_in = open(cmdli->file_in[i++], O_RDONLY);
		if (cmdli->fd_in == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s:#/r %s#0\n",
				cmdli->file_in[i - 1], strerror(g_errno));
			return (1);
		}
	}
	return (0);
}

int	set_file_out(t_cmdli *cmdli)
{
	unsigned int	i;

	//ft_printfd(2, "Hello ! i'm here !\n");
	i = 0;
	while (cmdli->file_out[i])
	{
		if (cmdli->fd_out != -1)
			close(cmdli->fd_out);
		if (cmdli->file_out[i]->type == RDO)
			cmdli->fd_out = open(cmdli->file_out[i++]->name,
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else if (cmdli->file_out[i]->type == RDOA)
			cmdli->fd_out = open(cmdli->file_out[i++]->name,
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (cmdli->fd_out == -1)
		{
			g_errno = errno;
			ft_printfd(2, "#+wminishell#0: %s:#/r %s#0\n",
				cmdli->file_out[i - 1], strerror(g_errno));
			return (1);
		}
	}
	return (0);
}

void	set_in(t_cmdli *cmdli)
{
	if (cmdli->file_in && cmdli->fd_in != -1 && !cmdli->here_doc)
	{
		dup2(cmdli->fd_in, STDIN_FILENO);
		close(cmdli->fd_in);
		if (cmdli->pipe_in)
			close_pipe(cmdli->pipe_in);
	}
	else if (cmdli->pipe_in)
	{
		dup2(cmdli->pipe_in[0], STDIN_FILENO);
		close_pipe(cmdli->pipe_in);
	}
}

void	set_out(t_cmdli *cmdli)
{
	if (cmdli->fd_out != -1)
	{
		dup2(cmdli->fd_out, STDOUT_FILENO);
		//ft_printfd(2, "Hello ! The cmd is %s\ni'm also here (after the dup2) while the fd_out is [%d] !\n",cmdli->cmd, cmdli->fd_out);
		close(cmdli->fd_out);
		if (cmdli->pipe_out)
			close_pipe(cmdli->pipe_out);
	}
	else if (cmdli->pipe_out)
	{
		dup2(cmdli->pipe_out[1], STDOUT_FILENO);
		close_pipe(cmdli->pipe_out);
	}
}

void	set_redirection(t_cmdli *cmdli)
{
	if (cmdli->pipe_in)
		close(cmdli->pipe_in[1]);
	if (cmdli->pipe_out)
		close(cmdli->pipe_out[0]);
	if (cmdli->file_out)
		set_file_out(cmdli);
	if (cmdli->file_in)
		if (set_file_in(cmdli))
			exit(g_errno);
	set_in(cmdli);
	set_out(cmdli);
}
