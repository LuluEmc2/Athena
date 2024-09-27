#include <document_view.hpp>

void short_view(tuple<string, string, string, double> document)
{
    cout << get<0>(document) << "\n";
}

void medium_view(tuple<string, string, string, double> document)
{
    cout << get<0>(document) << " : " << get<1>(document) << "\n";
}

void long_view(tuple<string, string, string, double> document)
{
    cout << get<0>(document) << " : " << get<1>(document) << " : \n\n\t"
    << get<2>(document) << "\n\nPages : " << get<3>(document) << ".\n";
}