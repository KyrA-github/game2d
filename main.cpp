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

int Tilemap[matrix_h][matrix_w];


class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int player_textur_w = 50;
	int player_textur_h = 70;
	bool animation_on_off = true;

	PLAYER(Texture& image)
	{
		sprite.setTexture(image);
		rect = FloatRect(7 * 32, 9 * 32, 50, 69);

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


		if (animation_on_off) {
			
		}

		if (dx > 0) 
		{
			animation_on_off = false;
			currentFrame += 0.005 * time;
			if (currentFrame > 7) currentFrame -= 7;
			sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame), 60, player_textur_w, player_textur_h));
		}
		else
		{
			animation_on_off = true;
		}
		if (dx < 0)
		{ 
			animation_on_off = false;
			currentFrame += 0.005 * time;
			if (currentFrame > 7) currentFrame -= 7;
			sprite.setTextureRect(IntRect(player_textur_w * int(currentFrame) + player_textur_w, 60, -player_textur_w, player_textur_h));
		}
		else
		{
			animation_on_off = true;
		}
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);
		dx = 0;
	}

	void Collision(int dir)
	{
		for (int i = rect.top / tile; i < (rect.top + rect.height) / tile; i++)
			for (int j = rect.left / tile; j < (rect.left + rect.width) / tile; j++)
			{
				if (Tilemap[i][j] == 202)
				{
					if ((dx > 0) && (dir == 0)) rect.left = j * tile - rect.width;
					if ((dx < 0) && (dir == 0)) rect.left = j * tile + tile;
					if ((dy > 0) && (dir == 1)) { rect.top = i * tile - rect.height;  dy = 0;   onGround = true; }
					if ((dy < 0) && (dir == 1)) { rect.top = i * tile + tile;   dy = 0; }
				}

				if (Tilemap[i][j] == 1)
				{
					Tilemap[i][j] = 0;
				}

			}

	}
};

class Map
{
public:
	Sprite sprite;
	int groundLayer[matrix_h][matrix_w];
	int treeLayer[matrix_h][matrix_w];

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
				auto groundData = layers[0]["data"];
				auto treeData = layers[1]["data"];

				for (int j = 0; j < matrix_w; j++)
				{
					Tilemap[i][j] = groundData[i * matrix_w + j];
					treeLayer[i][j] = treeData[i * matrix_w + j];
				}
			}
		}
		catch (const nlohmann::json::exception& e)
		{
			std::cerr << "Error reading JSON: " << e.what() << std::endl;
		}
	}

	void draw()
	{
		for (int i = 0; i < matrix_h; i++)
		{
			for (int j = 0; j < matrix_w; j++)
			{
				int groundTile = groundLayer[i][j];
				int treeTile = treeLayer[i][j];

				// ќтрисовка плитки земли (ground)
				if (groundTile != 0)
				{
					// ... ваш код отрисовки земли ...
				}

				// ќтрисовка плитки дерева (tree)
				if (treeTile != 0)
				{
					// ... ваш код отрисовки дерева ...
				}
			}
		}
	}

};


int main()
{
	Map gameMap;
	gameMap.read_file();

	RenderWindow window(VideoMode(600, 400), "Test!");

	Texture skin1, textur_map;
	skin1.loadFromFile("data_game/img/players_skin/skin_1/Walk.png");
	textur_map.loadFromFile("data_game/map/textur_map/set1.png");

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

		}

		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			p.dx = 0.08;
		}

		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			if (p.onGround) { p.dy = -0.35; p.onGround = false; }
		}

		p.update(time);

		if (p.rect.left > 300) offsetX = p.rect.left - 300;
		offsetY = p.rect.top - 200;

		window.clear(Color::White);
		for (int i = 0; i < matrix_h; i++)
			for (int j = 0; j < matrix_w; j++)
			{
				if (Tilemap[i][j] != 0) 
				{
					bool tile_bool = true;
					int tile_x = 16;
					int tile_y = 16;
					int tilenumder = Tilemap[i][j];
					tile_x = tilenumder * tile_x;
					while (true)
					{
						if (tile_x > 528) {
						tile_x = tile_x - 528;
						tile_y = tile_y + 16;
						}
						else
						{
							tile_bool = false;
						}
					}
					gameMap.sprite.setTextureRect(IntRect(0, 0, tile, tile));
				}
				gameMap.sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
				window.draw(gameMap.sprite);
			}
		window.draw(p.sprite);
		window.display();
	}

	return 0;
}

