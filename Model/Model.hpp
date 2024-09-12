#ifndef _MODEL_
#define _MODEL_

#include <list>
#include <unordered_map>
#include "Document.hpp"
#include "Container.hpp"

using namespace std;

class Model
{
    public:
        Model();

        unordered_map<string, Document*> GetDocuments();
        list<Document*> GetDocuments(Container* _container);
        unordered_map<string,Container*> GetContainers();
        list<Container*> GetContainers(Document* _document);
        Container* GetParent(Container* _childContainer);
        list<Container*> GetChilds(Container* _parentContainer);

        int AddDocument(Document* _document);
        void RemoveDocument(Document* _document);
        int AddContainer(Container* _container);
        void RemoveContainer(Container* _container);

        void Store(Document* _document, Container* _container);
        void Store(Container* _childContainer, Container* _parentContainer);

    private:
        unordered_map<string, Document*> m_documents;
        unordered_map<string,Container*> m_containers;

        unordered_map<Document*, list<Container*>> m_documentsToContainers;
        unordered_map<Container*, list<Document*>> m_containersToDocuments;

        unordered_map<Container*, Container*> m_childsToParents;
        unordered_map<Container*, list<Container*>> m_parentsToChilds;
};

#endif
