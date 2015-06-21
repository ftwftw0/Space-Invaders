// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEnemy.class.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 22:17:51 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:26:34 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "AEnemy.class.hpp"

/*
**  Methods
*/
bool AEnemy::takeDamage(unsigned int amount)
{
    if (this->hp <= 0)
        return (0);
    if (this->hp > (int)amount)
        this->hp -= amount;
    else
        this->hp = 0;
    if (this->hp == 0)
        return (0);
    return (1);
}

void  AEnemy::attack(void)
{
	this->bullets->add(this->name, this->damage,
                       this->pos.x + 4, this->pos.y, 0);
	return ;
}

void  AEnemy::show(void)
{
//	static int frame = 0;

	if (this->getSide())
	{
		attron(COLOR_PAIR(2));
		mvprintw(this->pos.y - 1, this->pos.x, "[\\");
		mvprintw(this->pos.y, this->pos.x - 1, "| >");
		mvprintw(this->pos.y + 1, this->pos.x, "[/");
		attroff(COLOR_PAIR(2));
	}
	else
	{
		attron(COLOR_PAIR(1));
		mvprintw(this->pos.y - 1, this->pos.x,	 "/]");
		mvprintw(this->pos.y, this->pos.x - 1,	"< |");
		mvprintw(this->pos.y + 1, this->pos.x,	"\\]");
		attroff(COLOR_PAIR(1));
	}
	return ;
}

bool AEnemy::randomMove(t_point winsize)
{
    int i;

    i = rand() % 100;
    if (i == 0)
        this->moveUp();
    else if (i == 1)
        this->moveDown(winsize);
    else if (i == 2)
	{
		this->attack();
        this->moveRight(winsize);
	}
    else if (i > 80)
        this->moveLeft();
	if ((mvinch(this->pos.y - 1, this->pos.x) & A_COLOR) == COLOR_PAIR(2) ||
		(mvinch(this->pos.y, this->pos.x) & A_COLOR) == COLOR_PAIR(2) ||
		(mvinch(this->pos.y + 1, this->pos.x) & A_COLOR) == COLOR_PAIR(2))
        return (1);
	return (0);
}

void AEnemy::moveUp(void)
{
    if (this->pos.y > 0)
        this->pos.y--;
}

void AEnemy::moveDown(t_point winsize)
{
    if (this->pos.y < winsize.y - 1)
        this->pos.y++;
}

void AEnemy::moveLeft(void)
{
    if (this->pos.x > 0)
		this->pos.x--;
}

void AEnemy::moveRight(t_point winsize)
{
    if (this->pos.x < winsize.x - 4)
        this->pos.x++;
}

/*
**  Getters
*/
std::string	AEnemy::getName() const
{
	return (this->name);
}

int			AEnemy::getDamage() const
{
	return (this->damage);
}

t_point     AEnemy::getPos(void) const
{
	return (this->pos);
}

int	     AEnemy::getValue(void) const
{
	return (this->value);
}

int     AEnemy::getPosX(void) const
{
	return (this->pos.x);
}

int     AEnemy::getPosY(void) const
{
	return (this->pos.y);
}

bool	AEnemy::getSide(void) const
{
	return (this->side);
}

int AEnemy::getHp(void) const
{
    return (this->hp);
}

int AEnemy::getMaxHp(void) const
{
    return (this->maxhp);
}

t_point     AEnemy::getXFatness(void) const
{
	return (this->xfatness);
}

t_point     AEnemy::getYFatness(void) const
{
	return (this->yfatness);
}

/*
** Constructors / Destructors
*/

AEnemy::AEnemy(std::string const &name, BulletHandler *bullets, int hp, int damage, int value, int xpos, int ypos, bool side, int leftfatness, int rightfatness, int topfatness, int botfatness) : name(name), damage(damage), side(side)
{
	t_point i;

	this->bullets = bullets;
	i.x = leftfatness;
	i.y = rightfatness;
	this->xfatness = i;
	i.x = topfatness;
	i.y = botfatness;
	this->hp = hp;
	this->value = value;
	this->maxhp = hp;
	this->yfatness = i;
	this->pos.x = xpos;
	this->pos.y = ypos;
	this->next = NULL;
	this->prev = NULL;
}

AEnemy::AEnemy(AEnemy const &copy)
{
	this->bullets = copy.bullets;
	this->pos = copy.getPos();
	this->name = copy.getName();
	this->hp = copy.hp;
	this->maxhp = copy.maxhp;
	this->damage = copy.getDamage();
	this->next = copy.next;
	this->prev = copy.prev;
	this->xfatness = copy.xfatness;
	this->yfatness = copy.yfatness;
}

AEnemy &AEnemy::operator=(AEnemy const &copy)
{
	this->bullets = copy.bullets;
	this->pos = copy.getPos();
	this->hp = copy.hp;
	this->maxhp = copy.hp;
	this->name = copy.getName();
	this->damage = copy.getDamage();
	this->next = copy.next;
	this->prev = copy.prev;
	return (*this);
}

