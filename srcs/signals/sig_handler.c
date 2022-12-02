/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 17:46:34 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/01 23:25:46 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	handle_interrupt(int sig)
{
	if (sig != SIGINT)
		return ;
	write(1, "\n", 1);
	ft_print_prompt();
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
	mode = 0 for SIG_IGN (for childs)
	mode = 1 for SIG_DFL but custom
*/
void	sig_mode(int mode)
{
	if (!mode)
		signal(SIGINT, SIG_IGN);
	else if (mode == 1)
		signal(SIGINT, &handle_interrupt);
	else
		signal(SIGINT, SIG_DFL);
}

/*
	init term
	no ^C with ECHOCTL option
	applies settings now
*/
void	term_handler(t_shell *shell)
{
	struct termios	term_flag;

	tcgetattr(0, &term_flag);
	term_flag.c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &term_flag);
}
