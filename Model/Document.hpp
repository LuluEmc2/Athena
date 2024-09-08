#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

using namespace std;

class Document
{
	public:
		Document(string _title, string _description, int _pages);

		string GetTitle() const;
		string GetDescription() const;
		int GetPages() const;

		void SetTitle(string _title);
		void SetDescription(string _description);
		void SetPages(int _pages);

	private:
		string m_title;
		string m_description;
		int m_pages;
};

#endif
