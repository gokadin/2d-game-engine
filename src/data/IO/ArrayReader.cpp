#include "ArrayReader.h"

std::vector<std::vector<int>> ArrayReader::read2D(std::string filename)
{
    std::vector<std::vector<int>> array;

    std::ifstream infile(filename);
    if (!infile.is_open())
    {
        std::cout << "Could not open file " << filename << std::endl;
        return array;
    }

    std::string line;
    while (getline(infile, line))
    {
        std::vector<int> row;
        std::string value;
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ',' || line[i] == '\n')
            {
                row.push_back(std::stoi(value));
                value = "";

                continue;
            }

            value += line[i];
        }

        array.push_back(row);
    }

    return array;
}
