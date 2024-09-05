#include "Book.hpp"

using namespace std;

Book::Book(string _title, string _description, int _pages, Container* _container)
{
	m_title = _title;
	m_description = _description;
	m_pages = _pages;
	m_container = _container;
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

Container* Book::GetContainer() const
{
	return m_container;
}
