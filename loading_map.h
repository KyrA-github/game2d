#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Graphics/Texture.hpp>
#include <fstream>
#include "json/include/nlohmann/json.hpp"
#include "global.h"

using namespace sf;

class loading_map
{
public:
	Sprite sprite;
	bool tile_bool;
	int tile_x;
	int tile_y;
	int tilenumder;

	loading_map(Texture& image);

	void read_file();
	void draw(RenderWindow& window);
	
};

