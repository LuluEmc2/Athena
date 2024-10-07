#ifndef _DOCUMENT_VIEW_
#define _DOCUMENT_VIEW_

#include <iostream>
#include <tuple>

#include <define_global.hpp>
#include <define_view_en.hpp>

namespace document_view
{
    //Only id, arguments : a tuple of id, title, description, length
    void short_view(std::tuple<std::string, std::string, std::string, double> _document);
    //Id and title, arguments : a tuple of id, title, description, length
    void medium_view(std::tuple<std::string, std::string, std::string, double> _document);
    //Everything, arguments : a tuple of id, title, description, length
    void long_view(std::tuple<std::string, std::string, std::string, double> _document);
}

#endif
