#include "Quests.h"
#include "../../events/quests/QuestAcceptedEvent.h"
#include "act1/Intro.h"

Quests::Quests()
{
    m_tracker = new QuestTracker();
}

Quests::~Quests()
{
    delete m_tracker;
}

void Quests::update()
{
    m_tracker->update();
}

void Quests::draw(sf::RenderWindow *window)
{

}

void Quests::notify(std::shared_ptr<Event> event)
{
    switch (event->type())
    {
        case event_type::QUEST_ACCEPTED:
            m_tracker->acceptQuest(createQuest((std::static_pointer_cast<QuestAcceptedEvent>(event))->questName()));
            break;
        default:
            m_tracker->notify(event);
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
