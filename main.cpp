
// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/18 11:02:43 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:52:53 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "r-trip.hpp"
#include "Ship.class.hpp"
#include "BulletHandler.class.hpp"
#include "EnemyHandler.class.hpp"
#include "AEnemy.class.hpp"
#include "unistd.h"

void	initgame(t_point *winsize)
{
	initscr();
	raw();	/* Line buffering disabled*/
	keypad(stdscr, TRUE);	/* We get F1, F2 etc..*/
	noecho();
	nodelay(stdscr, TRUE);
	curs_set(0);
	if (has_colors() == FALSE)
	{
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	getmaxyx(stdscr, winsize->y, winsize->x);
}

int main()
{
	t_point			winsize;
	BulletHandler	*bullets;
	EnemyHandler	*enemys;
	Ship			*ship;
	int				key;

	initgame(&winsize);
	bullets = new BulletHandler();
	enemys = new EnemyHandler(bullets);
	ship = new Ship("IceTea", bullets);
	ship->setAnnounce("Game Master : Good luck little boy.");
	getmaxyx(stdscr, winsize.y, winsize.x);
    mvprintw(winsize.y / 2, winsize.x / 2, ship->getName().c_str());
	attron(A_DIM);
	while (ship->getHp())
	{
		key = getch();
		if (key != ERR)
			if (keyhooks(key, ship, winsize) == 0)
				break ;
		erase();
		bullets->showbullets();
		enemys->showenemys();
		ship->show();
		bullets->makeBulletsMove(enemys, ship);
		enemys->makeEnemysMove(ship);
		enemys->randomEnemys(winsize, MOBSFREQUENCY);
		if ((enemys->frame % 10) == 0)
			ship->attack();
		ship->announce();
		refresh(); /* Print it on to the real screen */
		usleep(20000);
	}
	ship->show();
	// THE END
    mvprintw(winsize.y / 2, winsize.x / 2 - 10, "Game Over - Press any key");
	refresh(); /* Print it on to the real screen */
	usleep(1000000);
	nodelay(stdscr, FALSE);
	getch();
	// DESTROY TIME
	delete ship;
	delete bullets;
	endwin();/* End curses mode  */
	return (0);
}
