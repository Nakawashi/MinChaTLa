/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgenevey <lgenevey@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/20 12:17:45 by lgenevey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

/*
	print a list from a copy pointer
*/
static void	printlist()
{
	t_variable	*env;

	env = ft_get_env();
	if (!env)
		return ;
	while (env)
	{
		if (!env->value)
			printf("%s\n", env->name);
		else
			printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
}

/*
	Displays env variables
	The order we see is when items are created
*/
int	ft_env(void)
{
	printlist();
	return (1);
}
