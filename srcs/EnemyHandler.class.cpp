// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemyHandler.class.cpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 22:26:35 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:45:29 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "EnemyHandler.class.hpp"

/*
**  Methodes
*/
void	EnemyHandler::bulletHit(ABullet *bullet)
{
	AEnemy *enemy;
	t_point bulletpos;
	t_point enemypos;

	bulletpos = bullet->getPos();
	enemy = this->enemy;
	while (enemy)
	{
		enemypos = enemy->getPos();
		if (bulletpos.x >= enemypos.x - enemy->getXFatness().x &&
			bulletpos.x <= enemypos.x + enemy->getXFatness().y &&
			bulletpos.y >= enemypos.y - enemy->getYFatness().x &&
			bulletpos.y <= enemypos.y + enemy->getYFatness().y)
			enemy->takeDamage(bullet->getDamage());
		enemy = enemy->next;
	}
}

void	EnemyHandler::randomEnemys(t_point winsize, int frequency)
{
	if (this->frame % frequency == 0)
	{
		this->add("Taggle", this->bullets, 10, 1, 2,
				  winsize.x - 2, rand() % winsize.y, 0);
	}
	else if (this->frame % 3000 == 0)
	{
		this->add("Moche", this->bullets, 100000, 1, 1000,
				  winsize.x - 2, winsize.y / 2, 0);
	}
	this->frame++;
}

void	EnemyHandler::makeEnemysMove(Ship *ship)
{
	AEnemy *tmp;
	AEnemy *prev;
	t_point winsize;
	int ret;

	if (!this->enemy)
		return ;
	getmaxyx(stdscr, winsize.y, winsize.x);
	tmp = this->enemy;
	if ((ret = tmp->randomMove(winsize)))
		ship->takeDamage(tmp->getDamage() * 10);
	prev = tmp;
	tmp = tmp->next;
	if (prev->getPosX() >= winsize.x - 1 ||
		prev->getPosX() <= 0 ||
		prev->getHp() <= 0 || ret)
	{
		if (prev->getHp() <= 0)
			ship->addScore(prev->getValue());
		this->remove(prev);
		this->enemy = tmp;
	}
	while (tmp)
	{
		if ((ret = tmp->randomMove(winsize)))
			ship->takeDamage(tmp->getDamage() * 10);
		prev = tmp;
		tmp = tmp->next;
		if (prev && (prev->getPosX() >= winsize.x - 1 ||
					 prev->getPosX() <= 0 ||
					 prev->getHp() <= 0 || ret))
		{
			if (prev->getHp() <= 0)
				ship->addScore(prev->getValue());
			this->remove(prev);
		}
	}
}

void      EnemyHandler::remove(AEnemy *enemy)
{
	AEnemy *tmp;

    if (enemy == this->enemy)
        this->enemy = enemy->next;
	tmp = enemy;
	if (!(tmp))
		return ;
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	delete tmp;
}

void     EnemyHandler::showenemys(void)
{
	AEnemy *tmp;

	tmp = this->enemy;
	while (tmp)
	{
		tmp->show();
		tmp = tmp->next;
	}
}

void      EnemyHandler::add(std::string name, BulletHandler *bullets, int hp, int damage, int value,
                int xpos, int ypos, bool side)
{
	AEnemy *tmp;

	tmp = this->enemy;
	if (!(tmp))
		this->enemy = new AEnemy(name, bullets, hp, damage, value,
								 xpos, ypos, side, 1, 0, 1, 1);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new AEnemy(name, bullets, hp, damage, value,
							   xpos, ypos, side, 1, 0, 1, 1);
		tmp->next->prev = tmp;
	}
}

/*
**  Getters
*/
AEnemy			*EnemyHandler::getEnemyList() const
{
	return (this->enemy);
}

/*
**  Operators
*/
EnemyHandler &EnemyHandler::operator=(EnemyHandler const &copy)
{
	this->enemy = copy.getEnemyList();
	return (*this);
}

/*
**   Constructors / Destructors
*/
EnemyHandler::EnemyHandler(EnemyHandler const &copy)
{
	srand((long)time(0));
	this->enemy = copy.enemy;
	this->frame = 0;
}

EnemyHandler::EnemyHandler(BulletHandler *bullets)
{
	srand((long)time(0));
	this->enemy = NULL;
	this->bullets = bullets;
	this->frame = 0;
}

EnemyHandler::~EnemyHandler(void)
{
	AEnemy *tmp;

	tmp = this->enemy;
	while (this->enemy)
	{
		tmp = this->enemy;
		this->enemy = this->enemy->next;
		delete tmp;
	}
}
