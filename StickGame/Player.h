#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include "Gun.h"

class Player
{
public:
	Player();
	Player(sf::Sprite& _PlayerSprite,Gun& _gun);
	~Player();
	sf::Sprite getPlayerSprite();
	int getPlayerGunDamage();
	int getHealth();
	void changeHealth(unsigned int newHealth);
private:
	Gun gun;
	unsigned int Health = 100;
	sf::Sprite PlayerSprite;

};

