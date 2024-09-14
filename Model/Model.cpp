#include <list>
#include <unordered_map>
#include "Model.hpp"

using namespace std;

Model::Model(){}


unordered_set<string> Model::GetDocuments(string _containerId)
{
    return m_containersToDocuments[_containerId];
}

unordered_set<string> Model::GetContainers(string _documentId)
{
    return m_documentsToContainers[_documentId];
}


int Model::AddDocument(string _id, string _title, string _description, float _length)
{
    if(m_documents[_id] != nullptr)
    {
        return 1;
    }

    m_documents[_id] = new Document(_title, _description, _length);

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


int Model::StoreDocument(string _documentId, string _containerId)
{
    if(m_documents[_documentId] == nullptr || m_containers[_containerId] == nullptr)
    {
        return 1;
    }

    m_documentsToContainers[_documentId].insert(_containerId);
    m_containersToDocuments[_containerId].insert(_documentId);

    return 0;
}