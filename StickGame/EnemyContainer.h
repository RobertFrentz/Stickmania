#pragma once

#include <SFML/System.hpp>
#include <vector>
#include "Enemy.h"

class EnemyContainer
  {
    public:
	   EnemyContainer();
	   ~EnemyContainer();
	  int getNumberOfEnemies();
	  void AddEnemy(Enemy* _enemy);
	  void AddEnemyRect(sf::FloatRect _enemyRect);
	  void AddEnemyRespawnTime(sf::Clock* _enemyRespawnTime);
	  void AddEnemyShootTime(sf::Clock* _enemyShootTime);
	  std::vector<Enemy*> & getEnemies();
	  std::vector<sf::FloatRect> getEnemiesRects();
	  std::vector<sf::Clock*> & getEnemiesRespawnTime();
	  std::vector<sf::Clock*> & getEnemiesShootTime();
    private:
		std::vector<Enemy*> Enemies;
		std::vector<sf::FloatRect> EnemiesRect;
	    std::vector<sf::Clock*> EnemyRespawnTime;
		std::vector<sf::Clock*> EnemyShootTime;


  };

