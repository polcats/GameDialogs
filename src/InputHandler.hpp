#include <iostream>

class InputHandler
{
public:

    InputHandler()
    {
    }

    const size_t getInput(size_t const max) const
    {
        bool goodInput = false;
        size_t input = -1;

        while (!goodInput)
        {
            try {
                std::cout << "\n== Enter your choice: ";

                if((std::cin >> input))
                {
                    if (input >= max || input < 0)
                    {
                        goodInput = false;
                    }
                    else
                    {
                        goodInput = true;
                    }
                }
                else
                {
                    goodInput = false;
                }

                std::cin.clear();
                std::cin.ignore(10000, '\n');

                if (!goodInput)
                {
                    throw -1;
                }
            }
            catch (...)
            {
                std::cout << "      > Invalid input!";
            }

        }
        return input;
    }
};
