#include <document.hpp>

namespace document
{
	Document::Document(std::string _title, std::string _description, double _length)
	{
		m_title = _title;
		m_description = _description;
		m_length = _length;
	}

	std::string Document::GetTitle() const
	{
		return m_title;
	}

	std::string Document::GetDescription() const
	{
		return m_description;
	}

	double Document::GetLength() const
	{
		return m_length;
	}


	void Document::SetTitle(std::string _title)
	{
		m_title = _title;
	}

	void Document::SetDescription(std::string _description)
	{
		m_description = _description;
	}

	void Document::SetLength(double _length)
	{
		m_length = _length;
	}
}