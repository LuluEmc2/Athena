#include <controller.hpp>

namespace controller
{
    Controller::Controller(){}

    std::unordered_map<std::string, document::Document*> Controller::GetAllDocuments()
    {
        return m_documents;
    }

    std::unordered_map<std::string, container::Container*> Controller::GetAllContainers()
    {
        return m_containers;
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> Controller::GetAllConnexions()
    {
        return m_documentsToContainers;
    }


    std::tuple<std::string, std::string, std::string, double> Controller::GetDocument(std::string _documentId)
    {
        if(m_documents[_documentId] == nullptr)
        {
            return {NO_FOUND_ERROR, "", "", 0.0f};
        }

        std::string title = m_documents[_documentId]->GetTitle();
        std::string description = m_documents[_documentId]->GetDescription();
        double length = m_documents[_documentId]->GetLength();

        return {_documentId, title, description, length};
    }

    std::tuple<std::string, std::string, std::string> Controller::GetContainer(std::string _containerId)
    {
        if(m_containers[_containerId] == nullptr)
        {
            return {NO_FOUND_ERROR, "", ""};
        }

        std::string name = m_containers[_containerId]->GetName();
        std::string description = m_containers[_containerId]->GetDescription();

        return {_containerId, name, description};
    }

    std::unordered_set<std::string> Controller::GetDocuments(std::string _containerId)
    {
        return m_containersToDocuments[_containerId];
    }

    std::unordered_set<std::string> Controller::GetContainers(std::string _documentId)
    {
        return m_documentsToContainers[_documentId];
    }

    std::unordered_set<std::string> Controller::GetIds(std::string _name)
    {
        return m_namesToIds[_name];
    }


    int Controller::AddDocument(std::string _id, std::string _title, std::string _description, double _length)
    {
        if(m_documents.count(_id) > 0 && m_documents[_id] != nullptr)
        {
            return 1;
        }

        if(m_containers.count(_id) > 0 && m_containers[_id] != nullptr)
        {
            return 1;
        }

        if(_id == NO_FOUND_ERROR)
        {
            return -1;
        }

        if (_id.find("\"") != std::string::npos
        ||  _title.find("\"") != std::string::npos
        ||  _description.find("\"") != std::string::npos) 
        {
            return 2;
        }

        m_namesToIds[_title].insert(_id);
        m_documents[_id] = new document::Document(_title, _description, _length);

        return 0;
    }

    int Controller::RemoveDocument(std::string _id)
    {
        if(m_documents[_id] == nullptr)
        {
            return 1;
        }

        m_namesToIds.erase(m_documents[_id]->GetTitle());

        delete m_documents[_id];

        for (auto& container : GetContainers(_id))
        {
            m_containersToDocuments[container].erase(_id);
        }

        m_documentsToContainers.erase(_id);

        m_documents.erase(_id);

        return 0;
    }

    int Controller::AddContainer(std::string _id, std::string _name, std::string _description)
    {
        if(m_documents.count(_id) > 0 && m_documents[_id] != nullptr)
        {
            return 1;
        }

        if(m_containers.count(_id) > 0 && m_containers[_id] != nullptr)
        {
            return 1;
        }

        if(_id == NO_FOUND_ERROR)
        {
            return -1;
        }

        if (_id.find("\"") != std::string::npos
        ||  _name.find("\"") != std::string::npos
        ||  _description.find("\"") != std::string::npos) 
        {
            return 2;
        }

        m_namesToIds[_name].insert(_id);
        m_containers[_id] = new container::Container(_name, _description);

        return 0;
    }

    int Controller::RemoveContainer(std::string _id)
    {
        if(m_containers[_id] == nullptr)
        {
            return 1;
        }

        m_namesToIds.erase(m_containers[_id]->GetName());

        delete m_containers[_id];

        for (auto& document : GetDocuments(_id))
        {
            m_documentsToContainers[document].erase(_id);
        }

        m_containersToDocuments.erase(_id);

        m_containers.erase(_id);

        return 0;
    }

    int Controller::StoreDocument(std::string _documentId, std::string _containerId)
    {
        if(m_documents[_documentId] == nullptr || m_containers[_containerId] == nullptr)
        {
            return 1;
        }

        m_documentsToContainers[_documentId].insert(_containerId);
        m_containersToDocuments[_containerId].insert(_documentId);

        return 0;
    }

    int Controller::UnstoreDocument(std::string _documentId, std::string _containerId)
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
}