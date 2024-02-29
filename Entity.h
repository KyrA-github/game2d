#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"

using namespace sf;

class Entity
{
public:
	float dx, dy, x, y, speed, moveTimer;
	int w, h, health;
	bool life, isMove, onGround;
	Texture texture;
	Sprite sprite;
	String name;

	Entity(Image& image, float X, float Y, int W, int H, String Name);
};

