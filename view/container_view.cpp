#include <container_view.hpp>

namespace container_view
{
    void short_view(std::tuple<std::string, std::string, std::string> _container)
    {
        std::cout << std::get<0>(_container) << "\n";
    }
    
    void medium_view(std::tuple<std::string, std::string, std::string> _container)
    {
        std::cout << std::get<0>(_container) << " : " << std::get<1>(_container) << "\n";
    }
    
    void long_view(std::tuple<std::string, std::string, std::string> _container)
    {
        std::cout << std::get<0>(_container) << " : " << std::get<1>(_container) << " : \n\n\t"
        << std::get<2>(_container) << "\n";
    }
}