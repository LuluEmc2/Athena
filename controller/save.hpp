#ifndef _SAVE_
#define _SAVE_

#include <fstream>
#include <sstream>
#include <iomanip>
#include <controller.hpp>
#include <document.hpp>
#include <container.hpp>

#define DOCUMENTS_FLAG "__DOCUMENTS__"
#define CONTAINERS_FLAG "__CONTAINERS__"
#define LINKS_FLAG "__LINKS__"

namespace save
{
        //Returns 1 if it cannot open the file, 0 else
        int SaveData(std::string _filepath, controller::Controller* _controller);
        //Returns 1 if it cannot open the file, 0 else
        int LoadData(std::string _filepath, controller::Controller* _controller);
}

#endif