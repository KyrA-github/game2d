#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "global.h"

using namespace sf;

#define max_text 2
#define max_text_level 2

class Menu
{
	public:

		Sprite background_sprite, button_play;
		FloatRect rect_play;
		bool press_button = true;
		int menu_v = 1;
		

		Menu(Texture& background_img);

		void menu(RenderWindow& window);
		void levels(RenderWindow& window);
		void options(RenderWindow& window);
		void draw_menu(RenderWindow& window);

	private:
		Font font;
		Text MainMenu[max_text];
		Text Levels[max_text];
};
