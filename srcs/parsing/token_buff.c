/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:41:16 by hrolle            #+#    #+#             */
/*   Updated: 2022/12/01 23:41:39 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

char	*token_buff(char *new_token)
{
	static t_slist	*toli;
	t_slist			*current_toli;
	t_slist			*tmp;
	char			*ret;

	current_toli = toli;
	if (new_token)
	{
		if (!toli)
		{
			toli = malloc(1 * sizeof(t_slist));
			if (!toli)
				return (NULL);
			toli->next = NULL;
			toli->str = new_token;
		}
		else
		{
			while (current_toli->next)
				current_toli = current_toli->next;
			current_toli->next = malloc(1 * sizeof(t_slist));
			if (!current_toli->next)
				return (NULL);
			current_toli = current_toli->next;
			current_toli->next = NULL;
			current_toli->str = new_token;
		}
	}
	else
	{
		if (!toli)
			return (NULL);
		tmp = toli;
		ret = toli->str;
		toli = toli->next;
		free(tmp);
		return (ret);
	}
	return (NULL);
}
