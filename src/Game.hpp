#include "Conversation.hpp"

class Game
{
public:
    Game()
    : convo{}
    {
    }

    void start() const
    {
        convo.showDialogs();
    }
private:
    const Conversation convo;
};
