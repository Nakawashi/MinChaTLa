/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:33:17 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/20 14:20:03 by lgenevey         ###   ########.fr       */
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
	if ((*s >= '0' && *s <= '9'))
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

/*
	returns 1 if c is not a valid identifier or doesnt content any =
	writes only once the message, not for every bad char
*/
int	check_non_authorized_values(char *str, int *i)
{
	if (str[0] == '_') // if _ just ignore
	{
		++(*i);
		return (1);
	}
	if (!ft_isalpha(str[0]))
	{
		ft_printfd(2, "export: `%s': not a valid identifier\n", str);
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
