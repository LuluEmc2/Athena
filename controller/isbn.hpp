#ifndef _GET_ISBN_
#define _GET_ISBN_

#include <string>
#include <tuple>

#define HTML_ERROR_TEXT "__HE__"
#define DESCRIPTION_PROPERTY "description"
#define TITLE_PROPERTY "title"
#define PAGES_PROPERTY "number_of_pages"

namespace isbn
{
    // Returns {HTML_ERROR_TEXT, "", error_code} wher a html error occurs
    std::tuple<std::string, std::string, int> GetDocISBN(long int ISBN);
}

#endif
