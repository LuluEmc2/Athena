#include <document.hpp>

namespace document
{
	Document::Document(std::string _title, std::string _description, double _length)
	{
		m_title = _title;
		m_description = _description;
		m_length = _length;
	}

	std::string Document::get_title() const
	{
		return m_title;
	}

	std::string Document::get_description() const
	{
		return m_description;
	}

	double Document::get_length() const
	{
		return m_length;
	}
}