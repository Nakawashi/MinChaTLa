/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:46:29 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 11:12:40 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

static void	bigger(t_variable *prev, t_variable *new,
	t_variable **export, t_variable *current)
{
	if (prev)
		prev->next = new;
	else
		(*export) = new;
	new->next = current;
}

static void	equal_fill(t_variable *prev, t_variable *new,
	t_variable **export, t_variable *current)
{
	if (prev)
		prev->next = new;
	else
		(*export) = new;
	new->next = current->next;
	free(current->name);
	free(current);
}

static void	equal(t_variable *new, t_variable *current)
{
	if (!new->value)
		return ;
	if (current->value)
		free(current->value);
	current->value = new->value;
}

int	put_node(t_variable **export, t_variable *current,
			t_variable *prev, t_variable *new)
{
	int	cmp_ret;

	cmp_ret = ft_strcmp(current->name, new->name);
	if (cmp_ret > 0)
	{
		bigger(prev, new, export, current);
		return (0);
	}
	if (!cmp_ret && !current->value)
	{
		equal_fill(prev, new, export, current);
		return (0);
	}
	if (!cmp_ret)
	{
		equal(new, current);
		return (0);
	}
	return (1);
}

void	ft_export(t_cmdli **cmdli)
{
	t_shell		*shell;
	t_variable	*new;
	int			i;

	g_errno = 0;
	shell = ft_get_shell(NULL);
	new = NULL;
	if ((*cmdli)->cmd_args[1] && (*cmdli)->cmd_args[1][0] != '#')
	{
		i = 1;
		while ((*cmdli)->cmd_args[i])
		{
			if (check_non_authorized_names((*cmdli)->cmd_args[i], &i))
				continue ;
			new = create_var_node((*cmdli)->cmd_args[i++]);
			replace_node(&shell->export, new);
			if (new->value)
				replace_node_env(shell->env, new);
		}
	}
	else
		print_export(cmdli);
}
