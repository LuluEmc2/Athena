#include <container.hpp>

namespace container 
{
    Container::Container(std::string _name, std::string _description)
    {
        m_name = _name;
        m_description = _description;
    }

    std::string Container::GetName() const
    {
        return m_name;
    }

    std::string Container::GetDescription() const
    {
        return m_description;
    }


    void Container::SetName(std::string _name)
    {
        m_name = _name;
    }

    void Container::SetDescription(std::string _description)
    {
        m_description = _description;
    }
}