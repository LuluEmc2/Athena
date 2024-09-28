#ifndef _CONTAINER_VIEW_
#define _CONTAINER_VIEW_

#include <iostream>
#include <tuple>

#define NO_FOUND_ERROR "__NF__"

#define CONTAINER_NO_FOUND_ERROR_TEXT "Container not found in database.\n"

namespace container_view
{
    //Only id, arguments : a tuple of id, name, description
    void short_view(std::tuple<std::string, std::string, std::string> _container);
    //Id and title, arguments : a tuple of id, name, description
    void medium_view(std::tuple<std::string, std::string, std::string> _container);
    //Everything, arguments : a tuple of id, name, description
    void long_view(std::tuple<std::string, std::string, std::string> _container);
}

#endif
