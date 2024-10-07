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


	void Document::set_title(std::string _title)
	{
		m_title = _title;
	}

	void Document::set_description(std::string _description)
	{
		m_description = _description;
	}

	void Document::set_length(double _length)
	{
		m_length = _length;
	}
}