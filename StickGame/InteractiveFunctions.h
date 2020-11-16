#pragma once

#include <iostream>
#include "EnemyContainer.h"
#include "Enemy.h"
#include "Player.h"

void EnemyGun_Fire(EnemyContainer enemies, Player& player);
void PlayerUpdateHealthBar(Player& player,sf::Sprite& HealthBarSprite);
void PlayerGun_Fire(Player& player, EnemyContainer enemies , sf::Vector2f MousePressedPos,sf::Vector2f MouseMovePos);