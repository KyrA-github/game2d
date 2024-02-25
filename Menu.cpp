#include "Menu.h"

Menu::Menu(Texture& background_img)
{
	background_sprite.setTexture(background_img);
}

void Menu::menu(RenderWindow& window)
{
	MainMenu.setFont(font);
	MainMenu.setFillColor(Color::White);
	MainMenu.setString("Play");
	MainMenu.setCharacterSize(20);
	MainMenu.setPosition(300, 400);
	window.draw(MainMenu);
	window.draw(background_sprite);
}

void Menu::options(RenderWindow& window)
{
}

void Menu::draw_menu(RenderWindow& window)
{
	/*for (int i = 0; i < Max_main_menu; i++) {
		window.draw(MainMenu[i]);
	}*/
	window.draw(MainMenu);
	window.draw(background_sprite);
}
