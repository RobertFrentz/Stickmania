
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <thread>
#include "Gun.h"
#include "Enemy.h"
#include "Player.h"
#include "EnemyContainer.h"
#include "Interactive_Functions.h"

int main()
{
	unsigned int Level = 0;
	float X = 1518;
	float Y = 900;
	unsigned int killcount = 0;

	sf::Music Background_Music;
	Background_Music.openFromFile("Music/RockyMusic.wav");
	Background_Music.play();


	sf::RenderWindow window(sf::VideoMode((int)X,(int)Y),"My Game");
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);

	sf::Font font;
	if (!font.loadFromFile("shadow.otf"))
		return 0;

	sf::Text menu_text1("Play Game", font);
	sf::Text menu_text2("Quit", font);
	sf::Text Timer;
	sf::Text BackToMenuOption("Main Menu", font);


	BackToMenuOption.setPosition(X - 270, Y / 2 - 450);
	menu_text1.setPosition(X / 2 - 200, Y / 2 - 250);
	menu_text2.setPosition(X / 2 - 200, Y / 2 - 50);
	Timer.setPosition(X / 2 - 100, Y / 2 - 450);
	menu_text1.setCharacterSize(130);
	menu_text2.setCharacterSize(130);
	Timer.setCharacterSize(50);
	BackToMenuOption.setCharacterSize(50);
	Timer.setFont(font);

	sf::FloatRect Text1Dim = menu_text1.getGlobalBounds();
	sf::FloatRect Text2Dim = menu_text2.getGlobalBounds();
	sf::FloatRect BackToMenuDim = BackToMenuOption.getGlobalBounds();
	
	
    sf::Texture Menu_Background, FirstLevelBackground,Player_Texture,Enemy_Texture,Health_Bars_Texture,Cursor_Texture;

	if (!Menu_Background.loadFromFile("Textures/Main_Menu_Background.png"))
		return 0;
	
	if (!FirstLevelBackground.loadFromFile("Textures/FirstLevel.png"))
        return 0;

	if (!Player_Texture.loadFromFile("Textures/Player_Texture.png",sf::IntRect(0,0,200,250)))
		return 0;

	if (!Enemy_Texture.loadFromFile("Textures/Enemy_Texture.png", sf::IntRect(0, 0, 110, 240)))
		return 0;

	if (!Health_Bars_Texture.loadFromFile("Textures/Health_Bar_Texture.png"))
	    return 0;
	if (!Cursor_Texture.loadFromFile("Textures/Cursor_Texture.png"))
	    return 0;

	sf::Sprite Menu_Background_sprite, FirstLevelBackground_sprite, Player_Sprite, Enemy_Sprite1, Enemy_Sprite2, Enemy_Sprite3, Health_Bars_Sprite, CursorImage_sprite;

	CursorImage_sprite.setTexture(Cursor_Texture);
	//CursorImage_sprite.setTextureRect(sf::IntRect(0, 0, 350, 600)); //DEFAULT CURSOR
	//CursorImage_sprite.setTextureRect(sf::IntRect(350, 0, 600, 600)); //TARGET CURSOR
	Menu_Background_sprite.setTexture(Menu_Background);
	FirstLevelBackground_sprite.setTexture(FirstLevelBackground);
	Player_Sprite.setTexture(Player_Texture);
	Enemy_Sprite1.setTexture(Enemy_Texture);
	Enemy_Sprite2 = Enemy_Sprite1;
	Enemy_Sprite3 = Enemy_Sprite1;
	Health_Bars_Sprite.setTexture(Health_Bars_Texture);
	Health_Bars_Sprite.setTextureRect(sf::IntRect(40, 0, 225, 80));
	Health_Bars_Sprite.setScale(0.8f, 0.8f);
	//CursorImage_sprite.setScale(0.15f, 0.15f);    //TARGET CURSOR
	//CursorImage_sprite.setScale(0.07f, 0.07f);  //DEFAULT CURSOR


	Gun PlayerGun("AK-47", 90);
	Gun EnemyGun("P99 Pistol", 5);
	EnemyContainer _EnemyContainer;
	Enemy* enemyPtr = nullptr;
	Enemy enemy1(Enemy_Sprite1, EnemyGun); enemyPtr = &enemy1; _EnemyContainer.AddEnemy(enemyPtr);
	Enemy enemy2(Enemy_Sprite2, EnemyGun); enemyPtr = &enemy2; _EnemyContainer.AddEnemy(enemyPtr);
	Enemy enemy3(Enemy_Sprite3, EnemyGun); enemyPtr = &enemy3; _EnemyContainer.AddEnemy(enemyPtr);
	Player player(Player_Sprite,PlayerGun);

	Player_Sprite.setPosition(X - 330, Y - 315);
	Enemy_Sprite1.setPosition(180.0f, Y - 330);
	Enemy_Sprite2.setPosition(80.0f, Y - 250);
	Enemy_Sprite3.setPosition(5.0f, Y - 400);
	Health_Bars_Sprite.setPosition(X - 300, Y - 380);
	CursorImage_sprite.setPosition(X / 2 - 200, Y / 2 - 250);


	sf::FloatRect Enemy1Rect = Enemy_Sprite1.getGlobalBounds(); _EnemyContainer.AddEnemyRect(Enemy1Rect);
	sf::FloatRect Enemy2Rect = Enemy_Sprite2.getGlobalBounds(); _EnemyContainer.AddEnemyRect(Enemy2Rect);
	sf::FloatRect Enemy3Rect = Enemy_Sprite3.getGlobalBounds(); _EnemyContainer.AddEnemyRect(Enemy3Rect);

	
	sf::Clock* enemyClockPtr = nullptr;
	sf::Clock Enemy1RespawnTime; enemyClockPtr = &Enemy1RespawnTime; _EnemyContainer.AddEnemyRespawnTime(enemyClockPtr);
	sf::Clock Enemy2RespawnTime; enemyClockPtr = &Enemy2RespawnTime; _EnemyContainer.AddEnemyRespawnTime(enemyClockPtr);
	sf::Clock Enemy3RespawnTime; enemyClockPtr = &Enemy3RespawnTime; _EnemyContainer.AddEnemyRespawnTime(enemyClockPtr);
	
	sf::Clock* enemyShootPtr = nullptr;
	sf::Clock Enemy1Shoot; enemyShootPtr = &Enemy1Shoot; _EnemyContainer.AddEnemyShootTime(enemyShootPtr);
	sf::Clock Enemy2Shoot; enemyShootPtr = &Enemy2Shoot; _EnemyContainer.AddEnemyShootTime(enemyShootPtr);
	sf::Clock Enemy3Shoot; enemyShootPtr = &Enemy3Shoot; _EnemyContainer.AddEnemyShootTime(enemyShootPtr);
	sf::Clock TimePassed;


	while (window.isOpen())
	{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				    window.close();
				if (event.type == sf::Event::MouseMoved)
				{
					
					sf::Vector2f MousePos((float)event.mouseMove.x, (float)event.mouseMove.y);

					switch (Level) {
					
					
					   case 0:
					   {
						    CursorImage_sprite.setTextureRect(sf::IntRect(0, 0, 350, 600));
						    CursorImage_sprite.setScale(0.07f, 0.07f);
							CursorImage_sprite.setPosition(MousePos);
						    if (Text1Dim.contains(MousePos)) menu_text1.setCharacterSize(140);
						    else if (Text2Dim.contains(MousePos)) menu_text2.setCharacterSize(140);
						    else {
							       menu_text1.setCharacterSize(130);
							       menu_text2.setCharacterSize(130);
						         }
							break;
	
					   }
					   case 1:
					   {
						   if (BackToMenuDim.contains(MousePos)) 
						   {
							  CursorImage_sprite.setTextureRect(sf::IntRect(0, 0, 350, 600));
							  CursorImage_sprite.setScale(0.07f, 0.07f);
							  CursorImage_sprite.setPosition(MousePos);
						      BackToMenuOption.setCharacterSize(60);
						   }
						   else 
						   {
							   CursorImage_sprite.setTextureRect(sf::IntRect(350, 0, 600, 600));
							   CursorImage_sprite.setScale(0.15f, 0.15f);
							   CursorImage_sprite.setPosition(MousePos);
						       BackToMenuOption.setCharacterSize(50);
						   }
					   }
				     }

				}
				
			}

			time_counter(Level, TimePassed, Timer, X, Y);

			switch (Level) {

			     case 0:
				      break;
				 case 1:
				 {
					//EnemyGun_Fire(_EnemyContainer, player);
					//PlayerUpdateHealthBar(player, Health_Bars_Sprite,X,Y);
					EnemyRespawnTimeFunc(_EnemyContainer);
				 }
			}

			if (player.getHealth() == 0)
			{
				std::cout << std::endl << std::endl << std::endl << "YOU LOST!";
				std::cout << std::endl << killcount;
				break;
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				
				sf::Vector2i Mouse_Position = sf::Mouse::getPosition(window);
				switch (Level) {

				      case 0:
				      {
					      if (Text1Dim.contains((float)Mouse_Position.x, (float)Mouse_Position.y))
						    Level = 1;
					      if (Text2Dim.contains((float)Mouse_Position.x, (float)Mouse_Position.y))
						    window.close();
				      }

				      case 1:
					  {
						  sf::sleep(sf::milliseconds(150));
						  sf::Vector2f MousePressedPos((float)event.mouseButton.x, (float)event.mouseButton.y);
						  sf::Vector2f MouseMovePos((float)event.mouseMove.x, (float)event.mouseMove.y);

						  PlayerGun_Fire(player, _EnemyContainer, MousePressedPos, MouseMovePos,killcount);
						  ReturnToMenu(Level, BackToMenuDim, MousePressedPos);
						  
				      }
			    }
			}

			

		    window.clear();
		    switch (Level) {
			      case 0 :
				  {
					  window.draw(Menu_Background_sprite);
					  window.draw(menu_text1);
					  window.draw(menu_text2);
					  window.draw(CursorImage_sprite);
					  break;
				  }
				  case 1 :
				  {
					  window.draw(FirstLevelBackground_sprite);
					  window.draw(Player_Sprite);
					  window.draw(Health_Bars_Sprite);
					  window.draw(Timer);
					  window.draw(BackToMenuOption);
					  if (enemy1.getStatus() != "Killed") window.draw(Enemy_Sprite1);
					  if (enemy2.getStatus() != "Killed") window.draw(Enemy_Sprite2);
					  if (enemy3.getStatus() != "Killed") window.draw(Enemy_Sprite3);
					  window.draw(CursorImage_sprite);
					  break;
				  }
		   }
		   window.display();
	} 

}




