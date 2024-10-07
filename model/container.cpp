#include <container.hpp>

namespace container 
{
    Container::Container(std::string _name, std::string _description)
    {
        m_name = _name;
        m_description = _description;
    }

    std::string Container::get_name() const
    {
        return m_name;
    }

    std::string Container::get_description() const
    {
        return m_description;
    }


    void Container::set_name(std::string _name)
    {
        m_name = _name;
    }

    void Container::set_description(std::string _description)
    {
        m_description = _description;
    }
}