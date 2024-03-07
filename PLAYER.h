#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"
#include "Entity.h"

class PLAYER : public Entity
{
public:
	void info_class(Texture& image, float X, float Y, int W, int H);
	void control(float time);
private:
	float currentFrame, dx_, dy_;
	int player_textur_w = 32;
	int player_textur_h = 32;
	bool last_viewed = false;
	bool press_button_esc = true;
	void update(float time);
	void Collision(int dir);
};

