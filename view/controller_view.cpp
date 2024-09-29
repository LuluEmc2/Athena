#include <controller_view.hpp>

namespace controller_view
{
    void show_containers(controller::Controller* _controller, std::string _documentId)
    {
        std::unordered_set<std::string> containers = _controller->GetContainers(_documentId);

        for (const std::string container : containers)
        {
            std::cout << "\t-" << container << "\n";
        }
    }

    void show_document(controller::Controller* _controller, std::string _documentId, int _details)
    {
        std::tuple<std::string, std::string, std::string, double> document = _controller->GetDocument(_documentId);

        if(std::get<0>(document) == NO_FOUND_ERROR)
        {
            std::cout << DOCUMENT_NO_FOUND_ERROR_TEXT;

            return;
        }

        switch(_details)
        {
            case 0:
                document_view::short_view(document);
                break;
            case 1:
                document_view::medium_view(document);
                break;
            case 2:
                utils_view::line(10, "=");
                document_view::long_view(document);
                utils_view::line(10, "=");
                break;
            case 3:
                utils_view::line(10, "-");
                document_view::medium_view(document);
                show_containers(_controller, _documentId);
                utils_view::line(10, "-");
                break;
            case 4:
                utils_view::line(20, "<");
                document_view::long_view(document);
                show_containers(_controller, _documentId);
                utils_view::line(20, ">");
                break;
            default:
                document_view::short_view(document);
                break;
        }
    }

    void show_documents(controller::Controller* _controller, std::string _containerId)
    {
        std::unordered_set<std::string> documents = _controller->GetDocuments(_containerId);

        for (const std::string document : documents)
        {
            std::cout << "\t-" << document << "\n";
        }
    }

    void show_container(controller::Controller* _controller, std::string _containerId, int _details)
    {
        std::tuple<std::string, std::string, std::string> container = _controller->GetContainer(_containerId);

        if(std::get<0>(container) == NO_FOUND_ERROR)
        {
            std::cout << CONTAINER_NO_FOUND_ERROR_TEXT;

            return;
        }

        switch(_details)
        {
            case 0:
                container_view::short_view(container);
                break;
            case 1:
                container_view::medium_view(container);
                break;
            case 2:
                utils_view::line(10, "=");
                container_view::long_view(container);
                utils_view::line(10, "=");
                break;
            case 3:
                utils_view::line(5, "-");
                container_view::medium_view(container);
                show_documents(_controller, _containerId);
                utils_view::line(5, "-");
                break;
            case 4:
                utils_view::line(20, "<");
                container_view::long_view(container);
                show_documents(_controller, _containerId);
                utils_view::line(20, ">");
                break;
            default:
                container_view::short_view(container);
                break;
        }
    }


    void show_search(controller::Controller* _controller)
    {
        std::string name = "";

        name = utils_view::read_input<std::string>(ASK_FOR_NAME_TEXT);

        for (const std::string id : _controller->GetIds(name))
        {
            std::cout << "\t-" << id << "\n";
        }
    }


    void show_add_document(controller::Controller* _controller)
    {
        std::string id = "";
        std::string title = "";
        std::string description = "";
        double length = 0.0;

        char use_isbn = 'n';

    ask_isbn:

        use_isbn = utils_view::read_input<char>(ASK_FOR_USE_ISBN_TEXT);

        if(use_isbn == USE_ISBN_YES_CHAR)
        {
            long int isbn = 0;

            isbn = utils_view::read_input<long int>(ASK_FOR_ISBN_TEXT);

            std::tuple<std::string, std::string, int> document = isbn::GetDocISBN(isbn);

            if(std::get<0>(document) == HTML_ERROR)
            {
                std::cout << HTML_ERROR_TEXT;
                goto ask_isbn;
            }
            else
            {
                title = std::get<0>(document);
                description = std::get<1>(document);
                length = std::get<2>(document);

                std::cout << ISBN_INFO_FOUND_SUCCESS_TEXT;
                std::cout << TITLE_TEXT << title << "\n";
                std::cout << DESCRIPTION_TEXT << description << "\n";
                std::cout << LENGTH_TEXT << length << "\n";

                use_isbn = 'n';

                use_isbn = utils_view::read_input<char>(ASK_FOR_USE_ISBN_INFOS_TEXT);

                if(use_isbn == USE_ISBN_YES_CHAR)
                {
                    id = utils_view::read_input<std::string>(ASK_FOR_DOCUMENT_ID_TEXT);

                    goto add_document;
                }
            }
        }

        id = "";
        title = "";
        description = "";

        id = utils_view::read_input<std::string>(ASK_FOR_DOCUMENT_ID_TEXT);

        title = utils_view::read_input<std::string>(ASK_FOR_TITLE_TEXT);

        description = utils_view::read_input<std::string>(ASK_FOR_DESCRIPTION_TEXT);

        length = utils_view::read_input<double>(ASK_FOR_LENGTH_TEXT);

    add_document:
        switch(_controller->AddDocument(id, title, description, length))
        {
            case 1:
                std::cout << ID_ALREADY_USED_ERROR_TEXT;
                break;
            case -1:
                std::cout << ID_IS_A_KEYWORD_ERROR_TEXT;
                break;
            case 2:
                std::cout << CONTAINS_QUOTES_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << DOCUMENT_CREATED_SUCCESS_TEXT;
                show_document(_controller, id, 1);
                break;
        }
    }

