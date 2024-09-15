#include "Document.hpp"

using namespace std;

Document::Document(string _title, string _description, double _length)
{
	m_title = _title;
	m_description = _description;
	m_length = _length;
}

string Document::GetTitle() const
{
	return m_title;
}

string Document::GetDescription() const
{
	return m_description;
}

double Document::GetLength() const
{
	return m_length;
}


void Document::SetTitle(string _title)
{
	m_title = _title;
}

void Document::SetDescription(string _description)
{
	m_description = _description;
}

void Document::SetLength(double _length)
{
	m_length = _length;
}
