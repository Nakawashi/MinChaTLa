/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmdli.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 06:53:43 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/02 02:53:44 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	print_cmdli_tab(char **ss, char *s)
{
	if (!ss || !*ss)
		printf("%s = (null)\n", s);
	else
	{
		printf("%s = %s\n", s, *(ss++));
		while (*ss)
			printf("           %s\n", *(ss++));
	}
}

void	print_cmdli_files(t_file **files, char *s)
{
	if (!files)
		printf("%s = (null)\n", s);
	else
	{
		while (*files)
		{
			printf("%s type = %d\n", s, (*files)->type);
			printf("%s value = %s\n", s, (*files)->name);
			files++;
		}
	}
}

void	print_content(t_cmdli *cmds_list)
{
	printf("cmd = %s\n", cmds_list->cmd);
	print_cmdli_tab(cmds_list->cmd_args, "cmd_args");
	if (cmds_list->pipe_in)
		printf("pipe_in = yes\n");
	else
		printf("pipe_in = no\n");
	if (cmds_list->pipe_out)
		printf("pipe_out = yes\n");
	else
		printf("pipe_out = no\n");
	print_cmdli_tab(cmds_list->file_in, "file_in");
	print_cmdli_files(cmds_list->file_out, "file_out");
	printf("here_doc = %d\n", cmds_list->here_doc);
	printf("and_or = %d\n", cmds_list->and_or);
	printf("next = %p\n", cmds_list->next);
	printf("previous = %p\n", cmds_list->previous);
}

void	print_cmdli(t_cmdli *cmds_list)
{
	unsigned int	i;

	i = 0;
	printf("\nCMDLI :\n");
	if (!cmds_list)
	{
		printf("cmds_list = NULL\n");
		return ;
	}
	printf("\nnode %u :\n\n", ++i);
	print_content(cmds_list);
	while (cmds_list->next)
	{
		cmds_list = cmds_list->next;
		printf("\nnode %u :\n\n", ++i);
		print_content(cmds_list);
	}
}
