#ifndef _DOCUMENT_VIEW_
#define _DOCUMENT_VIEW_

#include <iostream>
#include <tuple>

using namespace std;

//Only id, arguments : a tuple of id, name, description
void short_view(tuple<string, string, string> container);
//Id and title, arguments : a tuple of id, name, description
void medium_view(tuple<string, string, string> container);
//Everything, arguments : a tuple of id, name, description
void long_view(tuple<string, string, string> container);

#endif
