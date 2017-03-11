#ifndef SFMLDEMO_ARRAYREADER_H
#define SFMLDEMO_ARRAYREADER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class ArrayReader
{
public:
    static std::vector<std::vector<int>> read2D(std::string filename);
};

#endif //SFMLDEMO_ARRAYREADER_H