    void show_remove_document(controller::Controller* _controller)
    {
        std::string id = "";

        id = utils_view::read_input<std::string>(ASK_FOR_DOCUMENT_ID_TEXT);

        switch(_controller->RemoveDocument(id))
        {
            case 1:
                std::cout << DOCUMENT_NO_FOUND_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << DOCUMENT_REMOVED_SUCCESS_TEXT << id << "\n";
                break;
        }
    }

    void show_add_container(controller::Controller* _controller)
    {
        std::string id = "";
        std::string name = "";
        std::string description = "";

        id = utils_view::read_input<std::string>(ASK_FOR_CONTAINER_ID_TEXT);
        name = utils_view::read_input<std::string>(ASK_FOR_NAME_TEXT);
        description = utils_view::read_input<std::string>(ASK_FOR_DESCRIPTION_TEXT);


        switch(_controller->AddContainer(id, name, description))
        {
            case 1:
                std::cout << ID_ALREADY_USED_ERROR_TEXT;
                break;
            case -1:
                std::cout << ID_IS_A_KEYWORD_ERROR_TEXT;
                break;
            case 2:
                std::cout << CONTAINS_QUOTES_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << CONTAINER_CREATED_SUCCESS_TEXT;
                show_container(_controller, id, 1);
                break;
        }
    }

    void show_remove_container(controller::Controller* _controller)
    {
        std::string id = "";

        id = utils_view::read_input<std::string>(ASK_FOR_CONTAINER_ID_TEXT);

        switch(_controller->RemoveContainer(id))
        {
            case 1:
                std::cout << CONTAINER_NO_FOUND_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << CONTAINER_REMOVED_SUCCESS_TEXT << id << "\n";
                break;
        }
    }

    void show_store_document(controller::Controller* _controller)
    {
        std::string document_id = "";

        document_id = utils_view::read_input<std::string>(ASK_FOR_DOCUMENT_ID_TEXT);

        std::string container_id = "";

        container_id = utils_view::read_input<std::string>(ASK_FOR_CONTAINER_ID_TEXT);

        switch(_controller->StoreDocument(document_id, container_id))
        {
            case 1:
                std::cout << CONTAINER_OR_DOCUMENT_NO_FOUND_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << STORE_SUCCESS_TEXT;
                break;
        }
    }

    void show_unstore_document(controller::Controller* _controller)
    {
        std::string document_id = "";

        document_id = utils_view::read_input<std::string>(ASK_FOR_DOCUMENT_ID_TEXT);

        std::string container_id = "";

        container_id = utils_view::read_input<std::string>(ASK_FOR_CONTAINER_ID_TEXT);

        switch(_controller->UnstoreDocument(document_id, container_id))
        {
            case 1:
                std::cout << CONTAINER_OR_DOCUMENT_NO_FOUND_ERROR_TEXT;
                break;
            case -1:
                std::cout << CONTAINER_AND_DOCUMENT_NO_LINKED_ERROR_TEXT;
                break;
            case 0:
            default:
                std::cout << UNSTORE_SUCCESS_TEXT;
                break;
        }
    }
}
