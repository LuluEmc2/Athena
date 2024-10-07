#ifndef _CONTROLLER_VIEW_
#define _CONTROLLER_VIEW_

#include <unordered_set>
#include <tuple>
#include <iostream>
#include <controller.hpp>
#include <isbn.hpp>
#include <container_view.hpp>
#include <document_view.hpp>
#include <utils_view.hpp>

#include <define_global.hpp>
#include <define_view_en.hpp>

namespace controller_view
{
    //_details :
    void show_document(controller::Controller* _controller, std::string _documentId, int _details);
    //_details :
    void show_container(controller::Controller* _controller, std::string _containerId, int _details);

    void show_search(controller::Controller* _controller);

    void show_add_document(controller::Controller* _controller);
    void show_remove_document(controller::Controller* _controller);
    void show_add_container(controller::Controller* _controller);
    void show_remove_container(controller::Controller* _controller);

    void show_store_document(controller::Controller* _controller);
    void show_unstore_document(controller::Controller* _controller);
}

#endif
