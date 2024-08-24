#include "Book.hpp"
#include <string>

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
