#include "InteractiveFunctions.h"

void EnemyGun_Fire(EnemyContainer enemies, Player& player)
{
	std::cout << "Enemy fired";
	for (int i = 0; i < enemies.getNumberOfEnemies(); i++)
	{
	  //if(enemies.getEnemiesShootTime()[i] >= )
		if (enemies.getEnemies()[i]->getStatus() == "Alive" && player.getHealth() > 0)
		{
			player.changeHealth(player.getHealth() - enemies.getEnemies()[i]->getEnemyGunDamage());
		}
	}
}

void PlayerUpdateHealthBar(Player & player, sf::Sprite& HealthBarSprite)
{
	if(player.getHealth() == 100) HealthBarSprite.setTextureRect(sf::IntRect(40, 0, 225, 80));
	else if(player.getHealth() >= 90 && player.getHealth() < 100) HealthBarSprite.setTextureRect(sf::IntRect(250, 0, 225, 80));
	else if(player.getHealth() >= 80 && player.getHealth() < 90) HealthBarSprite.setTextureRect(sf::IntRect(460, 0, 225, 80));
	else if(player.getHealth() >= 60 && player.getHealth() < 80) HealthBarSprite.setTextureRect(sf::IntRect(40, 90, 225, 50));
	else if (player.getHealth() >= 50 && player.getHealth() < 60) HealthBarSprite.setTextureRect(sf::IntRect(250, 90, 225, 50));
	else if (player.getHealth() >= 40 && player.getHealth() < 50) HealthBarSprite.setTextureRect(sf::IntRect(460, 90, 225, 50));
	else if (player.getHealth() >= 20 && player.getHealth() < 40) HealthBarSprite.setTextureRect(sf::IntRect(40, 140, 225, 50));
	else if (player.getHealth() > 0 && player.getHealth() < 20) HealthBarSprite.setTextureRect(sf::IntRect(250, 140, 225, 50));
	else if (player.getHealth() == 0) HealthBarSprite.setTextureRect(sf::IntRect(460, 140, 225, 50));
}

void PlayerGun_Fire(Player & player,EnemyContainer enemies ,sf::Vector2f MousePressedPos, sf::Vector2f MouseMovePos)
{
	for (int i = 0; i < enemies.getNumberOfEnemies(); i++)
	{
		if (enemies.getEnemiesRects()[i].contains(MousePressedPos) || enemies.getEnemiesRects()[i].contains(MouseMovePos))
		{
			std::cout << " Enemy " << i + 1 << " hit! " << " ";
			std::cout << enemies.getEnemies()[i]->getHealth() << " ";
			if (enemies.getEnemies()[i]->getHealth() <= 0)
			{
				enemies.getEnemies()[i]->changeEnemyStatus("Killed");
				enemies.getEnemiesRespawnTime()[i].restart();
				enemies.getEnemies()[i]->changeHealth(100);
			}
			else enemies.getEnemies()[i]->changeHealth(enemies.getEnemies()[i]->getHealth() - player.getPlayerGunDamage());
		}
	}

}
