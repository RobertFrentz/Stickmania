#include "Player.h"


Player::Player() 
{

}

Player::Player(sf::Sprite & _Sprite, Gun & _gun)
{
	gun = _gun;
	PlayerSprite = _Sprite;
}

Player::~Player()
{ 

}

sf::Sprite Player::getPlayerSprite()
{
	return PlayerSprite;
}

int Player::getPlayerGunDamage()
{
	return gun.getGunDamage();
}

int Player::getHealth()
{
	return Health;
}

void Player::changeHealth(unsigned int newHealth)
{
	Health = newHealth;
}


