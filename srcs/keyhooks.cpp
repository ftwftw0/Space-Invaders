// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   keyhooks.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 16:00:27 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:27:57 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ship.class.hpp"
#include "r-trip.hpp"

int	keyhooks(int key, Ship *ship, t_point winsize)
{
	if (key == 27) // Escape
		return (0);
	else if (key == KEY_DOWN)
		ship->moveDown(winsize);
	else if (key == KEY_UP)
		ship->moveUp();
	else if (key == KEY_LEFT)
		ship->moveLeft();
	else if (key == KEY_RIGHT)
		ship->moveRight(winsize);
	else if ((char)key == ' ')
		ship->setAutoAttack();
	else if ((char)key == 'i')
		ship->sendUnkillableFriend();
	return (1);
}
