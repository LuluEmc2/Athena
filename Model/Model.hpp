#ifndef _MODEL_
#define _MODEL_

#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include "Document.hpp"
#include "Container.hpp"

using namespace std;

class Model
{
    public:
        Model();

        //Returns a tuple of title, description, length, returns {"", "", 0.0f} if Id is invalid
        tuple<string, string, float> GetDocument(string _documentId);
        //Returns a tuple of name, description, returns {"", ""} if Id is invalid
        tuple<string, string> GetContainer(string _containerId);
        //Returns a set of the documents in container Ids
        unordered_set<string> GetDocuments(string _containerId);
        //Returns a set of the containers of document Ids
        unordered_set<string> GetContainers(string _documentId);

        //Returns 1 if there's already a doc with the same Id, 0 else
        int AddDocument(string _id, string _title, string _description, float _length);
        void RemoveDocument(string _id);
        //Returns 1 if there's already a container with the same Id, 0 else
        int AddContainer(string _id, string _title, string _description);
        void RemoveContainer(string _id);

        //Returns 1 if the container or the document doesn't exists, 0 else
        int StoreDocument(string _documentId, string _containerId);
        
    private:
        //Links the Id with the objects
        unordered_map<string, Document*> m_documents;
        unordered_map<string,Container*> m_containers;

        //Parents documents and containers using ids.
        unordered_map<string, unordered_set<string>> m_documentsToContainers;
        unordered_map<string, unordered_set<string>> m_containersToDocuments;
};

#endif
