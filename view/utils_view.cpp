#include <utils_view.hpp>

namespace utils_view
{
    void line(int _length, std::string _patern)
    {
        for(int i = 0; i < _length; i++)
        {
            std::cout << _patern;
        }

        std::cout << "\n";
    }

    void clear_input()
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    template <typename T> T read_input(std::string _message)
    {
    read_input:
        std::cout << _message;

        T value;
        std::string input;

        std::getline(std::cin, input);

        std::stringstream ss(input);
        ss >> value;
        
        if (ss.fail() || !ss.eof()) 
        {
            std::cout << INVALID_ENTRY_ERROR;
            clear_input();
            goto read_input;
        }
        

        return value;
    }

    template <> char read_input(std::string _message)
    {
    read_input:
        std::cout << _message;

        char value;
        std::string input;

        std::getline(std::cin, input);

        if (input.empty() || input.length() != 1) {
            std::cout << INVALID_ENTRY_ERROR;
            clear_input();
            goto read_input;
        }

        value = input[0];

        return value;
    }

    template <> std::string read_input(std::string _message)
    {
    read_input:
        std::cout << _message;

        std::string value;
        std::string input;

        std::getline(std::cin, input);
        
        if (input.empty())
        {
            std::cout << INVALID_ENTRY_ERROR;
            clear_input();
            goto read_input;
        }
        
        value = input;

        return value;
    }

    template int read_input<int>(std::string _message);
    template double read_input<double>(std::string _message);
    template long read_input<long>(std::string _message);
}