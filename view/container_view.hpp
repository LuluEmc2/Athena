#ifndef _CONTAINER_VIEW_
#define _CONTAINER_VIEW_

#include <iostream>
#include <tuple>

namespace container_view
{
    //Only id, arguments : a tuple of id, name, description
    void short_view(std::tuple<std::string, std::string, std::string> container);
    //Id and title, arguments : a tuple of id, name, description
    void medium_view(std::tuple<std::string, std::string, std::string> container);
    //Everything, arguments : a tuple of id, name, description
    void long_view(std::tuple<std::string, std::string, std::string> container);
}

#endif
