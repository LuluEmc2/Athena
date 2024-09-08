#include <list>
#include <unordered_map>
#include "Model.hpp"

using namespace std;

Model::Model(){}


list<Document*> Model::GetDocuments()
{
    return m_documents;
}

list<Container*> Model::GetContainers()
{
    return m_containers;
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
    m_documentsToContainers[_document] = _container;
    m_containersToDocuments[_container] = _document;
}

void Model::Store(Container* _childContainer, Container* _parentContainer)
{
    m_childsToParents[_childContainer] = _parentContainer;
    m_parentsToChilds[_parentContainer] = _childContainer;
}
