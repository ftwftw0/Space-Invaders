// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ABullet.class.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 18:30:46 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 18:54:57 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //


#ifndef ABULLET_H
#define ABULLET_H

#include <iostream>
#include "r-trip.hpp"
#include <ncurses.h>

class ABullet
{
// Attributes
protected:
	std::string name;
	int         damage;
	t_point		pos;
	bool		side;
	ABullet(void) {std::cout << "Dont use me";};

public:
	ABullet		*next;
	ABullet		*prev;

// Getters
	std::string virtual getName(void) const;
	int					getDamage(void) const;
	t_point				getPos(void) const;
	int					getPosX(void) const;
	int					getPosY(void) const;
	bool				getSide(void) const;

// Methods
	void		attack(void);
	int			move(void); // ret si collision
	void		show(void);

// Operators
	ABullet &operator=(ABullet const &copy);

// Destructors / Constructors
	ABullet(std::string const &name, int damage,
			int xpos, int ypos,
			bool side);
	ABullet(ABullet const &copy);
	virtual ~ABullet() { };
};

#endif
