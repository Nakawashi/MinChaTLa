/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:25:54 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/02 02:33:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/minishell.h"
#include "printfd/HEADER/ft_printfd.h"
#include <stdio.h>

/*
	while (wait(&status) != -1)
		if (WIFEXITED(status))
			g_errno = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_errno = WTERMSIG(status);
*/
// int	main(int ac, char **av, char **env)
// {
// 	t_shell	shell;
// 	t_cmdli	*cmdli;
// 	t_cmdli	*cmdli_i;
// 	int		status;

// 	status = 0;
// 	ft_get_shell(&shell);
// 	init_shell(&shell, env);
// 	if (ac > 1)
// 		shell.say = 1;
// 	else
// 		shell.say = 0;
// 	print_minishell();
// 	(void)av;
// 	term_handler(&shell);
// 	signal(SIGQUIT, SIG_IGN); // NE PAS SUPPRIMER
// 	sig_mode(1);
// 	while (true)
// 	{
// 		shell.read = readline(ft_prompt());
// 		if (shell.read)
// 		{
// 			if (shell.read[0])
// 				add_history(shell.read);
// 			cmdli = get_cmds(&shell.read);
// 			//print_cmdli(cmdli);
// 			if (cmdli)
// 			{
// 				cmdli_i = cmdli;
// 				while (cmdli_i)
// 				{
// 					sig_mode(1);
// 					if (!cmdli_i->cmd)
// 						no_cmd(cmdli_i);
// 					else if (cmdli_i->pipe_in || cmdli_i->pipe_out)
// 						is_builtin(&cmdli_i, 1);
// 					else
// 						is_builtin(&cmdli_i, 0);
// 					sig_mode(0);
// 					cmdli_i = cmdli_i->next;
// 				}
// 				while (wait(&status) != -1)
// 					if (WIFEXITED(status))
// 						g_errno = WEXITSTATUS(status);
// 				else if (WIFSIGNALED(status))
// 					g_errno = WTERMSIG(status);
// 				if (WIFSIGNALED(status))
// 					write(1, "\n", 1);
// 				sig_mode(1);
// 				free_cmdli(&cmdli);
// 			}
// 			free(shell.read);
// 		}
// 		else
// 			ft_sig_exit();
// 	}
// 	free_nodes_contents(&shell.export);
// 	free_nodes(&shell.env);
// 	return (0);
// }

void	ft_norme(t_cmdli *cmdli, int status)
{
	t_cmdli	*cmdli_i;

	cmdli_i = cmdli;
	while (cmdli_i)
	{
		sig_mode(1);
		if (!cmdli_i->cmd)
			no_cmd(cmdli_i);
		else if (cmdli_i->pipe_in || cmdli_i->pipe_out)
			is_builtin(&cmdli_i, 1);
		else
			is_builtin(&cmdli_i, 0);
		sig_mode(0);
		cmdli_i = cmdli_i->next;
	}
	while (wait(&status) != -1)
		if (WIFEXITED(status))
			g_errno = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_errno = WTERMSIG(status);
	if (WIFSIGNALED(status))
		write(1, "\n", 1);
	sig_mode(1);
	free_cmdli(&cmdli);
}

void	ft_say_check(int ac, t_shell *shell)
{
	if (ac > 1)
		shell->say = 1;
	else
		shell->say = 0;
}

void	ft_norme2(t_shell *shell, t_cmdli *cmdli, int status)
{
			if (shell->read[0])
				add_history(shell->read);
			cmdli = get_cmds(&shell->read);
			//print_cmdli(cmdli);
			if (cmdli)
				ft_norme(cmdli, status);
			free(shell->read);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	t_cmdli	*cmdli;
	int		status;

	status = 0;
	ft_get_shell(&shell);
	init_shell(&shell, env);
	ft_say_check(ac, &shell);
	print_minishell();
	(void)av;
	term_handler(&shell);
	signal(SIGQUIT, SIG_IGN); // NE PAS SUPPRIMER
	sig_mode(1);
	while (true)
	{
		shell.read = readline(ft_prompt());
		if (shell.read)
			ft_norme2(&shell, cmdli, status);
		else
			ft_sig_exit();
	}
	free_nodes_contents(&shell.export);
	free_nodes(&shell.env);
	return (0);
}
