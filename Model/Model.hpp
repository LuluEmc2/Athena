#ifndef _MODEL_
#define _MODEL_

#include <unordered_set>
#include <unordered_map>
#include "Document.hpp"
#include "Container.hpp"

using namespace std;

class Model
{
    public:
        Model();

        unordered_map<string, Document*> GetDocuments();
        unordered_set<Document*> GetDocuments(Container* _container);
        unordered_set<Document*> GetDocuments(string _containerId);
        unordered_map<string,Container*> GetContainers();
        unordered_set<Container*> GetContainers(Document* _document);
        unordered_set<Container*> GetContainers(string _documentId);

        //Returns 1 if there's already a doc with the same Id, 0 else
        int AddDocument(string _id, string _title, string _description, int _pages);
        void RemoveDocument(string _id);
        //Returns 1 if there's already a container with the same Id, 0 else
        int AddContainer(string _id, string _title, string _description);
        void RemoveContainer(string _id);

        int StoreDocument(string _documentId, string _containerId);
        
    private:
        //Links the Id with the objects
        unordered_map<string, Document*> m_documents;
        unordered_map<string,Container*> m_containers;

        unordered_map<Document*, unordered_set<Container*>> m_documentsToContainers;
        unordered_map<Container*, unordered_set<Document*>> m_containersToDocuments;
};

#endif
