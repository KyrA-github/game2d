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
    //Vector2i mousePosition = Mouse::getPosition(window);

    MainMenu[0].setFont(font);
    MainMenu[0].setFillColor(Color::Black);
    MainMenu[0].setString("Play");
    MainMenu[0].setCharacterSize(20);
    MainMenu[0].setPosition(100, 500);


    MainMenu[1].setFont(font);
    MainMenu[1].setFillColor(Color::Black);
    MainMenu[1].setString("info");
    MainMenu[1].setCharacterSize(20);
    MainMenu[1].setPosition(100, 550);

    MainMenu[2].setFont(font);
    MainMenu[2].setFillColor(Color::Black);
    MainMenu[2].setString("Options");
    MainMenu[2].setCharacterSize(20);
    MainMenu[2].setPosition(100, 600);

    MainMenu[3].setFont(font);
    MainMenu[3].setFillColor(Color::Black);
    MainMenu[3].setString("Exit");
    MainMenu[3].setCharacterSize(20);
    MainMenu[3].setPosition(100, 650);

    control(window);
    
    switch (menu_v)
    { 
    case 1:
        MainMenu[0].setFillColor(Color::White);
        break;
    case 2:
        MainMenu[1].setFillColor(Color::White);
        break;
    case 3:
        MainMenu[2].setFillColor(Color::White);
        break;
    case 4:
        MainMenu[3].setFillColor(Color::White);
        break;
    default:
        break;
    }

}

void Menu::levels(RenderWindow& window)
{
    //Levels[0].setFont(font);
    //Levels[0].setFillColor(Color::Black);
    //Levels[0].setString("Play");
    //Levels[0].setCharacterSize(20);
    //Levels[0].setPosition(300, 400);


    //Vector2i mousePosition = Mouse::getPosition(window);


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

void Menu::draw_menu_index(RenderWindow& window)
{
}

void Menu::control(RenderWindow& window)
{
    if (Keyboard::isKeyPressed(Keyboard::W) && press_button_w)
    {
        press_button_w = false;
        if (menu_v != 1) {
            menu_v--;
        }
        else
        {
            menu_v = 4;
        }
    }
    else if (!Keyboard::isKeyPressed(Keyboard::W))
    {
        press_button_w = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::S) && press_button_s**)
    {
        std::cout << 5;
        press_button_s = false;
        if (menu_v != 4) {
            menu_v++;
        }
        else
        {
            menu_v = 1;
        }
    }else if (!Keyboard::isKeyPressed(Keyboard::S)){
        std::cout << 6;
        press_button_s = true;
    }
    
}
