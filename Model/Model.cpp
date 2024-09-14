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


int Model::AddDocument(string _id, string _title, string _description, int _pages)
{
    if(m_documents[_id] != nullptr)
    {
        return 1;
    }

    m_documents[_id] = new Document(_title, _description, _pages);

    return 0;
}

void Model::RemoveDocument(string _id)
{
    delete m_documents[_id];
    m_documents.erase(_id);
}

int Model::AddContainer(string _id, string _title, string _description)
{
    if(m_containers[_id] != nullptr)
    {
        return 1;
    }

    m_containers[_id] = new Container(_title, _description);

    return 0;
}

void Model::RemoveContainer(string _id)
{
    delete m_containers[_id];
    m_containers.erase(_id);
}


void Model::StoreDocument(string _documentId, string _containerId)
{
    m_documentsToContainers[m_documents[_documentId]].insert(m_containers[_containerId]);
    m_containersToDocuments[m_containers[_containerId]].insert(m_documents[_documentId]);
}