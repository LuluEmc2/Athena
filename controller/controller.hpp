#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <document.hpp>
#include <container.hpp>

#define NO_FOUND_ERROR "__NF__"

namespace controller
{
    class Controller
    {
        public:
            Controller();

            //Returns a tuple of id, title, description, length, returns {UNFOUND_ERROR, "", "", 0.0f} if Id is invalid
            std::tuple<std::string, std::string, std::string, double> GetDocument(std::string _documentId);
            //Returns a tuple of id, name, description, returns {UNFOUND_ERROR, "", ""} if Id is invalid
            std::tuple<std::string, std::string, std::string> GetContainer(std::string _containerId);
            //Returns a set of the documents in container Ids
            std::unordered_set<std::string> GetDocuments(std::string _containerId);
            //Returns a set of the containers of document Ids
            std::unordered_set<std::string> GetContainers(std::string _documentId);

            //Returns 1 if there's already a doc or a container with the same Id, -1 if it uses a keyword, 0 else
            int AddDocument(std::string _id, std::string _title, std::string _description, double _length);
            //Returns 1 if there isn't a doc with this Id, 0 else
            int RemoveDocument(std::string _id);
            //Returns 1 if there's already a container or a doc with the same Id, -1 if it uses a keyword, 0 else
            int AddContainer(std::string _id, std::string _title, std::string _description);
            //Returns 1 if there isn't a container with this Id, 0 else
            int RemoveContainer(std::string _id);

            //Returns 1 if the container or the document doesn't exists, 0 else
            int StoreDocument(std::string _documentId, std::string _containerId);
            //Returns 1 if the container or the document doesn't exists, -1 if the links between them doesn't exists, 0 else
            int UnstoreDocument(std::string _documentId, std::string _containerId);

        private:
            //Links the Id with the objects
            std::unordered_map<std::string, document::Document*> m_documents;
            std::unordered_map<std::string, container::Container*> m_containers;

            //Parents documents and containers using ids.
            std::unordered_map<std::string, std::unordered_set<std::string>> m_documentsToContainers;
            std::unordered_map<std::string, std::unordered_set<std::string>> m_containersToDocuments;
    };
}

#endif
