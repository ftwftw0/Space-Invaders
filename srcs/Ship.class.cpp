// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Ship.class.cpp                                     :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: flagoutt <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/20 14:14:56 by flagoutt          #+#    #+#             //
//   Updated: 2015/06/21 20:33:35 by flagoutt         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Ship.class.hpp"

std::string Ship::quotes[] = 
{
	"This time it'll be awesome, I promise!",
	"Hey everybody, check out that looser!",
	"Tips : Press I to send your unkillable friends!",
	"Recompiling my combat code!",
	"Running the sequencer!",
	"It's happening... it's happening!",
	"It's about to get magical!",
	"What will he do next?",
	"Things are about to get awesome!",
	"Let's get this party started!",
	"Glitchy weirdness is term of endearment, right?",
	"I'm a sexy dinosaur! Rawr.",
	"Oh god I can't stop!",
	"It's the only way to stop the voices!",
	"I am cloaking...",
	"Roses are red/Violets are blue/Wait...how many syllables does that have?",
	"Clem le moche!",
	"Aww, I shoulda drawn tattoos on it!",
	"Burn them, my mini-phoenix!",
	"Calm down!",
	"It's time to phase you suckers out!",
	"Tell me I'm the prettiest!", 
	"To the sky, Noob!", 
	"Fly Noob! Fly!", 
	"I have two robot arms!", 
	"Punch 'em in the face, noob!", 
	"Ratattattattatta! Powpowpowpow! Powpowpowpow! Pew-pew-pew!", 
	"Score one for the noob!", 
	"I'm going commando!", 
	"Boiyoiyoiyoiyoing!",
	"For you...I commit...seppuku...", 
	"Some days, you just can't get rid of an obscure pop-culture reference.", 
	"Can I use my magic missile",
	"Do not look behind my curtain!",
	"I'm made of magic!", 
	"You can call me Gundalf!", 
	"Kill! Reload! Kill! Reload! KILL! RELOAD!", 
	"Like those guys who made only one song ever.", 
	"All these bullets in just one shot.", 
	"One shot, make it count!", 
	"Boogie time!",
	"Lasers!",
	"Psychedellic man!",
	"Everybody, dance time! Da-da-da-dun-daaa-da-da-da-dun-daaa!",
	"One for you, one for you, and one for you!",
	"I fucking love dogs!",
	"Is this really your canon?",
	"I feel a joke about poop decks coming on!"
};

/*
** Accessors
*/
std::string Ship::getName(void) const
{
	return (this->name);
}

int Ship::getPosX(void) const
{
	return (this->pos.x);
}

int Ship::getPosY(void) const
{
	return (this->pos.y);
}

int Ship::getHp(void) const
{
	return (this->hp);
}

int Ship::getMaxHp(void) const
{
	return (this->maxhp);
}

int Ship::getScore(void) const
{
	return (this->score);
}

int Ship::getDmg(void) const
{
	return (this->dmg);
}

/*
**  Setters
*/
void	Ship::setAnnounce(std::string announce)
{
	this->txtannounce = announce;
}

void	Ship::setAutoAttack()
{
	this->autoattack = (this->autoattack) ? 0 : 1;
}

/*
** Methods
*/
void    Ship::bulletHit(ABullet *bullet)
{
    t_point bulletpos;

    bulletpos = bullet->getPos();
	if (bulletpos.x >= this->pos.x - 3 &&
		bulletpos.x <= this->pos.x + 10 &&
		bulletpos.y >= this->pos.y - 2 &&
		bulletpos.y <= this->pos.y + 2)
		this->takeDamage(bullet->getDamage());
}

void Ship::sendUnkillableFriend(void)
{
	return ;
}

void Ship::addScore(int score)
{
	this->score += score;
}

void Ship::moveUp(void)
{
	if (this->pos.y > 0)
		this->pos.y--;
}

void Ship::moveDown(t_point winsize)
{
	if (this->pos.y < winsize.y - 1)
		this->pos.y++;
}

void Ship::moveLeft(void)
{
	if (this->pos.x > 0)
		this->pos.x--;
}

void Ship::moveRight(t_point winsize)
{
	if (this->pos.x < winsize.x - 4)
		this->pos.x++;
}

void Ship::saysth(void) const
{
	std::cout << "\033[36m" << this->name << "\033[0m"<< " : "
			  << Ship::quotes[5 + rand() % 48] << std::endl;
}

