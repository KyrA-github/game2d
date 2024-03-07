#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"

using namespace sf;

class Entity
{
protected:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	FloatRect rect;

	void info(Texture& image, float X, float Y, int W, int H);
public:
	Sprite getSprite() const;
};

