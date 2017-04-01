#ifndef SFMLDEMO_ANIMATEDMAPOBJECT_H
#define SFMLDEMO_ANIMATEDMAPOBJECT_H

#include "MapObject.h"

class AnimatedMapObject : public MapObject
{
public:
    AnimatedMapObject(const std::string &name, MapState *mapState);

    virtual void update();
    virtual void draw(sf::RenderWindow *window);

protected:
    int m_counter;
    int m_stageFrames;
    int m_numStages;
    int m_currentStage;

    virtual void updateSprite();
    void loadMetadata(std::map<std::string, std::string> metadata);
};

#endif //SFMLDEMO_ANIMATEDMAPOBJECT_H
