#include <document_view.hpp>

namespace document_view
{
    void short_view(std::tuple<std::string, std::string, std::string, double> document)
    {
        std::cout << std::get<0>(document) << "\n";
    }

    void medium_view(std::tuple<std::string, std::string, std::string, double> document)
    {
        std::cout << std::get<0>(document) << " : " << std::get<1>(document) << "\n";
    }

    void long_view(std::tuple<std::string, std::string, std::string, double> document)
    {
        std::cout << std::get<0>(document) << " : " << std::get<1>(document) << " : \n\n\t" 
        << std::get<2>(document) << "\n\nLength : " << std::get<3>(document) << ".\n";
    }
}