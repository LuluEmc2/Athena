#ifndef _GET_ISBN_
#define _GET_ISBN_

#include <string>
#include <tuple>

#include <define_global.hpp>

namespace isbn
{
    // Returns {HTML_ERROR_TEXT, "", error_code} wher a html error occurs
    std::tuple<std::string, std::string, int> get_document_isbn(long int _ISBN);
}

#endif
