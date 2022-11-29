/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:46:34 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/29 19:11:05 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	handle ctrl + C (interruption) when cmd = done
*/
void	handle_interrupt(int sig)
{
	t_shell	*shell;

	write(1, "\n", 1);
	shell = ft_get_shell(NULL);
	if (sig == SIGINT && shell->if_sig)
	{
		ft_print_prompt();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_errno = 1;
	}
	else if (sig == SIGINT && !shell->if_sig)
		g_errno = 128 + sig;
}

/*
	handle ctrl + \
	no ^C with ECHOCTL option
*/
void	sig_handler(t_shell *shell)
{
	struct termios	term_flag;

	tcgetattr(0, &term_flag);
	term_flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term_flag);
	sigaction(SIGINT, &shell->sa_interrupt, NULL);
	sigaction(SIGQUIT, &shell->sa_backslash, NULL);
}
