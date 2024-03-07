#include "PLAYER.h"

void PLAYER::info_class(Texture& image, float X, float Y, int W, int H)
{
	info(image, X, Y, W, H);

	rect = FloatRect(7 * H, 9 * W, H, W);
	dx = dy = 0.1;
	currentFrame = 0;
}

void PLAYER::control(float time)
{
	
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		dx = -0.08;
		last_viewed = false;
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		dx = 0.08;
		last_viewed = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		if (onGround) { dy = -0.30; onGround = false; }
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape) && press_button_esc)
	{
		press_button_esc = false;
		current_scene = 1;
	}
	else if (!Keyboard::isKeyPressed(Keyboard::Escape)) {
		press_button_esc = true;
	}

	update(time);

	

	offsetY = -70;
	offsetX = -150;
	//if (rect.left > 683) offsetX = rect.left - 583;
	//offsetY = rect.top - 659;
}

void PLAYER::update(float time)
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

void PLAYER::Collision(int dir)
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