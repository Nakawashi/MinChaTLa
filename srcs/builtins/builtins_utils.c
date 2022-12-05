/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:52:41 by lgenevey          #+#    #+#             */
/*   Updated: 2022/12/05 12:25:32 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_and_free_new_value(t_variable *current, t_variable *new)
{
	current->value = new->value;
	free(new->name);
	free(new);
}

/*
	parcourir env, si variable deja existante alors la remplacer
	autrement ajouter le nouveau noeud a la fin
*/
void	replace_node_env(t_variable **env, t_variable *new)
{
	t_variable	*current;
	t_variable	*prev;

	prev = NULL;
	if (!*env)
	{
		*env = malloc(sizeof(t_variable));
		(*env)->name = new->name;
		(*env)->value = new->value;
		(*env)->next = NULL; // <---------
		return ;
	}
	current = *env;
	while (current)
	{
		if (!ft_strcmp(current->name, new->name))
			return (add_and_free_new_value(current, new));
		prev = current;
		current = current->next;
	}
	prev->next = (t_variable *)malloc(sizeof(t_variable));
	if (prev->next)
	{
		prev->next->next = NULL;
		prev->next->name = new->name;
		prev->next->value = new->value;
	}
}

/*
	parcourir export, si variable deja existante alors la remplacer
	autrement ajouter le nouveau noeud au bon endroit selon le tri insertion
*/
void	replace_node(t_variable **export, t_variable *new)
{
	t_variable	*prev;
	t_variable	*current;
//	static int	i;

	prev = NULL;
	current = *export;
	//i++;
	if (!*export)
	{
		*export = new;
		return ;
	}
	while (current)
	{
		if (!put_node(export, current, prev, new))
			return ;
		prev = current;
		current = current->next;
	}
	if (!current)
		prev->next = new;
}
