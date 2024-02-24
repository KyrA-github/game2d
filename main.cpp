#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include "json/include/nlohmann/json.hpp"


using namespace sf;

float offsetX = 0, offsetY = 0;

const int tile = 16;

const int matrix_h = 65;
const int matrix_w = 100;

int groundLayer[matrix_h][matrix_w];
int treeLayer[matrix_h][matrix_w];


class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int player_textur_w = 32;
	int player_textur_h = 32;
	bool last_viewed = false;


	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(7 * 32, 9 * 32, 32, 32);

		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{


		rect.left += dx * time;
		Collision(0);

		if (!onGround) dy = dy + 0.0005 * time;
		rect.top += dy * time;
		onGround = false;
		Collision(1);



		if (dy > 0.0003)
		{
			if (last_viewed) {
				currentFrame += 0.01 * time;
				if (currentFrame > 1) currentFrame -= 1;
				sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame), 128, player_textur_w, player_textur_h));
				
			}
			else {
				currentFrame += 0.01 * time;
				if (currentFrame > 1) currentFrame -= 1;
				sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame) + player_textur_w, 128, -player_textur_w, player_textur_h));	
			}
			
			
		}
		else if (dx < 0)
		{
			currentFrame += 0.01 * time;
			if (currentFrame > 12) currentFrame -= 12;
			sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame) + player_textur_w, 0, -player_textur_w, player_textur_h));
		}
		else if (dx > 0)
		{
			currentFrame += 0.01 * time;
			if (currentFrame > 12) currentFrame -= 12;
			sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame), 0, player_textur_w, player_textur_h));
		}
		else
		{
			if (last_viewed) {
				currentFrame += 0.01 * time;
				if (currentFrame > 11) currentFrame -= 11;
				sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame), 32, player_textur_w, player_textur_h));
		
			}
			else
			{
				currentFrame += 0.01 * time;
				if (currentFrame > 11) currentFrame -= 11;
				sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame) + player_textur_w, 32, -player_textur_w, player_textur_h));

			}
		}


		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
	}

	void Collision(int dir)
	{
		for (int i = rect.top / tile; i < (rect.top + rect.height) / tile; i++)
			for (int j = rect.left / tile; j < (rect.left + rect.width) / tile; j++)
			{
				if (groundLayer[i][j] != 0)
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * tile - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * tile + tile;
					if ((dy > 0) && (dir == 1)) { rect.top = i * tile - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * tile + tile;   dy = 0; }
				}

			}

	}
};

class Map
{
public:
	Sprite sprite;
	bool tile_bool;
	int tile_x;
	int tile_y;
	int tilenumder;
	void map_sprite(Texture& image)
	{
		sprite.setTexture(image);
	}
	void read_file()
	{
		try
		{
			nlohmann::json objJson;
			std::fstream fileInput;
			fileInput.open("data_game/map/map.json");
			fileInput >> objJson;
			fileInput.close();

			auto layers = objJson["layers"];
			for (int i = 0; i < matrix_h; i++)
			{
				auto groundData = layers[1]["data"];
				auto treeData = layers[0]["data"];

				for (int j = 0; j < matrix_w; j++)
				{
					groundLayer[i][j] = groundData[i * matrix_w + j];
					treeLayer[i][j] = treeData[i * matrix_w + j];
				}
			}
		}
		catch (const nlohmann::json::exception& e)
		{
			std::cerr << "Error reading JSON: " << e.what() << std::endl;
		}
	}

	void draw(RenderWindow& window)
	{
		for (int i = 0; i < matrix_h; i++)
		{
			for (int j = 0; j < matrix_w; j++)
			{
				int groundTile = groundLayer[i][j];
				int treeTile = treeLayer[i][j];

				if (groundTile != 0)
				{
					tile_bool = true;
					tile_x = 16;
					tile_y = 16;
					tilenumder = groundLayer[i][j];
					tile_x = tilenumder * tile_x;
					while (tile_bool)
					{
						if (tile_x > 96)
						{
							tile_x = tile_x - 96;
							tile_y = tile_y + 16;
						}
						else
						{
							tile_bool = false;
						}
					}
					sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
					sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
					window.draw(sprite);

				}

				if (treeTile != 0)
				{
					tile_bool = true;
					tile_x = 16;
					tile_y = 16;
					tilenumder = treeLayer[i][j];
					tile_x = tilenumder * tile_x;
					while (tile_bool)
					{
						if (tile_x > 96)
						{
							tile_x = tile_x - 96;
							tile_y = tile_y + 16;
						}
						else
						{
							tile_bool = false;
						}
					}
					sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
					sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
					window.draw(sprite);
				}
			}
		}
	}

};


int main()
{
	Map gameMap;
	gameMap.read_file();

	RenderWindow window(VideoMode(600, 400), "Game2d");

	Texture skin1, textur_map;
	skin1.loadFromFile("data_game/img/players_skin/s1/gab.png");
	textur_map.loadFromFile("data_game/map/texture_map/set3.png");

	float currentFrame = 0;

	PLAYER p(skin1);
	gameMap.map_sprite(textur_map);

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
