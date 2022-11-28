/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:54 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/28 21:07:26 by hrolle           ###   ########.fr       */
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
	char	*read;
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
		read = readline(ft_prompt());
		if (read)
		{
			if (*read)
				add_history(read);
			cmdli = get_cmds(&read);
			if (cmdli)
			{
				cmdli_i = cmdli;
				while (cmdli_i)
				{
					if (!cmdli_i->cmd)
						no_cmd(cmdli_i);
					else if (is_builtin(cmdli_i) == 1 && !cmdli->pipe_in && !cmdli->pipe_out)
					{
						builtin_set_file(cmdli_i);
						exec_builtin(&cmdli_i, read);
					}
					else
						exec_cmd(cmdli_i, read);
					shell.if_sig = 0;//------------move to exec_cmd
					cmdli_i = cmdli_i->next;
				}
				//g_errno = wait_process(status);
				 while (wait(&status) != -1)
					if (WIFEXITED(status))
						g_errno = WEXITSTATUS(status);
				// g_errno = WEXITSTATUS(status);
				shell.if_sig = 1;
				free_cmdli(&cmdli);
			}
			free(read);
		}
		else
			ft_exit(NULL, NULL, 0);
	}
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
