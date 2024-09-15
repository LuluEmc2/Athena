#include "Controller.hpp"

using namespace std;

Controller::Controller(){}

tuple<string, string, double> Controller::GetDocument(string _documentId)
{
    if(m_documents[_documentId] == nullptr)
    {
        return {"", "", 0.0f};
    }

    string title = m_documents[_documentId]->GetTitle();
    string description = m_documents[_documentId]->GetDescription();
    double length = m_documents[_documentId]->GetLength();

    return {title, description, length};
}

tuple<string, string> Controller::GetContainer(string _containerId)
{
    if(m_containers[_containerId] == nullptr)
    {
        return {"", ""};
    }

    string name = m_containers[_containerId]->GetName();
    string description = m_containers[_containerId]->GetDescription();

    return {name, description};
}

unordered_set<string> Controller::GetDocuments(string _containerId)
{
    return m_containersToDocuments[_containerId];
}

unordered_set<string> Controller::GetContainers(string _documentId)
{
    return m_documentsToContainers[_documentId];
}


int Controller::AddDocument(string _id, string _title, string _description, double _length)
{
    if(m_documents[_id] != nullptr || m_containers[_id] != nullptr)
    {
        return 1;
    }

    m_documents[_id] = new Document(_title, _description, _length);

    return 0;
}

int Controller::RemoveDocument(string _id)
{
    if(m_documents[_id] == nullptr)
    {
        return 1;
    }

    delete m_documents[_id];

    for (auto& container : GetContainers(_id))
    {
        m_containersToDocuments[container].erase(_id);
    }

    m_documentsToContainers.erase(_id);

    m_documents.erase(_id);

    return 0;
}

int Controller::AddContainer(string _id, string _title, string _description)
{
    if(m_documents[_id] != nullptr || m_containers[_id] != nullptr)
    {
        return 1;
    }

    m_containers[_id] = new Container(_title, _description);

    return 0;
}

int Controller::RemoveContainer(string _id)
{
    if(m_containers[_id] == nullptr)
    {
        return 1;
    }

    delete m_containers[_id];

    for (auto& document : GetDocuments(_id))
    {
        m_documentsToContainers[document].erase(_id);
    }

    m_containersToDocuments.erase(_id);

    m_containers.erase(_id);

    return 0;
}

int Controller::StoreDocument(string _documentId, string _containerId)
{
    if(m_documents[_documentId] == nullptr || m_containers[_containerId] == nullptr)
    {
        return 1;
    }

    m_documentsToContainers[_documentId].insert(_containerId);
    m_containersToDocuments[_containerId].insert(_documentId);

    return 0;
}

int Controller::UnstoreDocument(string _documentId, string _containerId)
{
    if(m_documents[_documentId] == nullptr || m_containers[_containerId] == nullptr)
    {
        return 1;
    }

    if(m_containersToDocuments[_containerId].count(_documentId) == 0)
    {
        return -1;
    }

    m_documentsToContainers[_documentId].erase(_containerId);
    m_containersToDocuments[_containerId].erase(_documentId);

    return 0;
}