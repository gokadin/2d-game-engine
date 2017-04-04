#ifndef SFMLDEMO_SORTEDRENDERER_H
#define SFMLDEMO_SORTEDRENDERER_H

#include "SortedRenderGroup.h"

class SortedRenderer
{
public:
    ~SortedRenderer();

    void update();
    void draw(sf::RenderWindow *window);
    void addGroup(SortedRenderGroup *group);
    void addChar(SortedRenderGroup *group);

private:
    std::vector<SortedRenderGroup *> m_groups;
    SortedRenderGroup *m_charGroup;
    std::vector<SortedRenderGroup *> m_drawBefore;
    std::vector<SortedRenderGroup *> m_drawAfter;
};

#endif //SFMLDEMO_SORTEDRENDERER_H
