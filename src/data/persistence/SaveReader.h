#ifndef SFMLDEMO_READSAVE_H
#define SFMLDEMO_READSAVE_H

#include <string>

const std::string SAVE_ROOT = "../src/storage/save/";
const std::string POSITION = SAVE_ROOT + "position";

class SaveReader
{
public:
    SaveReader();

    void read();

private:

};

#endif //SFMLDEMO_READSAVE_H
