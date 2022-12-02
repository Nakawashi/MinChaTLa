/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_1_to_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrolle <hrolle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:32:36 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/12/02 01:06:09 by hrolle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_1(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "#w     ██       ██    ██    ██    ██    ██      ██████     ██    ██    ████████    ██          ██       \n");
	ft_printfd(1, "     ███     ███    ██    ███   ██    ██    ███    ██    ██    ██    ██     █    ██          ██       \n");
	ft_printfd(1, "     ████   ████    ██    ████  ██    ██    ███          ██    ██    ██          ██          ██       \n");
	ft_printfd(1, "     ██ ██ ██ ██    ██    ██ ██ ██    ██      █████      ████████    ██████      ██          ██       \n");
	ft_printfd(1, "     ██  ███  ██    ██    ██  ████    ██          ███    ██    ██    ██          ██          ██       \n");
	ft_printfd(1, "     ██   █   ██    ██    ██   ███    ██    ██    ███    ██    ██    ██     █    ██          ██       \n");
	ft_printfd(1, "     ██       ██    ██    ██    ██    ██     ██████      ██    ██    ████████    ████████    ████████ #0\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_2(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b█#w██   #b█#w██     #b█#w██████    #b█#w██   #b█#w██   #b█#w████████   #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w███    #b█#w███   #b█#w██   #b█#w███  #b█#w██   #b█#w██   #b█#w███   #b█#w██   #b█#w██   #b█#w██   #b█#w██    #b█#w█   #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w████  #b█#w████   #b█#w██   #b█#w████ #b█#w██   #b█#w██   #b█#w███         #b█#w██   #b█#w██   #b█#w██         #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██#b█#w██#b█#w██#b█#w██   #b█#w██   #b█#w██#b█#w██#b█#w██   #b█#w██     #b█#w█████     #b█#w████████   #b█#w██████     #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██ #b█#w███ #b█#w██   #b█#w██   #b█#w██ #b█#w████   #b█#w██         #b█#w███   #b█#w██   #b█#w██   #b█#w██         #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██  #b█#w█  #b█#w██   #b█#w██   #b█#w██  #b█#w███   #b█#w██   #b█#w██   #b█#w███   #b█#w██   #b█#w██   #b█#w██    #b█#w█   #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b█#w██   #b█#w██    #b█#w██████     #b█#w██   #b█#w██   #b█#w████████   #b█#w████████   #b█#w████████ \n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_3(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "     #w██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w     ██████#r█#w    ██#r█#w   ██#r█#w   ████████#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ███#r█#w    ███#r█#w   ██#r█#w   ███#r█#w  ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ████#r█#w  ████#r█#w   ██#r█#w   ████#r█#w ██#r█#w   ██#r█#w   ███#r█#w         ██#r█#w   ██#r█#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ██#r█#w██#r█#w██#r█#w   ██#r█#w     █████#r█#w     ████████#r█#w   ██████      ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w ███#r█#w ██#r█#w   ██#r█#w   ██#r█#w ████#r█#w   ██#r█#w         ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w  █#r█#w  ██#r█#w   ██#r█#w   ██#r█#w  ███#r█#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    ██████#r█#w     ██#r█#w   ██#r█#w   ████████#r█#w   ████████#r█#w   ████████#r█#w\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_4(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w█████#r█#w    #b█#w████████#r█#w  #b█#w██████     #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_5(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "  #b▀#w▀▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w  #b▀#w▀▀#p▀#w▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    #b▀#w▀▀▀▀▀#r▀#w    #b▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r▀#w    #b▀#w▀▀#r▀#w        #b▀#w▀▀#r▀#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}
