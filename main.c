/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:54 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/29 18:28:21 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	t_cmdli	*cmdli;
	t_cmdli	*cmdli_i;
	int		status;

	status = 0;
	ft_get_shell(&shell);
	init_shell(&shell, env);
	if (ac > 1)
		shell.say = 1;
	else
		shell.say = 0;
	//print_minishell();
	(void)av;
	sig_handler(&shell);
	while (true)
	{
		shell.read = readline(ft_prompt());
		if (shell.read)
		{
			if (shell.read[0])
				add_history(shell.read);
			cmdli = get_cmds(&shell.read);
			//print_cmdli(cmdli);
			if (cmdli)
			{
				cmdli_i = cmdli;
				while (cmdli_i)
				{
					if (!cmdli_i->cmd)
						no_cmd(cmdli_i);
					else if (cmdli_i->pipe_in || cmdli_i->pipe_out)
						is_builtin(&cmdli_i, 1);
					else
						is_builtin(&cmdli_i, 0);
					shell.if_sig = 0;//------------move to exec_cmd
					cmdli_i = cmdli_i->next;
				}

				while (wait(&status) != -1)
					if (WIFEXITED(status))
						g_errno = WEXITSTATUS(status);
				// g_errno = WEXITSTATUS(status);
				shell.if_sig = 1;
				free_cmdli(&cmdli);
			}
			free(shell.read);
		}
		else
			ft_sig_exit();
	}
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
