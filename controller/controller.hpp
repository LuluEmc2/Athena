#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <document.hpp>
#include <container.hpp>

#include <define_global.hpp>

namespace controller
{
    class Controller
    {
        public:
            Controller();

            std::unordered_map<std::string, document::Document*> get_all_documents();
            std::unordered_map<std::string, container::Container*> get_all_containers();
            //Returns m_documentsToContainers
            std::unordered_map<std::string, std::unordered_set<std::string>> get_all_connexions();

            //Returns a tuple of id, title, description, length, returns {UNFOUND_ERROR, "", "", 0.0f} if Id is invalid
            std::tuple<std::string, std::string, std::string, double> get_document(std::string _documentId);
            //Returns a tuple of id, name, description, returns {UNFOUND_ERROR, "", ""} if Id is invalid
            std::tuple<std::string, std::string, std::string> get_container(std::string _containerId);
            //Returns a set of the documents in container Ids
            std::unordered_set<std::string> get_documents(std::string _containerId);
            //Returns a set of the containers of document Ids
            std::unordered_set<std::string> get_containers(std::string _documentId);

            //Returns a set of the containers of document Ids
            std::unordered_set<std::string> get_ids(std::string _name);

            //Returns 1 if there's already a doc or a container with the same Id, 2 if it uses a ", -1 if it uses a keyword, 0 else
            int add_document(std::string _id, std::string _title, std::string _description, double _length);
            //Returns 1 if there isn't a doc with this Id, 0 else
            int remove_document(std::string _id);
            //Returns 1 if there's already a container or a doc with the same Id, 2 if it uses a ", -1 if it uses a keyword, 0 else
            int add_container(std::string _id, std::string _name, std::string _description);
            //Returns 1 if there isn't a container with this Id, 0 else
            int remove_container(std::string _id);

            //Returns 1 if the container or the document doesn't exists, 0 else
            int store_document(std::string _documentId, std::string _containerId);
            //Returns 1 if the container or the document doesn't exists, -1 if the links between them doesn't exists, 0 else
            int unstore_document(std::string _documentId, std::string _containerId);

        private:
            //Links the Id with the objects
            std::unordered_map<std::string, document::Document*> m_documents;
            std::unordered_map<std::string, container::Container*> m_containers;

            //Parents documents and containers using ids.
            std::unordered_map<std::string, std::unordered_set<std::string>> m_documentsToContainers;
            std::unordered_map<std::string, std::unordered_set<std::string>> m_containersToDocuments;
    
            //Links the title with the ids for rapid search
            std::unordered_map<std::string, std::unordered_set<std::string>> m_namesToIds;
    };
}

#endif
