#ifndef SFMLDEMO_SORTEDRENDERGROUP_H
#define SFMLDEMO_SORTEDRENDERGROUP_H

class SortedRenderGroup
{
public:
    void draw(sf::RenderWindow *window)
    {
        for (auto *drawable : m_drawables)
        {
            window->draw(*drawable);
        }
    }

    void addDrawable(sf::Drawable *drawable)
    {
        m_drawables.push_back(drawable);
    }

    void setCorner(int x, int y)
    {
        m_cornerX = x;
        m_cornerY = y;
    }

    inline int cornerX() { return m_cornerX; }
    inline int cornerY() { return m_cornerY; }

private:
    std::vector<sf::Drawable *> m_drawables;
    int m_cornerX;
    int m_cornerY;
};

#endif //SFMLDEMO_SORTEDRENDERGROUP_H
