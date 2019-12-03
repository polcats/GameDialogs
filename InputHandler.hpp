#include <iostream>

class InputHandler
{
public:

	InputHandler()
	: err{false}
	, badInput{false}
	{
    }

    const size_t getInput(size_t const max)
    {
        size_t input = -1;
        badInput = true;

        while (badInput)
        {
            try {
                std::cout << "\n== Enter your choice: ";

                if((std::cin >> input))
                {
                    if (input >= max || input < 0)
                    {
                        err = true;
                    }

                    badInput = false;
                    err = false;
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

private:
    bool err;
    bool badInput;
};
