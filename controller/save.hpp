#ifndef _SAVE_
#define _SAVE_

#include <fstream>
#include <sstream>
#include <iomanip>
#include <controller.hpp>
#include <document.hpp>
#include <container.hpp>

#include <define_global.hpp>

namespace save
{
        //Returns 1 if it cannot open the file, 0 else
        int SaveData(std::string _filepath, controller::Controller* _controller);
        //Returns 1 if it cannot open the file, 0 else
        int LoadData(std::string _filepath, controller::Controller* _controller);
}

#endif