#include <container_view.hpp>

namespace container_view
{
    void short_view(std::tuple<std::string, std::string, std::string> container)
    {
        std::cout << std::get<0>(container) << "\n";
    }
    
    void medium_view(std::tuple<std::string, std::string, std::string> container)
    {
        std::cout << std::get<0>(container) << " : " << std::get<1>(container) << "\n";
    }
    
    void long_view(std::tuple<std::string, std::string, std::string> container)
    {
        std::cout << std::get<0>(container) << " : " << std::get<1>(container) << " : \n\n\t"
        << std::get<2>(container) << "\n";
    }
}