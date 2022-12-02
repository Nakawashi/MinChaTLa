/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:00:06 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/02 01:25:00 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*add_var_free(char *str, char *new)
{
	char	*tmp;
	char	*ret;

	tmp = str;
	ret = NULL;
	if (!new)
	{
		if (tmp)
			free(tmp);
		return (NULL);
	}
	ret = ft_strjoin(str, new);
	free(new);
	if (tmp)
		free(tmp);
	if (!ret)
		return (NULL);
	return (ret);
}

char *split_variable_buff(char *var)
{
	char	*ret;

	ret = NULL;
	if (!var || !*var || (*var == '$' && !*(var + 1)))
		return (var);
	if (*var != ' ')
	{
		ret = ft_strdup("");
	}
	return (ret);
}

// char	*add_var_free_parse(char *str, char *new)
// {
// 	char	*tmp;
// 	char	*ret;

// 	tmp = str;
// 	ret = NULL;
// 	if (!new)
// 	{
// 		if (tmp)
// 			free(tmp);
// 		return (NULL);
// 	}
// 	ret = ft_strjoin(str, new);
// 	free(new);
// 	if (tmp)
// 		free(tmp);
// 	if (!ret)
// 		return (NULL);
// 	return (ret);
// }

char	*add_home(char **cmdline, unsigned int *i)
{
	++*i;
	return (ft_get_var("HOME"));
}

char	*add_var(char **cmdline, char *str, unsigned int *i)
{
	unsigned int	j;
	char			*new;
	char			*tmp;

	j = 0;
	++*i;
	while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != '$' && (*cmdline)[*i + j]
		!= ' ' && (*cmdline)[*i + j] != '<' && (*cmdline)[*i + j]
		!= '>' && (*cmdline)[*i + j] != '|' && (*cmdline)[*i + j]
		!= '&' && (*cmdline)[*i + j] != '\'' && (*cmdline)[*i + j] != '"')
		j++;
	if (j)
	{
		tmp = ft_substr((*cmdline), *i, j);
		new = ft_get_var(tmp);
		if (tmp)
			free(tmp);
	}
	else if ((*cmdline)[*i] != '"' && (*cmdline)[*i] != '\'')
		new = ft_strdup("$");
	else
		new = ft_strdup("");
	*i += j;
	return (add_var_free(str, new));
}

char	*add_var_parse(char **cmdline, char *str, unsigned int *i)
{
	unsigned int	j;
	char			*new;
	char			*tmp;

	j = 0;
	++*i;
	while ((*cmdline)[*i + j] && (*cmdline)[*i + j] != '$' && (*cmdline)[*i + j]
		!= ' ' && (*cmdline)[*i + j] != '<' && (*cmdline)[*i + j]
		!= '>' && (*cmdline)[*i + j] != '|' && (*cmdline)[*i + j]
		!= '&' && (*cmdline)[*i + j] != '\'' && (*cmdline)[*i + j] != '"')
		j++;
	if (j)
	{
		tmp = ft_substr((*cmdline), *i, j);
		new = ft_get_var(tmp);
		if (tmp)
			free(tmp);
	}
	else if ((*cmdline)[*i] != '"' && (*cmdline)[*i] != '\'')
		new = ft_strdup("$");
	else
		new = ft_strdup("");
	*i += j;
	return (add_var_free(str, split_variable_buff(new)));
}
