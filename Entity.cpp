#include "Entity.h"

void Entity::info(Texture& image, float X, float Y, int W, int H)
{
	x = X; y = Y;
	h = H; w = W; 
	moveTimer = 0;
	speed = 0;
	health = 100;
	dx = 0;
	dy = 0;
	life = true;
	onGround = false;
	isMove = false;
	sprite.setTexture(image);
}

Sprite Entity::getSprite() const
{
	return sprite; 
}
