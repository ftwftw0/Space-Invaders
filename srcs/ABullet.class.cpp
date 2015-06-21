// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   ABullet.class.cpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 18:30:50 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 18:54:35 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "ABullet.class.hpp"

/*
**  Methods
*/
void  ABullet::attack(void)
{
	
	return ;
}

int   ABullet::move(void) // Returns 1 or 2 if collision
{
	if (side)
	{
		this->pos.x++;
		if ((mvinch(this->pos.y, this->pos.x + 1) & A_COLOR) == COLOR_PAIR(1))
			return (1);
	}
	else
	{
		this->pos.x--;
		if ((mvinch(this->pos.y, this->pos.x) & A_COLOR) == COLOR_PAIR(2))
			return (2);
	}
	return (0);
}

void	ABullet::show(void)
{
	if (this->getSide())
	{
		attron(COLOR_PAIR(2));
		mvprintw(this->pos.y, this->pos.x, "#-");
		attroff(COLOR_PAIR(2));
	}
	else
	{
		attron(COLOR_PAIR(1));
		mvprintw(this->pos.y, this->pos.x, "-#");
		attroff(COLOR_PAIR(1));
	}
}

/*
**  Getters
*/
std::string	ABullet::getName() const
{
	return (this->name);
}

int			ABullet::getDamage() const
{
	return (this->damage);
}

t_point     ABullet::getPos(void) const
{
	return (this->pos);
}

int     ABullet::getPosX(void) const
{
	return (this->pos.x);
}

int     ABullet::getPosY(void) const
{
	return (this->pos.y);
}

bool		ABullet::getSide(void) const
{
	return (this->side);
}

/*
** Constructors / Destructors
*/

ABullet::ABullet(std::string const &name, int damage, int xpos, int ypos, bool side) : name(name), damage(damage), side(side)
{
	this->pos.x = xpos;
	this->pos.y = ypos;
	this->next = NULL;
	this->prev = NULL;
}

ABullet::ABullet(ABullet const &copy)
{
	this->pos = copy.getPos();
	this->name = copy.getName();
	this->damage = copy.getDamage();
	this->next = copy.next;
	this->prev = copy.prev;
}

ABullet &ABullet::operator=(ABullet const &copy)
{
	this->pos = copy.getPos();
	this->name = copy.getName();
	this->damage = copy.getDamage();
	this->next = copy.next;
	this->prev = copy.prev;
	return (*this);
}
