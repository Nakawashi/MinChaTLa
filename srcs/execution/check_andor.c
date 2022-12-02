/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_andor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:35:59 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/12/02 15:59:00 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

int	andor_while_check(t_cmdli **cmdli)
{
	while ((*cmdli) && (g_errno && (*cmdli)->and_or == 1)
		|| (!g_errno && (*cmdli)->and_or == 2))
	{
		if ((*cmdli)->pipe_in && (*cmdli)->pipe_in[0] == -1
			&& (*cmdli)->pipe_in[0] == -1)
			close_pipe((*cmdli)->pipe_in);
		(*cmdli)->previous = (*cmdli);
		(*cmdli) = (*cmdli)->next;
		while ((*cmdli) && !(*cmdli)->and_or)
		{
			if ((*cmdli)->pipe_in && (*cmdli)->pipe_in[0] == -1
				&& (*cmdli)->pipe_in[0] == -1)
				close_pipe((*cmdli)->pipe_in);
			(*cmdli)->previous = (*cmdli);
			(*cmdli) = (*cmdli)->next;
		}
		if (!(*cmdli))
			return (1);
	}
	if (!(*cmdli))
		return (1);
	return (0);
}

int	andor_check(t_cmdli **cmdli)
{
	int	status;

	status = 0;
	if (!(*cmdli)->and_or)
		return (0);
	sig_mode(0);
	while (wait(&status) != -1)
		if (WIFEXITED(status))
			g_errno = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_errno = WTERMSIG(status);
	if (status && WIFSIGNALED(status))
		write(1, "\n", 1);
	sig_mode(1);
	if (andor_while_check(cmdli))
		return (1);
	return (0);
}
