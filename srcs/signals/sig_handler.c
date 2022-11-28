/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:46:34 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/28 20:48:48 by hrolle           ###   ########.fr       */
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

	shell = ft_get_shell(NULL);
	if (sig == SIGINT && shell->if_sig)
	{
		write(1, "\n", 1);
		ft_print_prompt();
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
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
