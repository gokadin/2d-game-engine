#include "SaveReader.h"
#include "../IO/KeyValueReader.h"

SaveReader::SaveReader(GameState &state):
        state(state)
{}

void SaveReader::read()
{
    std::map<std::string, std::string> position = KeyValueReader::read(POSITION);

    state.save.act = std::stoi(position["ACT"]);
    state.save.map = position["MAP"];
}
