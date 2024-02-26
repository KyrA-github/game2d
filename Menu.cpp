#include "Menu.h"

Menu::Menu(Texture& background_img)
{
	background_sprite.setTexture(background_img);
	rect_play = FloatRect(0,0, 80, 21);
    if (!font.loadFromFile("data_game/font/text3.otf")) 
    {
        std::cout << "ERROR FONT";
    }
    if (!font_info.loadFromFile("data_game/font/text2.ttf"))
    {
        std::cout << "ERROR FONT";
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

    MainMenu[4].setFont(font_info);
    MainMenu[4].setFillColor(Color::White);
    MainMenu[4].setString(version);
    MainMenu[4].setCharacterSize(20);
    MainMenu[4].setPosition(0, 745);



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
    draw_menu(window);
}

void Menu::info(RenderWindow& window)
{
    MainMenu_info[0].setFont(font_info);
    MainMenu_info[0].setFillColor(Color::Black);
    MainMenu_info[0].setString("The game is written in C++\nwith the sfml library without an engine");
    MainMenu_info[0].setCharacterSize(50);
    MainMenu_info[0].setPosition(100, 500);

    MainMenu_info[1].setFont(font_info);
    MainMenu_info[1].setFillColor(Color::Black);
    MainMenu_info[1].setString("It is an open source project\n can be downloaded on the author’s github\nhttps://github.com/KyrA-github/game2d");
    MainMenu_info[1].setCharacterSize(50);
    MainMenu_info[1].setPosition(550, 100);

    MainMenu_info[2].setFont(font);
    MainMenu_info[2].setFillColor(Color::White);
    MainMenu_info[2].setString("Back");
    MainMenu_info[2].setCharacterSize(20);
    MainMenu_info[2].setPosition(100, 650);
    

    control(window);
    draw_menu_info(window);
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

void Menu::draw_menu_info(RenderWindow& window)
{
    window.draw(background_sprite);
    for (int i = 0; i < max_text_info; i++) {
        window.draw(MainMenu_info[i]);
    }
}

void Menu::control(RenderWindow& window)
{
    if (Keyboard::isKeyPressed(Keyboard::W) && press_button_w)
    {
        press_button_w = false;
        if (current_scene == 1) 
        {
            if (menu_v != 1) {
                menu_v--;
            }
            else
            {
                menu_v = 4;
            }
        }  
    }
    else if (!Keyboard::isKeyPressed(Keyboard::W))
    {
        press_button_w = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::S) && press_button_s)
    {
        press_button_s = false;
        if (current_scene == 1)
        { 
            if (menu_v != 4) 
            {
            menu_v++;
            }
            else
            {
                menu_v = 1;
            }
        }
       
    }else if (!Keyboard::isKeyPressed(Keyboard::S)){
        press_button_s = true;
    }

    if (Keyboard::isKeyPressed(Keyboard::Enter) && press_button_enter)
    {
        press_button_enter = false;
        switch (current_scene)
        {
        case 1:
            switch (menu_v)
            {
            case 1:
                current_scene = 2;
                break;
            case 2:
                current_scene = 3;
                break;
            case 3:
                break;
            case 4:
                current_scene = 4;
                break;
            default:
                break;
            }
            break;
        case 2:
            break;
        case 3:
            current_scene = 1;
            break;
        default:
            break;
        }  
    }
    else if (!Keyboard::isKeyPressed(Keyboard::Enter)) {
        press_button_enter = true;
    }
    
}
