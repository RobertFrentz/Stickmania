#include "InteractiveFunctions.h"


void EnemyGun_Fire(EnemyContainer& enemies, Player& player)
{

	//std::cout << "Enemy fired";
	for (int i = 0; i < enemies.getNumberOfEnemies(); i++)
	{
		if (enemies.getEnemiesShootTime()[i]->getElapsedTime() >= sf::seconds(1))
		{
			if (enemies.getEnemies()[i]->getStatus() != "Killed" && player.getHealth() > 0)
			{
				player.changeHealth(player.getHealth() - enemies.getEnemies()[i]->getEnemyGunDamage());
				enemies.getEnemiesShootTime()[i]->restart();
				std::cout << player.getHealth() << "           ";
			}
		}
	}
}

void EnemyRespawnTimeFunc(EnemyContainer & enemies)
{
	for (int i = 0; i < enemies.getNumberOfEnemies(); i++)
	{
		if (enemies.getEnemiesRespawnTime()[i]->getElapsedTime() >= sf::seconds(2))
		{
			enemies.getEnemies()[i]->changeEnemyStatus("Alive");
		}
	}
}

void PlayerUpdateHealthBar(Player & player, sf::Sprite& HealthBarSprite, float X, float Y)
{
	if (player.getHealth() == 100) HealthBarSprite.setTextureRect(sf::IntRect(40, 0, 225, 80));
	else if (player.getHealth() >= 90 && player.getHealth() < 100) HealthBarSprite.setTextureRect(sf::IntRect(250, 0, 225, 80));
	else if (player.getHealth() >= 80 && player.getHealth() < 90) HealthBarSprite.setTextureRect(sf::IntRect(460, 0, 225, 80));
	else if (player.getHealth() >= 60 && player.getHealth() < 80) { HealthBarSprite.setTextureRect(sf::IntRect(40, 90, 225, 50)); HealthBarSprite.setPosition(X - 300, Y - 345); }
	else if (player.getHealth() >= 50 && player.getHealth() < 60) HealthBarSprite.setTextureRect(sf::IntRect(250, 90, 225, 50));
	else if (player.getHealth() >= 40 && player.getHealth() < 50) HealthBarSprite.setTextureRect(sf::IntRect(460, 90, 225, 50));
	else if (player.getHealth() >= 20 && player.getHealth() < 40) HealthBarSprite.setTextureRect(sf::IntRect(40, 140, 225, 50));
	else if (player.getHealth() > 0 && player.getHealth() < 20) HealthBarSprite.setTextureRect(sf::IntRect(250, 140, 225, 50));
	else if (player.getHealth() == 0) HealthBarSprite.setTextureRect(sf::IntRect(460, 140, 225, 50));
}


void PlayerGun_Fire(Player & player, EnemyContainer& enemies, sf::Vector2f MousePressedPos, sf::Vector2f MouseMovePos, unsigned int &killcount)
{
	for (int i = 0; i < enemies.getNumberOfEnemies(); i++)
	{
		if (enemies.getEnemiesRects()[i].contains(MousePressedPos) || enemies.getEnemiesRects()[i].contains(MouseMovePos))
		{
			std::cout << " Enemy " << i + 1 << " hit! " << " ";
			if (enemies.getEnemies()[i]->getHealth() <= 0)
			{
				killcount++;
				enemies.getEnemies()[i]->changeEnemyStatus("Killed");
				enemies.getEnemiesRespawnTime()[i]->restart();
				enemies.getEnemies()[i]->changeHealth(100);

			}
			else enemies.getEnemies()[i]->changeHealth(enemies.getEnemies()[i]->getHealth() - player.getPlayerGunDamage());
			std::cout << enemies.getEnemies()[i]->getHealth() << " ";

		}
	}
}

void time_counter(unsigned int level, sf::Clock& clock, sf::Text& Timer , float X , float Y)
{
	if (level == 0)
	{
		clock.restart();
		return;
	}

	sf::Time counter_secunde = clock.getElapsedTime();
	float counter_secunde_ = counter_secunde.asSeconds();

	std::string TimeToShow;

	if(counter_secunde_ <= 10) TimeToShow = " 0 : 0" + std::to_string((int)counter_secunde_);
	else TimeToShow = " 0 : " + std::to_string((int)counter_secunde_);
		
	Timer.setString(TimeToShow);
}

void ReturnToMenu(unsigned int & level, sf::FloatRect BackToMenuDim, sf::Vector2f MousePressedPos)
{
	if (BackToMenuDim.contains(MousePressedPos)) level = 0;
}


