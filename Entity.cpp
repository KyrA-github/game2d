#include "Entity.h"

Entity::Entity(Image& image, float X, float Y, int W, int H, String Name)
{
	x = X; y = Y; h = H; name = Name; moveTimer = 0;
	speed = 0; health = 100; dx = 0; dy = 0;
	life = true; onGround = false; isMove = false;
	sprite.setTexture(texture);
	sprite.setOrigin(w / 2, h / 2);
}
