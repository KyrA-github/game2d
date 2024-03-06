#include "consoll_game.h"

consoll_game::consoll_game() {

	if (!font.loadFromFile("data_game/font/text4.otf"))
	{
		std::cout << "ERROR FONT";
	}
	
}


void consoll_game::control()
{

	if (Keyboard::isKeyPressed(Keyboard::F1) && press_f1 ) {
		press_f1 = false;
		if (!consoll_start) {
			consoll_start = true;
		}
		else
		{
			consoll_start = false;
		}
	}
	else if(!Keyboard::isKeyPressed(Keyboard::F1))
	{
		press_f1 = true;
	}
}

void consoll_game::text_up(RenderWindow& window)
{
	pos = player.dx_;
	std::cout << pos;
	text = std::to_string(offsetX) + " " + std::to_string(offsetY) + " " + std::to_string(player.dx_)
		+ " " + std::to_string(pos);
	
	consoll_text.setFont(font);
	consoll_text.setFillColor(Color::White);
	consoll_text.setString(text);
	consoll_text.setCharacterSize(15);
	consoll_text.setPosition(5, 5);
	if (consoll_start) {
		window.draw(consoll_text);
	}
	
}
