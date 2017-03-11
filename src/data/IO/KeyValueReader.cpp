#include "KeyValueReader.h"

std::map<std::string, std::string> KeyValueReader::read(std::string filename)
{
    std::map<std::string, std::string> map;

    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cout << "Could not open file " << filename << std::endl;
        return map;
    }

    std::string line;
    while (getline(infile, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '=')
            {
                map[line.substr(0, i)] = line.substr(i + 1);
                break;
            }
        }
    }

    return map;
}
