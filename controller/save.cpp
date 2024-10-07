#include <save.hpp>
#include <iostream>

namespace save
{

    int SaveData(std::string _filepath, controller::Controller* _controller)
    {
        auto documents = _controller->GetAllDocuments();
        auto containers = _controller->GetAllContainers();
        auto documentsToContainers = _controller->GetAllConnexions();

        std::ofstream outFile(_filepath);

        if (!outFile.is_open())
        {
            return 1;
        }

        outFile << DOCUMENTS_FLAG << "\n";
        for (const auto& [id, doc] : documents)
        {
            outFile << std::quoted(id) << " " << std::quoted(doc->get_title()) << " " << std::quoted(doc->get_description()) << " " << doc->get_length() << "\n";
        }

        outFile << CONTAINERS_FLAG << "\n";
        for (const auto& [id, container] : containers)
        {
            outFile << std::quoted(id) << " " << std::quoted(container->GetName()) << " " << std::quoted(container->GetDescription()) << "\n";
        }

        outFile << LINKS_FLAG << "\n";
        for (const auto& [docId, containerSet] : documentsToContainers)
        {
            outFile << "\n" << std::quoted(docId) << "\n ";
            for (const auto& containerId : containerSet)
            {
                outFile << std::quoted(containerId) << " ";
            }
            outFile << "\n";
        }

    
        outFile.close();

        return 0;
    }

    int LoadData(std::string _filepath, controller::Controller* _controller)
    {
        std::ifstream inFile(_filepath);
        if (!inFile.is_open())
        {
            return 1;
        }

        std::string line;
    
        std::getline(inFile, line);
        if (line != DOCUMENTS_FLAG)
        {
            return 2;
        }
        while (std::getline(inFile, line) && line != CONTAINERS_FLAG)
        {
            std::istringstream iss(line);
            std::string id, title, description;
            double length;

            iss >> std::quoted(id) >> std::quoted(title) >> std::quoted(description) >> length;

            _controller->AddDocument(id, title, description, length);
        }

        if (line == CONTAINERS_FLAG)
        {
            while (std::getline(inFile, line) && line != LINKS_FLAG)
            {
                std::istringstream iss(line);
                std::string id, name, description;
                if (iss >> std::quoted(id) >> std::quoted(name) >> std::quoted(description))
                {
                    _controller->AddContainer(id, name, description);
                }
            }
        }

        if (line == LINKS_FLAG)
        {
            while (std::getline(inFile, line))
            {
                if (line.empty()) continue;  

                std::string docId;
                std::istringstream docStream(line);
                docStream >> std::quoted(docId);

                std::getline(inFile, line);
                std::istringstream containerStream(line);

                std::string containerId;

                // Lire tous les identifiants de conteneurs pour ce document
                while (containerStream >> std::quoted(containerId))
                {
                    _controller->StoreDocument(docId, containerId);
                }
            }
        }


        inFile.close();
        return 0;
    }
}