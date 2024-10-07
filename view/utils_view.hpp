#ifndef _UTILS_VIEW_
#define _UTILS_VIEW_

#include <iostream>
#include <sstream>
#include <limits>

#include <define_view_en.hpp>

namespace utils_view
{
    //Draws a line of the length and char given in params
    void line(int _length, std::string _patern);
    template <typename T>
    T read_input(std::string _message);
}

#endif
