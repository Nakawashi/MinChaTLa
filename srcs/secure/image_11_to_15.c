/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_11_to_15.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:32:36 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/11/19 00:10:23 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_11(int back)
{
	ft_printfd(1, "                                                                                    #b█#w██#r█#w              \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w              #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "  #b▄#w▄▄#p▄#w▄▄▄▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w  #b▄#w▄▄#p▄#w▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w    #b▄#w▄▄▄▄▄#r▄#w    #b▄#w▄▄▄▄▄▄▄▄#r▄#w  #b▄#w▄▄▄▄▄▄#r▄#w    #b▄#w▄▄#r▄#w        #b▄#w▄▄#r▄#w      \n");
	ft_printfd(1, "     #b█#w██#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "             #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "#b█#w██#r█#w                                                                                                  \n");
	if (back)
		back_to_the_future();
}

void	image_12(int back)
{
	ft_printfd(1, "       #b█#w██      #b█#w██   #b█#w██   #b█#w██   #b█#w██   #b█#w██     #b█#w██████    #b█#w██   #b█#w██   #b█#w████████   #b█#w██         #b█#w██     \n");
	ft_printfd(1, "                                                                                                      \n");
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

void	image_13(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "     #w██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w     ██████#r█#w    ██#r█#w   ██#r█#w   ████████#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ███#r█#w    ███#r█#w   ██#r█#w   ███#r█#w  ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ██#r█#w██#r█#w██#r█#w   ██#r█#w     █████#r█#w     ████████#r█#w   ██████      ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ████#r█#w  ████#r█#w   ██#r█#w   ████#r█#w ██#r█#w   ██#r█#w   ███#r█#w         ██#r█#w   ██#r█#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w ███#r█#w ██#r█#w   ██#r█#w   ██#r█#w ████#r█#w   ██#r█#w         ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w  █#r█#w  ██#r█#w   ██#r█#w   ██#r█#w  ███#r█#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    █#r█#w   ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, " ██#r█#w      ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    ██████#r█#w     ██#r█#w   ██#r█#w   ████████#r█#w   ████████#r█#w   ████████#r█#w    \n");
	if (back)
		back_to_the_future();
}

void	image_14(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "   #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "       #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w█████#r█#w    #b█#w████████#r█#w  #b█#w██████     #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "  #b█#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_15(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w    #b█#w██████#r█#w   #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "  #b█#w███#r█#w   #b█#w███#r█#w  #b█#w██#r█#w  #b█#w███#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w████#r█#w #b█#w████#r█#w  #b█#w██#r█#w  #b█#w████#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "     #b█#w██#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w██#r█#w        #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w██████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "      #b▀#w▀▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w  #b▀#w▀▀#p▀#w▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    #b▀#w▀▀▀▀▀#r▀#w    #b▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r▀#w    #b▀#w▀▀#r▀#w        #b▀#w▀▀#r▀#w      \n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}
