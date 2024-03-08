#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "global.h"
#include "Entity.h"

class enemy : public Entity
{
public:
	void info_class(Texture& image, float X, float Y, int W, int H);
	void control(float time);
private:
	float currentFrame;
	int player_textur_w = 32, player_textur_h = 32, enemy_walk = 0;
	bool last_viewed = false, press_button_esc = true, enemy_walk_ = true;
	void update(float time);
	void Collision(int dir);
};


