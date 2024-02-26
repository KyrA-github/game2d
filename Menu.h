#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "global.h"

using namespace sf;

#define max_text 5
#define max_text_level 2

class Menu
{
	public:

		Sprite background_sprite, button_play;
		FloatRect rect_play;
		bool press_button_w = true;
		bool press_button_s = true;
		int menu_v = 1;
		

		Menu(Texture& background_img);

		void menu(RenderWindow& window);
		void levels(RenderWindow& window);
		void options(RenderWindow& window);
		void draw_menu(RenderWindow& window);
		void draw_menu_index(RenderWindow& window);
		void control(RenderWindow& window);

	private:
		Font font;
		Text MainMenu[max_text];
		Text Levels[max_text];
};
