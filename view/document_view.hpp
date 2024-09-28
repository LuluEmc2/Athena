#ifndef _DOCUMENT_VIEW_
#define _DOCUMENT_VIEW_

#include <iostream>
#include <tuple>

#define NO_FOUND_ERROR "__NF__"

#define DOCUMENT_NO_FOUND_ERROR_TEXT "Document not found in database.\n"

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