void Ship::show(void) const
{
	// Show ship
	attron(COLOR_PAIR(2));
	mvprintw(this->pos.y - 2, this->pos.x,	"|\\");
	mvprintw(this->pos.y - 1, this->pos.x,	"| \\");
	mvprintw(this->pos.y, this->pos.x,		"|  }");
	mvprintw(this->pos.y + 1, this->pos.x,	"| /");
	mvprintw(this->pos.y + 2, this->pos.x,	"|/");
	attroff(COLOR_PAIR(2));
	// Show life
	attron(COLOR_PAIR(0));
	mvprintw(1, 1,	"Player : %s", this->getName().c_str());
	mvprintw(2, 1,	"Life   : %i / %i", this->getHp(), this->getMaxHp());
	mvprintw(3, 1,	"Damage : %i", this->getDmg());
	mvprintw(4, 1,	"Score  : %i", this->getScore());
	attroff(COLOR_PAIR(0));
}

void Ship::attack(void)
{
	if (this->autoattack)
		this->bullets->add(this->name, this->dmg,
						   this->pos.x + 4, this->pos.y, 1);
}

int Ship::takeDamage(unsigned int amount)
{
	if (this->hp > 0)
	{
		if (this->hp > (int)amount)
			this->hp -= amount;
		else
			this->hp = 0;
		this->txtannounce = this->name + " takes " + std::to_string(amount) + "damage. (" + std::to_string(this->hp) + "HP left)";
		if (this->hp == 0)
			this->txtannounce = this->name + " just died.";
	}
	else
		this->txtannounce = this->name + " is dead.";
	return (amount);
}

void Ship::introduce(void) const
{
	std::cout << "I am " << this->name
			  << " and i love pooonieees!!!" << std::endl;
}

void Ship::announce(void)
{
	t_point winsize;
	int		start;
	int		end;

	start = rand();
	if (start % 1000 == 1)
		this->setAnnounce(quotes[start % 48]);
	getmaxyx(stdscr, winsize.y, winsize.x);
	start = (winsize.x - this->txtannounce.length()) / 2;
	end = start + this->txtannounce.length() + 2;
	mvprintw(1, start + 2, this->txtannounce.c_str());
	attron(COLOR_PAIR(3));
	mvprintw(0, start, "+-");
	mvprintw(1, start, "| ");
	mvprintw(2, start, "+-");
	while (++start < end)
	{
		mvprintw(0, start, "-");
		mvprintw(2, start, "-");
	}
	mvprintw(0, start, "-+");
	mvprintw(1, start, " |");
	mvprintw(2, start, "-+");
	attroff(COLOR_PAIR(3));
}

/*
** Operators
*/
Ship &Ship::operator=(Ship const &copy)
{
	this->name = copy.getName();
	this->hp = copy.getHp();
	this->maxhp = copy.getMaxHp();
	this->score = copy.getScore();
	this->dmg = copy.getDmg();
	this->bullets = copy.bullets;
	this->unkillablefriend = copy.unkillablefriend;
	this->autoattack = 0;
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const Ship &a)
{
	os << a.getName() << " has " << a.getHp()
	   << "HP and is unarmed." << std::endl;
	return (os);
}

/*
** Constructeurs / Destructeurs
*/
Ship::Ship(std::string const &name, BulletHandler *bullets) : name(name), bullets(bullets)
{
	srand((long)time(0));
	this->hp = 100;
	this->maxhp = 100;
	this->score = 0;
	this->dmg = 10;
	getmaxyx(stdscr, this->pos.y, this->pos.x);
	this->pos.y /= 2;
	this->pos.x /= 5;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << ", is born.\033[0m"
			  << std::endl;
}

Ship::Ship(Ship const &a)
{
	srand((long)time(0));
	this->hp = a.getHp();
	this->name = a.getName();
	this->maxhp = a.getMaxHp();
	this->score = a.getScore();
	this->dmg = a.getDmg();
	this->pos = a.pos;
	this->bullets = a.bullets;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << ", is born.\033[0m"
			  << std::endl;
}

Ship::Ship(Ship const &a, std::string name) : name(name)
{
	srand((long)time(0));
	this->hp = a.getHp();
	this->maxhp = a.getMaxHp();
	this->score = a.getScore();
	this->dmg = a.getDmg();
	this->pos = a.pos;
	this->bullets = a.bullets;
	this->unkillablefriend = 3;
	this->autoattack = 0;
	std::cout << "\033[32m" << this->name
			  << " bought a ship.\033[0m"
			  << std::endl;
}

Ship::~Ship(void)
{
	std::cout << "\033[31mYour ship, " << this->name
			  << ", is dead. You're alone now. Feel free to kill yourself.\033[0m"
			  << std::endl;
}
