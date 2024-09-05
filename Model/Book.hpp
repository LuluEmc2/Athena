#ifndef _BOOK_
#define _BOOK_

#include "Author.hpp"
#include "Container.hpp"
#include <string>

using namespace std;

class Book
{
	public:
		Book(string _title, string _description, int _pages, Author* _author, Container* _container);
		string GetTitle() const;
		string GetDescription() const;
		int GetPages() const;
		Author* GetAuthor() const;
		Container* GetContainer() const;

	private:
		string m_title;
		string m_description;
		int m_pages;
		Author* m_author;
		Container* m_container;

};

#endif
