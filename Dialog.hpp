#include <vector>

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
