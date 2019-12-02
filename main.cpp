#include <vector>
#include <memory>
#include <iostream>

struct Dialog;
typedef std::vector<std::pair<Dialog*, std::string>> choices_t;

struct Dialog
{
	Dialog(std::string text, choices_t choices)
	: text{text}
	, choices{choices}
	{
	}

	std::string text;
	choices_t choices;
};

struct Conversation
{
	std::vector<Dialog*> dialogs;

	Conversation()
	: dialogs{}
	{
		createDialogs();
	}

	void createDialogs()
	{
		dialogs.push_back(new Dialog("Root!", choices_t{{nullptr, ""}}));
		dialogs.push_back(
			new Dialog(
				"Previous!",
					choices_t (
						{
							{dialogs.at(0), "Go to root."},
							{dialogs.at(0), "Dont go to root."}
						}
					)
				)
		);
	}

	void showDialogs()
	{
		auto currentDialog = dialogs.at(1);

		while (currentDialog)
		{
			std::cout << "\n\n" << currentDialog->text;

			for (auto i = 0u; i < currentDialog->choices.size(); ++i)
			{
				std::cout << "\n" << (i+1) << ". " << currentDialog->choices.at(i).second;
			}

			currentDialog = currentDialog->choices.at(0).first;
		}
	}

};

int main()
{
	Conversation c;
	c.showDialogs();


	return 0;
}