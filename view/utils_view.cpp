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
}