// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   EnemyHandler.class.hpp                             :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 22:26:40 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:35:27 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMYHANDLER_H
#define ENEMYHANDLER_H

#include "AEnemy.class.hpp"
#include "ABullet.class.hpp"
#include "Ship.class.hpp"
#include "BulletHandler.class.hpp"

class AEnemy;

class EnemyHandler
{
// Attributes
protected:
	AEnemy		*enemy;
	BulletHandler *bullets;
	EnemyHandler(void) { };

public:
	int			frame;
// Getters
	AEnemy		*getEnemyList(void) const;

// Methods
	void		bulletHit(ABullet *bullet);
	void		randomEnemys(t_point winsize, int frequency);
	void		add(std::string name, BulletHandler *bullets, int hp, int damage, int value,
					int xpos, int ypos, bool side);
	void		remove(AEnemy *enemy);
	void		showenemys(void);
	void		makeEnemysMove(Ship *ship);

// Operators
	EnemyHandler &operator=(EnemyHandler const &copy);

// Destructors / Constructors
	EnemyHandler(EnemyHandler const &copy);
	EnemyHandler(BulletHandler *bullets);
	virtual ~EnemyHandler();
};

#endif
