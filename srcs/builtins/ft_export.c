/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:46:29 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/18 05:09:08 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	print la liste chainee stockee dans la struc shell.export
	print est different si on n'a pas de valeur (premier OLDPWD par exemple)
	pointeur null : pas les guillemets
	chaine vide : oui les guillemets
*/

static int	print_export(void)
{
	t_variable	*export;

	export = ft_get_export();
	if (export == NULL)
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


/*
	return 1 if c is not a valid identifier or doesnt content any =
	writes only once the message, not for every bad char
*/
// static int is_bad_arg(char *str, int *i, int first_time)
// {
// 	if (str[0] == '_')
// 	{
// 		++(*i);
// 		return (1);
// 	}
// 	if (!ft_isalpha(str[0]))
// 	{
// 		if (first_time)
// 		{
// 			ft_printfd(2, "export: `%s': not a valid identifier\n", str);
// 			first_time = 0;
// 		}
// 		++(*i);
// 		return (1);
// 		printf("coucou\n");
// 	}
// 	return (0);
// }

void	bigger(t_variable *prev, t_variable *new, t_variable **export, t_variable *current)
{
	if (prev)
		prev->next = new;
	else
		(*export) = new;
	new->next = current;
}

void	equal_fill(t_variable *prev, t_variable *new, t_variable **export, t_variable *current)
{
	if (prev)
		prev->next = new;
	else
		(*export) = new;
	new->next = current->next;
	free(current->name);
	free(current);
}

void	equal(t_variable *new, t_variable *current)
{
	if (!new->value)
		return ;
	if (current->value)
		free(current->value);
	current->value = new->value;
}

/*
	no  '='	: value is null
	yes '='	: value is empty string
*/
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

void	ft_export(t_cmdli *cmdli)
{
	t_shell			*shell;
	t_variable		*new;
	int				i;

	shell = ft_get_shell(NULL);
	new = NULL;
	if (cmdli->cmd_args[1])
	{
		i = 1;
		while (cmdli->cmd_args[i])
		{
			new = create_var_node(cmdli->cmd_args[i++]);
			if (!export_inset(new->name)
				|| (new->name[0] >= '0' && new->name[0] <= '9'))
			{
				free_content_node_and_print(cmdli, new, i);
			}
			else
			{
				replace_node(&shell->export, new);
				if (new->value)
					replace_node_env(shell->env, new);
			}
		}
	}
	else
		print_export();
}

// free dans export si value = NULL
// free dans env si la variable existe