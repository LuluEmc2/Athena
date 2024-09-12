#include <list>
#include <unordered_map>
#include "Model.hpp"

using namespace std;

Model::Model(){}


unordered_map<string, Document*> Model::GetDocuments()
{
    return m_documents;
}

list<Document*> Model::GetDocuments(Container* _container)
{
    return m_containersToDocuments[_container];
}

unordered_map<string, Container*> Model::GetContainers()
{
    return m_containers;
}

list<Container*> Model::GetContainers(Document* _document)
{
    return m_documentsToContainers[_document];
}

Container* Model::GetParent(Container* _childContainer)
{
    return m_childsToParents[_childContainer];
}

list<Container*> Model::GetChilds(Container* _parentContainer)
{
    return m_parentsToChilds[_parentContainer];
}


int Model::AddDocument(Document* _document)
{
    if(m_documents[_document->GetId()] != NULL)
    {
        return 1;
    }

    m_documents[_document->GetId()] = _document;

    return 0;
}

void Model::RemoveDocument(Document* _document)
{
    m_documents.erase(_document->GetId());
}

int Model::AddContainer(Container* _container)
{
    if(m_containers[_container->GetId()] != NULL)
    {
        return 1;
    }

    m_containers[_container->GetId()] = _container;

    return 0;
}

void Model::RemoveContainer(Container* _container)
{
    m_containers.erase(_container->GetId());
}


void Model::Store(Document* _document, Container* _container)
{
    m_documentsToContainers[_document].push_back(_container);
    m_containersToDocuments[_container].push_back(_document);
}

void Model::Store(Container* _childContainer, Container* _parentContainer)
{
    m_childsToParents[_childContainer] = _parentContainer;
    m_parentsToChilds[_parentContainer].push_back(_childContainer);
}
