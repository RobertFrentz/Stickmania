#pragma once

#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "EnemyContainer.h"
#include <windows.h>

void EnemyGun_Fire(EnemyContainer& enemies, Player& player);
void PlayerUpdateHealthBar(Player& player, sf::Sprite& HealthBarSprite,float X,float Y);
void EnemyRespawnTimeFunc(EnemyContainer& enemies);
void PlayerGun_Fire(Player& player, EnemyContainer& enemies, sf::Vector2f MousePressedPos, sf::Vector2f MouseMovePos,unsigned int &killcount);
void time_counter(unsigned int level, sf::Clock& clock, sf::Text& Timer, float X, float Y);
void ReturnToMenu(unsigned int& level, sf::FloatRect BackToMenuDim,sf::Vector2f MousePressedPos);