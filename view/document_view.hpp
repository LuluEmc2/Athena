#ifndef _DOCUMENT_VIEW_
#define _DOCUMENT_VIEW_

#include <iostream>
#include <tuple>

using namespace std;

//Only id, arguments : a tuple of id, title, description, length
void short_view(tuple<string, string, string, double> document);
//Id and title, arguments : a tuple of id, title, description, length
void medium_view(tuple<string, string, string, double> document);
//Everything, arguments : a tuple of id, title, description, length
void long_view(tuple<string, string, string, double> document);

#endif
