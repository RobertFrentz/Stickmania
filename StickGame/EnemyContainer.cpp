#include "EnemyContainer.h"



EnemyContainer::EnemyContainer()
{
}


EnemyContainer::~EnemyContainer()
{
}

int EnemyContainer::getNumberOfEnemies()
{
	return Enemies.size();
}


void EnemyContainer::AddEnemy(Enemy* _enemy)
{
	Enemies.push_back(_enemy);
}

void EnemyContainer::AddEnemyRect(sf::FloatRect _enemyRect)
{
	EnemiesRect.push_back(_enemyRect);
}
void EnemyContainer::AddEnemyRespawnTime(sf::Clock* _enemyRespawnTime)
{
	EnemyRespawnTime.push_back(_enemyRespawnTime);
}
void EnemyContainer::AddEnemyShootTime(sf::Clock* _enemyShootTime)
{
	EnemyShootTime.push_back(_enemyShootTime);
}

std::vector<Enemy*> & EnemyContainer::getEnemies()
{
	return Enemies;
}

std::vector<sf::FloatRect> EnemyContainer::getEnemiesRects()
{
	return EnemiesRect;
}

std::vector<sf::Clock*> & EnemyContainer::getEnemiesRespawnTime()
{
	return EnemyRespawnTime;
}

std::vector<sf::Clock*> & EnemyContainer::getEnemiesShootTime()
{
	return EnemyShootTime;
}

