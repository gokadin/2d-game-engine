#ifndef SFMLDEMO_KEYVALUEREADER_H
#define SFMLDEMO_KEYVALUEREADER_H

#include <map>
#include <fstream>
#include <iostream>

class KeyValueReader
{
public:
    static std::map<std::string, std::string> read(std::string filename);
};

#endif //SFMLDEMO_KEYVALUEREADER_H
