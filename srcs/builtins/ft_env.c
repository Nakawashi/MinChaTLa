/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:12:42 by lgenevey          #+#    #+#             */
/*   Updated: 2022/11/28 21:14:22 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

/*
	Displays env variables
	The order we see is when items are created
*/
int	ft_env(int fd)
{
	t_variable	*env;

	env = ft_get_env();
	if (!env)
		return (0);
	while (env)
	{
		if (!env->value)
			ft_printfd(fd, "%s\n", env->name);
		else
			ft_printfd(fd, "%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}
