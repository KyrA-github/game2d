#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <fstream>
#include "json/include/nlohmann/json.hpp"

int map_read() {
    nlohmann::json objJson;
    std::fstream fileInput;
    fileInput.open("data_game/map/map.json");

    fileInput >> objJson;



    fileInput.close();


    return 0;
}