#include "Enemy.h"

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
}

sf::FloatRect Enemy::getEnemyLocation()
{
	return this->getGlobalBounds();
}

sf::Sprite Enemy::getEnemySprite()
{
	return EnemySprite;
}

Enemy::Enemy(sf::Sprite & _EnemySprite, Gun _gun)
{
	EnemySprite = _EnemySprite;
	gun = _gun;

}

int Enemy::getHealth()
{
	return Health;
}

void Enemy::changeHealth(unsigned int newHealth)
{
	Health = newHealth;
}



void Enemy::changeEnemyStatus(const char * _status)
{
	status = _status;
}

int Enemy::getEnemyGunDamage()
{
	return gun.getGunDamage();
}

std::string Enemy::getStatus()
{
	return status;
}








