#include "Container.hpp"

using namespace std;

Container::Container(string _name, string _description)
{
    m_name = _name;
    m_description = _description;
}


string Container::GetName() const
{
    return m_name;
}

string Container::GetDescription() const
{
    return m_description;
}


void Container::SetName(string _name)
{
    m_name = _name;
}

void Container::SetDescription(string _description)
{
    m_description = _description;
}
