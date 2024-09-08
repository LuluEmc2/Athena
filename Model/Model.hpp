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

        void AddDocument(Document* _document);
        void RemoveDocument(Document* _document);
        void AddContainer(Container* _container);
        void RemoveContainer(Container* _container);

        void Store(Document* _document, Container* _container);
//        void Store(Container* _childContainer, Container* _parentContainer);

    private:
        list<Document*> m_documents;
        list<Container*> m_containers;
        unordered_map<Document*, Container*> m_documentsToContainers;
        unordered_map<Container*, Document*> m_containersToDocuments;
};

#endif
