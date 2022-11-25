/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:33:17 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/25 14:35:27 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	returns 1 if c is not a valid identifier or doesnt content any =
	writes only once the message, not for every bad char
*/
int	check_non_authorized_names(char *str, int *i)
{
	if (str[0] == '_' || str[0] == '#')
	{
		++(*i);
		return (1);
	}
	if (!ft_isalpha(str[0]))
	{
		ft_printfd(2, "export: `%s': not a valid identifier\n", str);
		g_errno = 1;
		++(*i);
		return (1);
	}
	return (0);
}

void	free_content_node_and_print(t_cmdli *cmdli, t_variable *new, int i)
{
	if (ft_strcmp(cmdli->cmd_args[i], "=") != 0)
	{
		ft_printfd(2, "#+wminishell#0: export: `%s': #/r%s#0\n",
			cmdli->cmd_args[i], "not a valid identifier");
	}
	free(new->name);
	free(new->value);
	free(new);
	g_errno = 1;
}

/*
	print la liste chainee stockee dans la struc shell.export
	print est different si on n'a pas de valeur (premier OLDPWD par exemple)
	pointeur null : pas les guillemets
	chaine vide : oui les guillemets
	no  '='	: value is null
	yes '='	: value is empty string
*/
int	print_export(void)
{
	t_variable	*export;

	export = ft_get_export();
	if (!export)
		return (0);
	while (export)
	{
		if (!export->value)
			printf("declare -x %s\n", export->name);
		else
			printf("declare -x %s=\"%s\"\n", export->name, export->value);
		export = export->next;
	}
	return (1);
}
