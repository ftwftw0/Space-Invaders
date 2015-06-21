// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.class.hpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 13:50:56 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:31:18 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <ncurses.h>
#include "BulletHandler.class.hpp"

class Ship
{
protected:
	std::string			name;
	std::string			txtannounce;
	BulletHandler		*bullets;
	int					unkillablefriend;
	t_point				pos;
	int					hp;
	int					maxhp;
	int					score;
	int					dmg;
	bool				autoattack;
	static std::string	quotes[];
 	inline Ship(void) {std::cout << "Dont use me";};

public:
// Getters
	std::string			getName(void) const;
	int					getHp(void) const;
	int					getPosX(void) const;
	int					getPosY(void) const;
	int					getMaxHp(void) const;
	int					getScore(void) const;
	int					getDmg(void) const;

// Setters
	void				setAnnounce(std::string announce);
	void				setAutoAttack(void);

// Methods
	void bulletHit(ABullet *bullet);
	void sendUnkillableFriend(void);
	void addScore(int score);
	void moveUp(void);
	void moveDown(t_point winsize);
	void moveLeft(void);
	void moveRight(t_point winsize);
	void show(void) const;
    void attack(void);
	int	 takeDamage(unsigned int amount);
	void announce(void);
	void introduce(void) const;
	void saysth(void) const;

// Operators
	Ship &operator=(Ship const &copy);

// Constructors / Destructors
	Ship(std::string const &name, BulletHandler *bullets);
	Ship(Ship const &a);
	Ship(Ship const &a, std::string name);
	virtual ~Ship(void);
};

std::ostream &operator<<(std::ostream &os, const Ship &a);
#endif
