#ifndef SFMLDEMO_MAPDATA_H
#define SFMLDEMO_MAPDATA_H

#include <vector>
#include "../Data.h"

class MapData : public Data
{
public:
    inline std::vector<std::vector<int>>& bounds() { return m_bounds; }

    inline void setBounds(std::vector<std::vector<int>> bounds) { m_bounds = bounds; }

private:
    std::vector<std::vector<int>> m_bounds;
};

#endif //SFMLDEMO_MAPDATA_H
