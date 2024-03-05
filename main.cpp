#include <SFML/Graphics.hpp>
#include <iostream>
#include "global.h"
#include "Menu.h"
#include "Player_game.h"
#include "loading_map.h"
#include "PLAYER.h"


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
	
	RenderWindow window(VideoMode(1366, 768), "CRAZY FROG");

	loading_map gameMap(textur_map);
	Menu menu_game_main(menu_background);
	PLAYER player_1(skin1, 1, 1, 32 ,32);
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
		//menu
		if (current_scene == 1) {
			menu_game_main.menu(window);
		}
		//game
		else if (current_scene == 2) {
			player_1.control(time);

			window.clear(Color::White);

			gameMap.draw(window);

			window.draw(player_1.getSprite());
		}
		//info
		else if (current_scene == 3) {
			menu_game_main.info(window);
		}
		//close
		else if (current_scene == 4) {
			window.close();
		}

		window.display();
	}

	return 0;
}
