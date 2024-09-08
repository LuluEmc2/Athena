#include "Document.hpp"

using namespace std;

Document::Document(string _title, string _description, int _pages)
{
	m_title = _title;
	m_description = _description;
	m_pages = _pages;
}


string Document::GetTitle() const
{
	return m_title;
}

string Document::GetDescription() const
{
	return m_description;
}

int Document::GetPages() const
{
	return m_pages;
}

list<Container*> Document::GetContainers() const
{
	return m_containers;
}


void Document::SetTitle(string _title)
{
	m_title = _title;
}

void Document::SetDescription(string _description)
{
	m_description = _description;
}

void Document::SetPages(int _pages)
{
	m_pages = _pages;
}


void Document::AddContainer(Container* _container)
{
	m_containers.push_back(_container);
}

void Document::RemoveContainer(Container* _container)
{
	m_containers.remove(_container);
}
