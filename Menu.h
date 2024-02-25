#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "global.h"


using namespace sf;

class Menu
{
	public:
		Sprite background_sprite;

		Menu(Texture& background_img);

		void menu(RenderWindow& window);
		void options(RenderWindow& window);
		void draw_menu(RenderWindow& window);

	private:
		Font font;
		Text MainMenu;
};

