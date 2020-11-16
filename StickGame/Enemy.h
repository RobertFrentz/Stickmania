#pragma once


#include <SFML/Graphics/Sprite.hpp>
#include "Gun.h"
#include <string>
#include <vector>

class Enemy : public sf::Sprite
{
public:
	Enemy();
	~Enemy();
	sf::FloatRect getEnemyLocation();
	sf::Sprite getEnemySprite();
	Enemy(sf::Sprite& _EnemySprite, Gun _gun);
	int getHealth();
	void changeHealth(unsigned int newHealth);
	void changeEnemyStatus(const char* _status);
	int getEnemyGunDamage();
	std::string getStatus();

private:
	Gun gun;
	unsigned int Health = 100;
	sf::Sprite EnemySprite;
	std::string status = "Alive";
};

