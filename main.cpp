#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "json/include/nlohmann/json.hpp"
#include "global.h"
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


int main()
{
	Texture skin1, textur_map;
	skin1.loadFromFile("data_game/img/players_skin/s1/gab.png");
	textur_map.loadFromFile("data_game/map/texture_map/set3.png");

	loading_map gameMap(textur_map);
	gameMap.read_file();

	RenderWindow window(VideoMode(600, 400), "Game2d");

	Player_game p(skin1);

	Clock clock;

	RectangleShape rectangle(Vector2f(tile, tile));

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

		if (p.rect.left > 300) offsetX = p.rect.left - 300;
		offsetY = p.rect.top - 200;

		window.clear(Color::White);

		gameMap.draw(window);

		window.draw(p.sprite);
		window.display();
	}

	return 0;
}
