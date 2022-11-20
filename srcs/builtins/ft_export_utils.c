/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:33:17 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/18 20:37:57 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	Incorrect char cases for ft_export
	if first char is :
	a number
	is '='
	not a letter (min, maj)
	other chars
*/
int	export_inset(char *s)
{
	if (!s)
		return (0);
	if ((*s >= '0' && *s <= '9') || (*s == '='))
		return (0);
	while (*s)
	{
		if (*s != '_'
			&& (*s < 'a' || *s > 'z')
			&& (*s < 'A' || *s > 'Z')
			&& (*s < '0' || *s > '9'))
			return (0);
			s++;
	}
	return (1);
}

void	free_content_node_and_print(t_cmdli *cmdli, t_variable *new, int i)
{
	if (ft_strcmp(new->name, "="))
	{
		ft_printfd(2, "#+wminishell#0: export: `%s': #/r%s#0\n",
			cmdli->cmd_args[i], "not a valid identifier");
	}
	free(new->name);
	free(new->value);
	free(new);
	g_errno = 1;
}
