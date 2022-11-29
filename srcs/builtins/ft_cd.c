/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:09:31 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/28 23:14:38 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	creates new node with name and value mallocated
	replace node in export
	if new node has value, replace node in env
*/
void	update_node(char *name, char *value)
{
	t_shell		*shell;
	t_variable	*node;

	shell = ft_get_shell(NULL);
	node = malloc(sizeof(t_variable));
	if (!node)
		return ;
	node->name = ft_strdup(name);
	node->value = ft_strdup(value);
	node->next = NULL;
	replace_node(&shell->export, node);
	if (node->value)
		replace_node_env(shell->env, node);
}

/*
	getcwd : Get the current working directory
	chdir : change current dir, returns 0 if success
	Must update OLDPWD variable at first use of cd
	Must update PWD variable after chdir
*/
int	ft_cd(char *str, int fd)
{
	char	*new_path;
	char	*actual_path;
	char	buff[PATH_MAX];

	actual_path = getcwd(buff, PATH_MAX);
	update_node("OLDPWD", actual_path);
	new_path = NULL;
	if (!str)
		new_path = ft_get_var("HOME");
	else if (str)
		new_path = ft_strdup(str);
	if (!chdir(new_path))
	{
		if (new_path)
			free(new_path);
		new_path = getcwd(buff, PATH_MAX);
		update_node("PWD", new_path);
	}
	else
	{
		if (new_path)
			free(new_path);
		ft_printfd(fd, "cd: %s: %s\n", strerror(errno), str);
		g_errno = 1;
	}
	g_errno = 0;
	return (g_errno);
}
