// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BulletHandler.class.hpp                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 17:36:29 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 18:26:03 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLETHANDLER_H
#define BULLETHANDLER_H

#include <iostream>
#include "ABullet.class.hpp"
#include "EnemyHandler.class.hpp"

class BulletHandler
{
// Attributes
protected:
	ABullet		*bullet;

public:
// Getters
	ABullet		*getBulletList(void) const;

// Methods
	void		add(std::string &name, int damage,
					int xpos, int ypos, bool side);
	void		remove(ABullet *bullet);
	void		showbullets(void);
	void		makeBulletsMove(EnemyHandler *enemys, Ship *ship);

// Operators
	BulletHandler &operator=(BulletHandler const &copy);

// Destructors / Constructors
	BulletHandler(BulletHandler const &copy);
	BulletHandler(void);
	virtual ~BulletHandler();
};

#endif
