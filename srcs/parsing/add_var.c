/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 07:00:06 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/02 04:47:05 by hrolle           ###   ########.fr       */
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

unsigned int	sp_strlen(char *s)
{
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != ' ')
		++i;
	return (i);
}

char	*get_split_var_line(char *s, unsigned int *i)
{
	unsigned int	j;
	char			*ret;

	if (!s)
		return (NULL);
	ret = malloc((sp_strlen(s) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = 0;
	while (s[*i] && s[*i] != ' ')
		ret[j++] = s[*i++];
	ret[j] = 0;
	return (ret);
}

char	*split_var_buff(char **cmdline, char *var, unsigned int *i)
{
	char			*ret;
	unsigned int	j;

	if (!var || !*var || (*var == '$' && !*(var + 1)))
		return (var);
	ret = NULL;
	j = 0;
	if (*var != ' ')
		ret = get_split_var_line(var, &i);
	if (var[j])
	{
		while (var[j] && var[j] == ' ')
			j++;
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
	while (ft_is_alphanum_((*cmdline)[*i + j]))
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
	while (ft_is_alphanum_((*cmdline)[*i + j]))
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
	return (add_var_free(str, split_var_buff(new)));
}
