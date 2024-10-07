#ifndef _SAVE_VIEW_
#define _SAVE_VIEW_

#include <iostream>
#include <controller.hpp>
#include <save.hpp>
#include <utils_view.hpp>

#include <define_view_en.hpp>

namespace save_view
{
    void show_save(controller::Controller* _controller);
    void show_load(controller::Controller* _controller);
}

#endif