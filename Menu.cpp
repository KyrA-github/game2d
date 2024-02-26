#include "Menu.h"

Menu::Menu(Texture& background_img)
{
	background_sprite.setTexture(background_img);
	rect_play = FloatRect(0,0, 80, 21);
    if (!font.loadFromFile("data_game/font/text3.otf")) 
    {
        std::cout << 4;
    }
}

void Menu::menu(RenderWindow& window)
{
    MainMenu[0].setFont(font);
    MainMenu[0].setFillColor(Color::Black);
    MainMenu[0].setString("Play");
    MainMenu[0].setCharacterSize(20);
    MainMenu[0].setPosition(350, 400);

    // Получение текущей позиции мыши
    Vector2i mousePosition = Mouse::getPosition(window);


    // Проверка нажатия на кнопку Play
    

    //window.draw(background_sprite);
    //window.draw(button_play);
    //window.draw(MainMenu);
}

void Menu::levels(RenderWindow& window)
{
    Levels[0].setFont(font);
    Levels[0].setFillColor(Color::Black);
    Levels[0].setString("Play");
    Levels[0].setCharacterSize(20);
    Levels[0].setPosition(300, 400);

    // Получение текущей позиции мыши
    Vector2i mousePosition = Mouse::getPosition(window);



    // Проверка нажатия на кнопку Play
   /* if (rect_play.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
        if (Mouse::isButtonPressed(Mouse::Left) && press_button) {
            std::cout << "Button Play Pressed!" << std::endl;
            press_button = false;
            current_scene = 3;
        }
        else if (!Mouse::isButtonPressed(Mouse::Left)) {
            press_button = true;
        }
    }*/
}

void Menu::options(RenderWindow& window)
{
}

void Menu::draw_menu(RenderWindow& window)
{
    window.draw(background_sprite);
    for (int i = 0; i < max_text; i++) {
        window.draw(MainMenu[i]);
    }
}
