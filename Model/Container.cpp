#include "Container.hpp"
#include "Document.hpp"

using namespace std;

Container::Container(string _name, string _description)
{
    m_name = _name;
    m_description = _description;
}


string Container::GetName() const
{
    return m_name;
}

string Container::GetDescription() const
{
    return m_description;
}

list<Document*> Container::GetDocuments() const
{
    return m_documents;
}

list<Container*> Container::GetContainers() const
{
    return m_containers;
}


void Container::SetName(string _name)
{
    m_name = _name;
}

void Container::SetDescription(string _description)
{
    m_description = _description;
}


void Container::AddDocument(Document* _document)
{
    m_documents.push_back(_document);
}

void Container::RemoveDocument(Document* _document)
{
    m_documents.remove(_document);
}

void Container::AddContainer(Container* _container)
{
    m_containers.push_back(_container);
}

void Container::RemoveContainer(Container* _container)
{
    m_containers.remove(_container);
}
