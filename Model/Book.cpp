#include "Book.hpp"

using namespace std;

Book::Book(string _title, string _description, int _pages)
{
	m_title = _title;
	m_description = _description;
	m_pages = _pages;
}


string Book::GetTitle() const
{
	return m_title;
}

string Book::GetDescription() const
{
	return m_description;
}

int Book::GetPages() const
{
	return m_pages;
}

list<Container*> Book::GetContainers() const
{
	return m_containers;
}


void Book::SetTitle(string _title)
{
	m_title = _title;
}

void Book::SetDescription(string _description)
{
	m_description = _description;
}

void Book::SetPages(int _pages)
{
	m_pages = _pages;
}


void Book::AddContainer(Container* _container)
{
	m_containers.push_back(_container);
}

void Book::RemoveContainer(Container* _container)
{
	m_containers.remove(_container);
}
