#include "Dialog.hpp"

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
        dialogs.push_back(new Dialog("You are trapped!", dialog_options_t{}));
        dialogs.push_back(
            new Dialog(
                "Previous!",
                dialog_options_t (
                    {
                        {findDialog("Root!"), "Go to root."},
                        {findDialog("You are trapped!"), "Go to an adventure!"},
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

            if (currentDialog->choices.size() > 0)
            {
                for (auto i = 0u; i < currentDialog->choices.size(); ++i)
                {
                    std::cout << "\n" << (i) << ". " << currentDialog->choices.at(i).second;
                }

                size_t choice = getInput(currentDialog->choices.size());
                std::cout << "Your fucking choice is " <<  choice;
                currentDialog = currentDialog->choices.at(choice).first;

                continue;
            }
            currentDialog = nullptr;
        }
    }

    const size_t getInput(size_t max) const
    {
        size_t input = -1;
        bool badInput = true;

        while (badInput)
        {
            try {
                std::cout << "\n== Enter your choice: ";

                bool err = false;
                if((std::cin >> input))
                {
                    if (input >= max || input < 0)
                    {
                        err = true;
                    }

                    badInput = false;
                }
                else
                {
                    err = true;
                }

                std::cin.clear();
                std::cin.ignore(10000, '\n');

                if (err)
                {
                    throw -1;
                }
            }
            catch (...)
            {
                std::cout << "      > Invalid input!";
                badInput =  true;
            }

        }

        return input;
    }

};