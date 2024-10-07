#include <save_view.hpp>

namespace save_view
{
    void show_save(controller::Controller* _controller)
    {
        std::string file_path = utils_view::read_input<std::string>(ASK_FOR_PATH_TEXT);

        switch(save::SaveData(file_path, _controller))
        {
            case 1:
                std::cout << CANNOT_OPEN_FILE_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << FILE_SAVE_SUCCESS_TEXT << "\n";
                break;
        }
    }

    void show_load(controller::Controller* _controller)
    {
        std::string file_path = utils_view::read_input<std::string>(ASK_FOR_PATH_TEXT);

        switch(save::LoadData(file_path, _controller))
        {
            case 1:
                std::cout << CANNOT_OPEN_FILE_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << FILE_SAVE_SUCCESS_TEXT << "\n";
                break;
        }
    }
}