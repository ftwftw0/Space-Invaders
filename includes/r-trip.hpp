// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   r-trip.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 14:32:57 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:22:28 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef R_TRIP_H
#define R_TRIP_H

#include <iostream>
#include <ncurses.h>
#include <string.h>

#define MOBSFREQUENCY 100
#define MOBSFIREFREQUENCY 10

class EnemyHandler;
class BulletHandler;
class Ship;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

int keyhooks(int key, Ship *ship, t_point winsize);

#endif
