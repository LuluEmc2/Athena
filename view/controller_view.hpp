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

#define HTML_ERROR "__HE__"
#define NO_FOUND_ERROR "__NF__"

#define USE_ISBN_YES_CHAR 'y'

#define HTML_ERROR_TEXT "The document isn't available in openlibrairy database, you can add it here : https://openlibrary.org/books/add\n"
#define CONTAINER_NO_FOUND_ERROR_TEXT "Container not found in database.\n"
#define DOCUMENT_NO_FOUND_ERROR_TEXT "Document not found in database.\n"
#define CONTAINER_OR_DOCUMENT_NO_FOUND_ERROR_TEXT "Container or document not found in database.\n"
#define ID_ALREADY_USED_ERROR_TEXT "The id is already used.\n"
#define ID_IS_A_KEYWORD_ERROR_TEXT "The id is a keyword.\n"
#define CONTAINER_AND_DOCUMENT_NO_LINKED_ERROR_TEXT "Container and document are not linked together.\n"

#define ISBN_INFO_FOUND_SUCCESS_TEXT "Document successfully found in openlibrairy database :\n"
#define DOCUMENT_CREATED_SUCCESS_TEXT "Document successfully created : "
#define DOCUMENT_REMOVED_SUCCESS_TEXT "Document successfully removed : "
#define CONTAINER_CREATED_SUCCESS_TEXT "Container successfully created : "
#define CONTAINER_REMOVED_SUCCESS_TEXT "Container successfully removed : "
#define STORE_SUCCESS_TEXT "Document successfully stored in container.\n"
#define UNSTORE_SUCCESS_TEXT "Document successfully unstored of container.\n"

#define ASK_FOR_USE_ISBN_TEXT "Do you want to use ISBN database ([y]es/[n]o) ? "
#define ASK_FOR_ISBN_TEXT "ISBN : "
#define ASK_FOR_USE_ISBN_INFOS_TEXT "Do you want to use ISBN obtained infos ([y]es/[n]o) ? "
#define ASK_FOR_CONTAINER_ID_TEXT "Container ID : "
#define ASK_FOR_DOCUMENT_ID_TEXT "Document ID : "
#define ASK_FOR_NAME_TEXT "Name : "
#define ASK_FOR_TITLE_TEXT "Title : "
#define ASK_FOR_DESCRIPTION_TEXT "Description : "
#define ASK_FOR_LENGTH_TEXT "Length : "

#define TITLE_TEXT "Title : "
#define DESCRIPTION_TEXT "Description : "
#define LENGTH_TEXT "Length : "

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
