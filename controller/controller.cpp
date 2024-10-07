#include <controller.hpp>

namespace controller
{
    Controller::Controller(){}

    std::unordered_map<std::string, document::Document*> Controller::get_all_documents()
    {
        return m_documents;
    }

    std::unordered_map<std::string, container::Container*> Controller::get_all_containers()
    {
        return m_containers;
    }

    std::unordered_map<std::string, std::unordered_set<std::string>> Controller::get_all_connexions()
    {
        return m_documentsToContainers;
    }


    std::tuple<std::string, std::string, std::string, double> Controller::get_document(std::string _documentId)
    {
        if(m_documents[_documentId] == nullptr)
        {
            return {NO_FOUND_ERROR, "", "", 0.0f};
        }

        std::string title = m_documents[_documentId]->get_title();
        std::string description = m_documents[_documentId]->get_description();
        double length = m_documents[_documentId]->get_length();

        return {_documentId, title, description, length};
    }

    std::tuple<std::string, std::string, std::string> Controller::get_container(std::string _containerId)
    {
        if(m_containers[_containerId] == nullptr)
        {
            return {NO_FOUND_ERROR, "", ""};
        }

        std::string name = m_containers[_containerId]->get_name();
        std::string description = m_containers[_containerId]->get_description();

        return {_containerId, name, description};
    }

    std::unordered_set<std::string> Controller::get_documents(std::string _containerId)
    {
        return m_containersToDocuments[_containerId];
    }

    std::unordered_set<std::string> Controller::get_containers(std::string _documentId)
    {
        return m_documentsToContainers[_documentId];
    }

    std::unordered_set<std::string> Controller::get_ids(std::string _name)
    {
        return m_namesToIds[_name];
    }


    int Controller::add_document(std::string _id, std::string _title, std::string _description, double _length)
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

    int Controller::remove_document(std::string _id)
    {
        if(m_documents.count(_id) == 0)
        {
            return 1;
        }

        m_namesToIds.erase(m_documents[_id]->get_title());

        delete m_documents[_id];

        for (auto& container : get_containers(_id))
        {
            m_containersToDocuments[container].erase(_id);
        }

        m_documentsToContainers.erase(_id);

        m_documents.erase(_id);

        return 0;
    }

    int Controller::add_container(std::string _id, std::string _name, std::string _description)
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

    int Controller::remove_container(std::string _id)
    {
        if(m_containers.count(_id) == 0)
        {
            return 1;
        }

        m_namesToIds.erase(m_containers[_id]->get_name());

        delete m_containers[_id];

        for (auto& document : get_documents(_id))
        {
            m_documentsToContainers[document].erase(_id);
        }

        m_containersToDocuments.erase(_id);

        m_containers.erase(_id);

        return 0;
    }

    int Controller::store_document(std::string _documentId, std::string _containerId)
    {
        if(m_documents.count(_documentId) == 0 || m_documents.count(_documentId) == 0)
        {
            return 1;
        }

        m_documentsToContainers[_documentId].insert(_containerId);
        m_containersToDocuments[_containerId].insert(_documentId);

        return 0;
    }

    int Controller::unstore_document(std::string _documentId, std::string _containerId)
    {
        if(m_documents.count(_documentId) == 0 || m_documents.count(_documentId) == 0)
        {
            return 1;
        }

        if(m_containersToDocuments.count(_containerId) == 0)
        {
            return -1;
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