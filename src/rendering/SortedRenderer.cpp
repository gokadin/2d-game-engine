#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "SortedRenderer.h"
#include "../core/Engine.h"

SortedRenderer::~SortedRenderer()
{
    m_drawBefore.clear();
    m_drawAfter.clear();

    for (auto *group : m_groups)
    {
        delete group;
    }
    m_groups.clear();

    delete m_charGroup;
}

void SortedRenderer::update()
{

}

void SortedRenderer::draw(sf::RenderWindow *window)
{
    //std::cout << Engine::CY - m_groups[0]->cornerY() << std::endl;
    std::cout << Engine::CX - m_groups[0]->cornerX() << std::endl;

    if (Engine::CY - m_groups[0]->cornerY() < 0 && Engine::CX - m_groups[0]->cornerX() < 0)
    {
        m_charGroup->draw(window);
        m_groups[0]->draw(window);
    }
    else
    {
        m_groups[0]->draw(window);
        m_charGroup->draw(window);
    }

    for (auto *group : m_drawBefore)
    {
        group->draw(window);
    }

    for (auto *group : m_drawAfter)
    {
        group->draw(window);
    }
}

void SortedRenderer::addGroup(SortedRenderGroup *group)
{
    m_groups.push_back(group);
}

void SortedRenderer::addChar(SortedRenderGroup *group)
{
    m_charGroup = group;
}

