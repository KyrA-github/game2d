#include "loading_map.h"

loading_map::loading_map(Texture& image)
{
	sprite.setTexture(image);
}

void loading_map::read_file()
{
	try
	{
		nlohmann::json objJson;
		std::fstream fileInput;
		fileInput.open("data_game/map/map.json");
		fileInput >> objJson;
		fileInput.close();

		auto layers = objJson["layers"];
		for (int i = 0; i < matrix_h; i++)
		{
			auto groundData = layers[1]["data"];
			auto treeData = layers[0]["data"];

			for (int j = 0; j < matrix_w; j++)
			{
				groundLayer[i][j] = groundData[i * matrix_w + j];
				treeLayer[i][j] = treeData[i * matrix_w + j];
			}
		}
	}
	catch (const nlohmann::json::exception& e)
	{
		std::cout << "Error reading JSON: " << e.what() << std::endl;
	}
}

void loading_map::draw(RenderWindow& window)
{
	for (int i = 0; i < matrix_h; i++)
	{
		for (int j = 0; j < matrix_w; j++)
		{
			int groundTile = groundLayer[i][j];
			int treeTile = treeLayer[i][j];

			if (groundTile != 0)
			{
				tile_bool = true;
				tile_x = 16;
				tile_y = 16;
				tilenumder = groundLayer[i][j];
				tile_x = tilenumder * tile_x;
				while (tile_bool)
				{
					if (tile_x > 352)
					{
						tile_x = tile_x - 352;
						tile_y = tile_y + 16;
					}
					else
					{
						tile_bool = false;
					}
				}
				sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
				sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
				window.draw(sprite);

			}

			if (treeTile != 0)
			{
				tile_bool = true;
				tile_x = 16;
				tile_y = 16;
				tilenumder = treeLayer[i][j];
				tile_x = tilenumder * tile_x;
				while (tile_bool)
				{
					if (tile_x > 352)
					{
						tile_x = tile_x - 352;
						tile_y = tile_y + 16;
					}
					else
					{
						tile_bool = false;
					}
				}
				sprite.setTextureRect(IntRect(tile_x - 16, tile_y - 16, tile, tile));
				sprite.setPosition(j * tile - offsetX, i * tile - offsetY);
				window.draw(sprite);
			}
		}
	}
}