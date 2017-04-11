#include "Quests.h"
#include "../../events/quests/QuestAcceptedEvent.h"
#include "act1/Intro.h"

Quests::Quests()
{}

Quests::~Quests()
{

}

void Quests::update()
{
    m_tracker.update();
}

void Quests::draw(sf::RenderWindow *window)
{

}

void Quests::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::QUEST_ACCEPTED:
            m_tracker.acceptQuest(createQuest((std::static_pointer_cast<QuestAcceptedEvent>(event))->questName()));
            break;
    }
}

Quest *Quests::createQuest(quest_name name)
{
    switch (name)
    {
        case quest_name::INTRO_QUEST:
            return new Intro();
        default:
            return nullptr;
    }
}
