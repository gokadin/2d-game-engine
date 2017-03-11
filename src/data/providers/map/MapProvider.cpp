#include <map>
#include "MapProvider.h"
#include "../../IO/KeyValueReader.h"
#include "../../IO/ArrayReader.h"

MapProvider::MapProvider(GameState& state, SaveReader& saveReader):
        Provider(state, saveReader)
{}

void MapProvider::load()
{
    std::string mapFolder = GAME_STORAGE_ROOT + "maps/act" + std::to_string(state.save.act) + "/" + state.save.map + "/";

    std::map<std::string, std::string> metadata = KeyValueReader::read(mapFolder + "metadata");

    state.map.width = std::stoi(metadata["WIDTH"]);
    state.map.height = std::stoi(metadata["HEIGHT"]);
    state.map.x = std::stoi(metadata["INITIAL_X"]);
    state.map.y = std::stoi(metadata["INITIAL_Y"]);
    state.map.texture = mapFolder + "texture.jpg";
    state.map.bounds = ArrayReader::read2D(mapFolder + "bounds");
}
