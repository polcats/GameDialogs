#include "Conversation.hpp"

class Game
{
public:
    Game()
    : convo{}
    {
    }

    void start()
    {
        convo.showDialogs();
    }
private:
    Conversation convo;
};
