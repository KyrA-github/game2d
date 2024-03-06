#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"
#include "PLAYER.h"
using namespace sf;

class consoll_game
{
public:
	consoll_game();
	void control();	
	void text_up(RenderWindow& window);
private:
	float pos;
	PLAYER player;
	bool consoll_start;
	bool press_f1;
	Font font;
	Text consoll_text;
	std::string text;
};

