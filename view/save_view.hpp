#ifndef _SAVE_VIEW_
#define _SAVE_VIEW_

#include <iostream>
#include <controller.hpp>
#include <save.hpp>
#include <utils_view.hpp>

#define CANNOT_OPEN_FILE_ERROR_TEXT "The file could not be opened."

#define FILE_SAVE_SUCCESS_TEXT "The file has been successfully saved."

#define ASK_FOR_PATH_TEXT "File Path : "

namespace save_view
{
    void show_save(controller::Controller* _controller);
    void show_load(controller::Controller* _controller);
}

#endif