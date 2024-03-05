#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"
#include "Entity.h"

class PLAYER : public Entity
{
public:
	float currentFrame;
	int player_textur_w = 32;
	int player_textur_h = 32;
	bool last_viewed = false;

	PLAYER(Texture& image, float X, float Y, int W, int H);
	void control(float time);
	void update(float time);
	void Collision(int dir);
};

