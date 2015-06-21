// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BulletHandler.class.cpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 17:36:22 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 18:55:06 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "BulletHandler.class.hpp"

/*
**  Methodes
*/
void	BulletHandler::makeBulletsMove(EnemyHandler *enemys, Ship *ship)
{
	ABullet *tmp;
	ABullet *prev;
	t_point winsize;
	int		ret;

	if (!this->bullet)
		return ;
	getmaxyx(stdscr, winsize.y, winsize.x);
	tmp = this->bullet;
	if ((ret = tmp->move())) // If collision
	{
		if (ret == 1)
			enemys->bulletHit(tmp);
		else
			ship->bulletHit(tmp);
	}
	prev = tmp;
	tmp = tmp->next;
	if (prev->getPosX() >= winsize.x - 1 ||
		prev->getPosX() <= 0 ||
		ret)
	{
		this->remove(prev);
		this->bullet = tmp;
	}
	while (tmp)
	{
		if ((ret = tmp->move()))
		{
			if (ret == 1)
				enemys->bulletHit(tmp);
			else
				ship->bulletHit(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
		if (prev && (prev->getPosX() >= winsize.x - 1 ||
					 prev->getPosX() <= 0 || ret))
			this->remove(prev);
	}
}

void      BulletHandler::remove(ABullet *bullet)
{
	ABullet *tmp;

	if (bullet == this->bullet)
		this->bullet = bullet->next;
	tmp = bullet;
	if (!(tmp))
		return ;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	delete tmp;
}

void     BulletHandler::showbullets(void)
{
	ABullet *tmp;

	tmp = this->bullet;
	while (tmp)
	{
		if (tmp->getSide())
		{
			attron(COLOR_PAIR(2));
			mvprintw(tmp->getPos().y, tmp->getPos().x, "#-");
			attroff(COLOR_PAIR(2));
		}
		else
		{
			attron(COLOR_PAIR(1));
			mvprintw(tmp->getPos().y, tmp->getPos().x, "-#");
			attroff(COLOR_PAIR(1));
		}
		tmp = tmp->next;
	}
}

void      BulletHandler::add(std::string &name, int damage,
                int xpos, int ypos, bool side)
{
	ABullet *tmp;

	tmp = this->bullet;
	if (!(tmp))
		this->bullet = new ABullet(name, damage,
								   xpos, ypos, side);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new ABullet(name, damage, xpos, ypos, side);
		tmp->next->prev = tmp;
	}
}

/*
**  Getters
*/
ABullet			*BulletHandler::getBulletList() const
{
	return (this->bullet);
}

/*
**  Operators
*/
BulletHandler &BulletHandler::operator=(BulletHandler const &copy)
{
	this->bullet = copy.getBulletList();
	return (*this);
}

/*
**   Constructors / Destructors
*/
BulletHandler::BulletHandler(BulletHandler const &copy)
{
	this->bullet = copy.bullet;
}

BulletHandler::BulletHandler(void)
{
	this->bullet = NULL;
}

BulletHandler::~BulletHandler(void)
{
	ABullet *tmp;

	tmp = this->bullet;
	while (this->bullet)
	{
		tmp = this->bullet;
		this->bullet = this->bullet->next;
		delete tmp;
	}
}
