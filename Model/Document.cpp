#include "Document.hpp"

using namespace std;

Document::Document(string _id, string _title, string _description, int _pages, int _year, string _format)
{
	m_id = _id;
	m_title = _title;
	m_description = _description;
	m_pages = _pages;
	m_year = _year;
	m_format = _format;
}

string Document::GetId() const
{
	return m_id;
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

int Document::GetYear() const
{
	return m_year;
}

string Document::GetFormat() const
{
	return m_format;
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

void Document::SetYear(int _year)
{
	m_year = _year;
}

void Document::SetFormat(string _format)
{
	m_format = _format;
}
