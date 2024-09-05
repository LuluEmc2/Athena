#ifndef _AUTHOR_
#define _AUTHOR_

#include <string>
#include <list>

using namespace std;

class Book;

class Author
{
	public:
		Author(string _name);
		string GetName() const;
        list<Book*> GetBooks() const;

	private:
		string m_name;
		list<Book*> m_books;
};

#endif
