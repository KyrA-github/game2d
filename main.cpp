#include <SFML/Graphics.hpp>
#include <iostream>
#include "global.h"
#include "Menu.h"
#include "Player_game.h"
#include "loading_map.h"


using namespace sf;

float offsetX = 0;
float offsetY = 0;
int tile = 16;
int matrix_h = 65;
int matrix_w = 100;
int groundLayer[65][100];
int treeLayer[65][100];
int current_scene = 1;


int main()
{
	Texture skin1, textur_map, menu_background, menu_button_play;
	skin1.loadFromFile("data_game/img/players_skin/s1/gab.png");
	textur_map.loadFromFile("data_game/map/texture_map/texture.png");
	menu_background.loadFromFile("data_game/img/menu/background/background1366-768.png");

	
	
	RenderWindow window(VideoMode(1366, 768), "Game2d");

	loading_map gameMap(textur_map);
	Menu menu_game_main(menu_background);
	Player_game p(skin1);
	Clock clock;
	RectangleShape rectangle(Vector2f(tile, tile));

	gameMap.read_file();

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 700;

		if (time > 20) time = 20;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		//game
		if (current_scene == 2) {
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				p.dx = -0.08;
				p.last_viewed = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				p.dx = 0.08;
				p.last_viewed = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				if (p.onGround) { p.dy = -0.35; p.onGround = false; }
			}

			p.update(time);

			if (p.rect.left > 683) offsetX = p.rect.left - 683;
			offsetY = p.rect.top - 459;
				
			window.clear(Color::White);

			gameMap.draw(window);

			window.draw(p.sprite);
		}
		//menu
		else if (current_scene == 1) {
			menu_game_main.menu(window);
			menu_game_main.draw_menu(window);
		}
		//levels
		else if (current_scene == 3) {
			menu_game_main.menu(window);
			
		}
		window.display();
	}

	return 0;
}
