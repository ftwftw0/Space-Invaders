// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   AEnemy.class.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 22:17:48 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 19:15:23 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef AENEMY_H
#define AENEMY_H

#include <iostream>
#include "BulletHandler.class.hpp"

class AEnemy
{
// Attributes
protected:
	std::string name;
	BulletHandler *bullets;
	int			hp;
	int			maxhp;
	int         damage;
	int         value;
	t_point		pos;
	bool		side;
	t_point		xfatness;
	t_point		yfatness;
	AEnemy(void) {std::cout << "Dont use me";};

public:
	AEnemy		*next;
	AEnemy		*prev;

// Getters
	std::string virtual getName(void) const;
	int					getDamage(void) const;
	t_point				getPos(void) const;
	int					getHp(void) const;
	int					getValue(void) const;
	int					getMaxHp(void) const;
	int					getPosX(void) const;
	int					getPosY(void) const;
	bool				getSide(void) const;
	t_point				getXFatness(void) const;
	t_point				getYFatness(void) const;


// Methods
    bool takeDamage(unsigned int amount);
	void show(void);
	void attack(void);
    bool randomMove(t_point winsize);
    void moveUp(void);
    void moveDown(t_point winsize);
    void moveLeft(void);
    void moveRight(t_point winsize);

// Operators
	AEnemy &operator=(AEnemy const &copy);

// Destructors / Constructors
	AEnemy(std::string const &name, BulletHandler *bullets, int hp, int damage, int value,
			int xpos, int ypos,
		   bool side, int leftfatness, int rightfatness, int topfatness, int botfatness);
	AEnemy(AEnemy const &copy);
	virtual ~AEnemy() { };
};

#endif
