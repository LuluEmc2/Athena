#include <container_view.hpp>

void short_view(tuple<string, string, string> container)
{
    cout << get<0>(container) << "\n";
}

void medium_view(tuple<string, string, string> container)
{
    cout << get<0>(container) << " : " << get<1>(container) << "\n";
}

void long_view(tuple<string, string, string> container)
{
    cout << get<0>(container) << " : " << get<1>(container) << " : \n\n\t"
    << get<2>(container) << "\n";
}