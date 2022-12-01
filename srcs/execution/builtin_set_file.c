/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_set_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:55:15 by hrolle            #+#    #+#             */
/*   Updated: 2022/11/29 20:01:38 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

int	builtin_set_file(t_cmdli *cmdli)
{
	if (cmdli->file_out)
	{
		if (set_file_out(cmdli))
			return (1);
	}
	else
		cmdli->fd_out = 1;
	if (cmdli->file_in)
		if (set_file_in(cmdli))
			return (1);
	return (0);	
}
