#include <document_view.hpp>

namespace document_view
{
    void short_view(std::tuple<std::string, std::string, std::string, double> _document)
    {
        if(std::get<0>(_document) == NO_FOUND_ERROR)
        {
            std::cout << DOCUMENT_NO_FOUND_ERROR_TEXT;

            return;
        }

        std::cout << std::get<0>(_document) << "\n";
    }

    void medium_view(std::tuple<std::string, std::string, std::string, double> _document)
    {
        if(std::get<0>(_document) == NO_FOUND_ERROR)
        {
            std::cout << DOCUMENT_NO_FOUND_ERROR_TEXT;

            return;
        }

        std::cout << std::get<0>(_document) << " : " << std::get<1>(_document) << "\n";
    }

    void long_view(std::tuple<std::string, std::string, std::string, double> _document)
    {
        if(std::get<0>(_document) == NO_FOUND_ERROR)
        {
            std::cout << DOCUMENT_NO_FOUND_ERROR_TEXT;

            return;
        }

        std::cout << std::get<0>(_document) << " : " << std::get<1>(_document) << " : \n\n\t" 
        << std::get<2>(_document) << "\n\nLength : " << std::get<3>(_document) << ".\n";
    }
}