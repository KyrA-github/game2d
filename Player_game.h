#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"

using namespace sf;

class Player_game
{
public:
	Player_game(Texture& image);
	float dx, dy;
	FloatRect rect;
	bool onGround;
	Sprite sprite;
	float currentFrame;
	int player_textur_w = 32;
	int player_textur_h = 32;
	bool last_viewed = false;

	void update(float time);
	void Collision(int dir);
};

