#include <vector>
#include <memory>
#include <iostream>

struct Dialog;
typedef std::vector<std::pair<const Dialog*, std::string>> dialog_options_t;

struct Dialog
{
    Dialog(std::string text, dialog_options_t choices)
    : text{text}
    , choices{choices}
    {
    }

    std::string text;
    dialog_options_t choices;
};

struct Conversation
{
    std::vector<Dialog*> dialogs;

    Conversation()
    : dialogs{}
    {
        createDialogs();
    }

    const Dialog* findDialog(std::string text) const
    {
        for (auto& dialog : dialogs)
        {
            if (text == dialog->text)
            {
                return dialog;
            }
        }
        return new Dialog("", dialog_options_t{});
    }

    void createDialogs()
    {
        dialogs.push_back(new Dialog("Root!", dialog_options_t{}));
        dialogs.push_back(new Dialog("Trap!", dialog_options_t{{nullptr, "Your are trapped!"}}));
        dialogs.push_back(
            new Dialog(
                "Previous!",
                dialog_options_t (
                    {
                        {findDialog("Root!"), "Go to root."},
                        {findDialog("Trap!"), "Go to an adventure!"},
                        {nullptr, "Dont go to root."}
                    }
                )
                )
        );
    }

    void showDialogs() const
    {
        auto currentDialog = findDialog("Previous!");

        while (currentDialog)
        {
            std::cout << "\n\n" << currentDialog->text << "\n";

            if (currentDialog->choices.size())
            {
                for (auto i = 0u; i < currentDialog->choices.size(); ++i)
                {
                    std::cout << "\n" << (i+1) << ". " << currentDialog->choices.at(i).second;
                }

                auto choice = getInput();
                currentDialog = currentDialog->choices.at(choice).first;

                continue;
            }
            currentDialog = nullptr;
        }
    }

    const uint8_t getInput() const
    {
        uint8_t input = 0;

        std::cout << "\n== Enter your choice: ";
        // std::cin >> input;

        return input;
    }

};

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

int main()
{
    Game g{};
    g.start();


    return 0;
}