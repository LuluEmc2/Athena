#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

using namespace std;

class Document
{
	public:
		Document(string _title, string _description = "", int _pages = 0, int _year = 0, string _format = "");

		string GetTitle() const;
		string GetDescription() const;
		int GetPages() const;
		int GetYear() const;
		string GetFormat() const;

		void SetTitle(string _title);
		void SetDescription(string _description);
		void SetPages(int _pages);
		void SetYear(int _year);
		void SetFormat(string _format);

	private:
		string m_title;
		string m_description;
		int m_pages;
		int m_year;
		string m_format;
};

#endif
