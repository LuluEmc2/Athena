#include <list>
#include <unordered_map>
#include "Model.hpp"

using namespace std;

Model::Model(){}


list<Document*> Model::GetDocuments()
{
    return m_documents;
}

list<Document*> Model::GetDocuments(Container* _container)
{
    return m_containersToDocuments[_container];
}

list<Container*> Model::GetContainers()
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


void Model::AddDocument(Document* _document)
{
    m_documents.push_back(_document);
}

void Model::RemoveDocument(Document* _document)
{
    m_documents.remove(_document);
}

void Model::AddContainer(Container* _container)
{
    m_containers.push_back(_container);
}

void Model::RemoveContainer(Container* _container)
{
    m_containers.remove(_container);
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
