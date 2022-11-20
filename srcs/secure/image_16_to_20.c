/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_16_to_20.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hermesrolle <hermesrolle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:32:36 by hermesrolle       #+#    #+#             */
/*   Updated: 2022/11/19 01:16:52 by hermesrolle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
#include "../../printfd/HEADER/ft_printfd.h"

void	image_16(int back)
{
	ft_printfd(1, "                                                        ");
	ft_printfd(1, "                                              \n");
	ft_printfd(1, "      #b░#w▒░#r█#w     #b█#w░▒#r█#w  #b█#w▒█#r█#w  #b█#w");
	ft_printfd(1, "░░#r░#w  #b█#w██#r█#w  #b█#w█▒#r▒#w    #b░#w░░▒██#r█#w   ");
	ft_printfd(1, "#b█#w█▒#r▒#w  #b█#w▒#r▒#w  #b█#w░░███░░█#r█#w  #b█#w██#r█");
	ft_printfd(1, "#w        #b█#w█▒#r░#w      \n");
	ft_printfd(1, "    #b█#w█▒#r▒#w   #b█#w█░░#r█#w  #b░#w░▒#r█#w  #b█#w▒██");
	ft_printfd(1, "#r█#w #b░#w░░#r░#w  #b█#w█▒#r▒#w  #b█#w███#r█#w  #b█#w░█");
	ft_printfd(1, "#r░#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b█#w▒");
	ft_printfd(1, "#r░#w  #b█#w▒#r▒#w        #b▒#w█░#r░#w      \n");
	ft_printfd(1, "    #b░#w░░██#r█#w #b█#w▒██#r█#w  #b█#w██#r█#w  #b█#w█░░");
	ft_printfd(1, "█#r█#w#b█#w██#r█#w  #b▒#w██#r▒#w  #b░#w░░░#r░#w        #b");
	ft_printfd(1, "█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b░#w░█#r█");
	ft_printfd(1, "#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "     #b░#w░░#r░#w#b█#w██░#r█#w#b█#w██#r█#w  #b█#w░░#r█#w");
	ft_printfd(1, "  #b█#w█░#r█#w#b█#w░░██#r█#w  #b█#w█░#r█#w        #b█#w█▒");
	ft_printfd(1, "░#r█#w  #b█#w░█#r█#w  #b█#w██#r█#w  #b█#w█▒#r▒#w        #b");
	ft_printfd(1, "█#w██#r█#w        #b█#w▒#r▒#w      \n");
	ft_printfd(1, "     #b░#w░░#r░#w #b▒#w█#r█#w #b█#w██#r█#w  #b█#w█▒#r█#w");
	ft_printfd(1, "  #b░#w▒#r█#w #b█#w▒██#r█#w  #b█#w██#r█#w  #b█#w▒#r█#w  ");
	ft_printfd(1, "#b█#w░░█#r█#w  #b█#w░░#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   ");
	ft_printfd(1, "#b█#w█#r█#w  #b█#w▒█#r█#w        #b░#w░▒#r▒#w      \n");
	ft_printfd(1, "   #b░#w░░#r░#w     #b█#w█░#r░#w  #b█#w▒#r█#w  #b█#w██#r");
	ft_printfd(1, "░#w  #b█#w▒#r█#w  #b█#w██#r█#w   #b█#w█░░▒█▒#r▒#w    #b█");
	ft_printfd(1, "#w██#r█#w  #b█#w██#r█#w  #b█#w▒███▒#r▒#w  #b▒#w▒█████▒#r▒");
	ft_printfd(1, "#w  #b█#w░▒██░░#r█#w\n");
	ft_printfd(1, "                                                        ");
	ft_printfd(1, "                                              \n");
	ft_printfd(1, "  #b▄#w▄▄#p▄#w▄▄▄▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w  #b▄#w▄▄#p");
	ft_printfd(1, "▄#w▄▄#p▄#w▄▄#r▄#w  #b▄#w▄▄#r▄#w    #b▄#w▄▄▄▄▄#r▄#w    #b▄");
	ft_printfd(1, "#w▄▄▄▄▄▄▄▄#r▄#w  #b▄#w▄▄▄▄▄▄#r▄#w    #b▄#w▄▄#r▄#w        ");
	ft_printfd(1, "#b▄#w▄▄#r▄#w      \n");
	if (back)
		back_to_the_future();
}

void	image_17(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b█#w░░      #b░#w██   #b░#w██   #b█#w██   #b▒#w█▒   #b█#w██     #b█#w░░███▒    #b█#w█▒   #b░#w░█   #b█#w█░░██▒░░   #b░#w░░         #b░#w██       \n");
	ft_printfd(1, "    #b█#w██░    #b░#w▒█▒   #b░#w██   #b█#w░░█  #b█#w▒█   #b█#w██   #b█#w░░█   #b░#w██   #b█#w██   #b█#w██   #b█#w█▒    #b█#w█   #b█#w▒         #b█#w█░       \n");
	ft_printfd(1, "      #b█#w███░  #b█#w░▒█   #b░#w██   #b█#w▒███ #b█#w▒█   #b█#w██   #b█#w█░░         #b░#w██   #b█#w██   #b█#w██         #b█#w██         #b█#w░█       \n");
	ft_printfd(1, "    #b▒#w▒█#b█#w██#b█#w██#b█#w▒   #b█#w██   #b█#w██#b█#w██#b█#w██   #b█#w██     #b█#w▒██     #b▒#w▒█████░░   #b█#w░░▒███     #b█#w█▒         #b█#w█░       \n");
	ft_printfd(1, "  #b▒#w██ #b█#w███ #b█#w██   #b█#w░░   #b█#w██ #b█#w░███   #b░#w░█         #b█#w███   #b█#w██   #b▒#w▒█   #b░#w░█         #b█#w██         #b█#w██       \n");
	ft_printfd(1, "    #b▒#w░░  #b█#w█  #b█#w██   #b█#w██   #b█#w██  #b█#w▒   #b░#w░█   #b█#w██   #b▒#w▒██   #b█#w██   #b░#w██   #b█#w██    #b█#w█   #b█#w░░         #b▒#w▒       \n");
	ft_printfd(1, "    #b▒#w░░      #b█#w██   #b█#w██   #b█#w██   #b█#w▒█   #b▒#w▒█    #b█#w░░██░░     #b▒#w▒   #b░#w░░   #b█#w░░▒███▒   #b█#w░░███▒█   #b█#w▒████░░ \n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_18(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "        ▒░░#r█#w    ▒█#r▒#w   █▒#r█#w   █░░#r█#w  ██#r█#w   ██#r█#w   ██░#r█#w   █░#r█#w   ██#r█#w   ██#r█#w   ▒░#r░#w    ░#r█#w   ██#r█#w         ▒#r░#w      \n");
	ft_printfd(1, "        #w░░#r▒#w      █░#r░#w   ██#r█#w   ██#r█#w   ██#r█#w   ██#r█#w     ░░░██░#r█#w    ██#r█#w   ░░#r█#w   ░▒███░░#r█#w   ██#r█#w         ░░#r█#w      \n");
	ft_printfd(1, "      █░#r░#w██#r█#w██#r█#w██#r█#w   ██#r█#w   ██#r█#w██#r█#w██#r█#w   ██#r█#w     ▒░▒░#r█#w     ░░▒████#r▒#w   ░░████      ░░#r█#w         █░#r░#w      \n");
	ft_printfd(1, "     ▒░░#r█#w  ▒█░░#r▒#w   █▒#r█#w   █░░░#r█#w ██#r█#w   ░░#r█#w   ░██#r█#w         ▒█#r█#w   ░░#r█#w   ██#r█#w         ██#r█#w         ██#r█#w      \n");
	ft_printfd(1, "     ██#r█#w ░██#r█#w ██#r█#w   ██#r░#w   █░#r█#w █░██#r█#w   ░░#r█#w         ██░#r█#w   ██#r█#w   ██#r█#w   ██#r█#w         ██#r█#w         █░#r░#w      \n");
	ft_printfd(1, "      ░░#r░#w  █#r█#w  ██#r█#w   ██#r░#w   ██#r█#w  ███#r▒#w   ██#r█#w   ██#r█#w   ███#r█#w   ██#r█#w   ██#r█#w   ██#r█#w    ░#r░#w   ░█#r█#w         ░░#r█#w      \n");
	ft_printfd(1, "     ██#r█#w      ██#r█#w   ▒█#r▒#w   ██#r▒#w   ██#r▒#w   ▒#r▒#w    ░░██░░#r█#w     ░█#r░#w   ██#r░#w   ░░██▒░░#r░#w   ░░▒████▒#r░#w   ░░▒███░#r░#w\n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}

void	image_19(int back)
{
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "  #b░#w█░#r░#w     #b█#w██#r░#w  #b█#w██#r░#w  #b█#w█░#r█#w  #b█#w█░#r░#w  #b░#w█░#r█#w    #b░#w░████░#r█#w   #b█#w██#r█#w  #b█#w░░#r█#w  #b█#w░░████░░#r█#w  #b░#w░█#r░#w        #b░#w░█#r░#w      \n");
	ft_printfd(1, "    #b░#w░░#p█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w  #b█#w██#p█#w██#p█#w██#r█#w  #b█#w██#r█#w    #b█#w░░███#r█#w    #b█#w░░░█████#r█#w  #b█#w░████░     #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b░#w██░#r░#w   #b█#w░░█#r░#w  #b█#w█░#r█#w  #b█#w██░#r█#w #b█#w█░#r░#w  #b░#w██#r░#w  #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w░░#r█#w   #b░#w░#r░#w  #b█#w██#r█#w        #b█#w██#r░#w      \n");
	ft_printfd(1, "   #b░#w████#r░#w #b█#w░░██#r█#w  #b█#w██#r░#w  #b█#w░░██#r█#w#b█#w█░#r░#w  #b█#w██#r░#w  #b█#w███#r█#w        #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "   #b░#w░░#r█#w#b█#w███#r█#w#b█#w██#r█#w  #b█#w█░#r█#w  #b█#w██#r█#w#b█#w░░██#r█#w  #b█#w██#r█#w        #b█#w░░░#r░#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w        #b█#w██#r█#w        #b█#w░░#r█#w      \n");
	ft_printfd(1, "    #b░#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b░#w█░#r█#w   #b█#w░░██░░#r█#w    #b█#w░░#r█#w  #b░#w░█#r█#w  #b█#w█░░███░░#r█#w  #b█#w░░██████#r█#w  #b█#w░░████░░#r█#w\n");
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "    #b░#w██#r█#w #b█#w█#r░#w #b█#w██#r█#w  #b█#w██#r█#w  #b█#w█░#r░#w #b█#w███#r█#w  #b█#w██#r█#w  #b█#w██#r█#w  #b░#w░░█#r█#w  #b░#w░█#r█#w  #b█#w░░#r█#w  #b█#w██#r█#w   #b█#w█#r█#w  #b█#w██#r█#w        #b█#w░░#r█#w      \n");
	if (back)

		back_to_the_future();
}

void	image_20(int back)
{
	ft_printfd(1, "        #b░#w██#r█#w     #b█#w██#r░#w  #b█#w░░#r░#w  #b█#w██#r█#w  #b█#w░█#r█#w  #b█#w█░#r█#w    #b░#w░░████#r█#w   #b█#w░█#r█#w  #b█#w░█#r█#w  #b█#w█████░░░#r░#w  #b█#w██#r█#w        #b░#w░█#r░#w      \n");
	ft_printfd(1, "                                                                                                      \n");
	ft_printfd(1, "        #b█#w█░█#r█#w   #b█#w░██#r█#w  #b█#w░░#r░#w  #b█#w░██#r█#w #b█#w██#r█#w  #b░#w██#r█#w  #b█#w█░░#r█#w  #b░#w██#r█#w  #b█#w█░#r█#w  #b█#w█░#r█#w  #b█#w██#r█#w   #b█#w█#r░#w  #b█#w██#r█#w        #b█#w░░#r█#w      \n");
	ft_printfd(1, "      #b█#w░███#r█#w #b█#w██░█#r█#w  #b█#w██#r█#w  #b█#w░███#r█#w#b█#w██#r█#w  #b█#w█░#r█#w  #b█#w███#r█#w        #b░#w░█#r░#w  #b█#w░░#r█#w  #b█#w██#r█#w        #b█#w██#r░#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "      #b░#w██#r█#w #b█#w█#r█#w #b█#w██#r█#w  #b█#w░░#r█#w  #b█#w██#r█#w #b░#w█░█#r░#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w███#r█#w  #b█#w█░#r█#w  #b█#w██#r█#w  #b█#w██#r█#w   #b░#w░#r░#w  #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "     #b█#w██#r█#w#b█#w░░█#r█#w#b░#w██#r█#w  #b█#w██#r█#w  #b█#w██#r█#w#b█#w████#r█#w  #b█#w░░#r░#w        #b█#w░██#r░#w  #b█#w██#r█#w  #b█#w██#r█#w  #b█#w░░#r░#w        #b█#w██#r█#w        #b█#w██#r█#w      \n");
	ft_printfd(1, "    #b█#w██#r█#w     #b█#w██#r█#w  #b█#w██#r█#w  #b█#w█░#r░#w  #b█#w██#r█#w  #b█#w██#r█#w   #b░#w░█████#r█#w    #b█#w██#r█#w  #b█#w██#r█#w  #b█#w████████#r█#w  #b█#w████░░░░#r█#w  #b█#w████████#r█#w\n");
	ft_printfd(1, "  #b▀#w▀▀#p▀#w▀▀▀▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w  #b▀#w▀▀#p▀#w▀▀#p▀#w▀▀#r▀#w  #b▀#w▀▀#r▀#w    #b▀#w▀▀▀▀▀#r▀#w    #b▀#w▀▀▀▀▀▀▀▀#r▀#w  #b▀#w▀▀▀▀▀▀#r▀#w    #b▀#w▀▀#r▀#w        #b▀#w▀▀#r▀#w      \n");
	ft_printfd(1, "                                                                                                      \n");
	if (back)
		back_to_the_future();
}
