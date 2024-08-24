#ifndef _BOOK_
#define _BOOK_

#include <string>

using namespace std;

class Book
{
	public:
		Book(string _title, string _description, int _pages);		
		string GetTitle() const;
	       	string GetDescription() const;
		int GetPages() const;	

	private:
		string m_title;
		string m_description;
		int m_pages;
};

#endif
