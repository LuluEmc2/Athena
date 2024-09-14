#include <list>
#include <unordered_map>
#include "Model.hpp"

using namespace std;

Model::Model(){}


unordered_map<string, Document*> Model::GetDocuments()
{
    return m_documents;
}

unordered_set<Document*> Model::GetDocuments(Container* _container)
{
    return m_containersToDocuments[_container];
}

unordered_set<Document*> Model::GetDocuments(string _containerId)
{
    return m_containersToDocuments[m_containers[_containerId]];
}

unordered_map<string, Container*> Model::GetContainers()
{
    return m_containers;
}

unordered_set<Container*> Model::GetContainers(Document* _document)
{
    return m_documentsToContainers[_document];
}

unordered_set<Container*> Model::GetContainers(string _documentId)
{
    return m_documentsToContainers[m_documents[_documentId]];
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


void Model::StoreDocument(Document* _document, Container* _container)
{
    m_documentsToContainers[_document].insert(_container);
    m_containersToDocuments[_container].insert(_document);
}

void Model::StoreDocument(string _documentId, string _containerId)
{
    m_documentsToContainers[m_documents[_documentId]].insert(m_containers[_containerId]);
    m_containersToDocuments[m_containers[_containerId]].insert(m_documents[_documentId]);
}