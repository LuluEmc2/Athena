#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

using namespace std;

class Document
{
	public:
		Document(string _title, string _description = "", int _pages = 0, int _year = 0);

		string GetTitle() const;
		string GetDescription() const;
		int GetPages() const;
		int GetYear() const;

		void SetTitle(string _title);
		void SetDescription(string _description);
		void SetPages(int _pages);
		void SetYear(int _year);

	private:
		string m_title;
		string m_description;
		int m_pages;
		int m_year;
};

#endif
