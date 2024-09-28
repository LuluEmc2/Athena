#include <utils_view.hpp>

namespace utils_view
{
    void line(int _length, char _char)
    {
        for(int i; i < _length; i++)
        {
            std::cout << _char;
        }

        std::cout << "\n";
    }
}