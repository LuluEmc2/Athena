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
        Container* GetParent(Container* _childContainer);
        Container* GetParent(string _childContainerId);
        unordered_set<Container*> GetChilds(Container* _parentContainer);
        unordered_set<Container*> GetChilds(string _parentContainerId);

        //Returns 1 if there's already a doc with the same Id, 0 else
        int AddDocument(Document* _document);
        void RemoveDocument(Document* _document);
        //Returns 1 if there's already a container with the same Id, 0 else
        int AddContainer(Container* _container);
        void RemoveContainer(Container* _container);

        void StoreDocument(Document* _document, Container* _container);
        void StoreDocument(string _documentId, string _containerId);
        void StoreContainer(Container* _childContainer, Container* _parentContainer);
        void StoreContainer(string _childContainerId, string _parentContainerId);

    private:
        //Links the Id with the objects
        unordered_map<string, Document*> m_documents;
        unordered_map<string,Container*> m_containers;

        unordered_map<Document*, unordered_set<Container*>> m_documentsToContainers;
        unordered_map<Container*, unordered_set<Document*>> m_containersToDocuments;

        unordered_map<Container*, Container*> m_childsToParents;
        unordered_map<Container*, unordered_set<Container*>> m_parentsToChilds;
};

#endif
