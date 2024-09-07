#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>
#include <list>

using namespace std;

class Book;

class Container
{
	public:
		Container(string _name);
		string GetName() const;
        list<Book*> GetBooks() const;
        list<Container*> GetContainers() const;
		void AddBook(Book* _book);
		void RemoveBook(Book* _book);

	private:
		string m_name;
		list<Book*> m_books;
        list<Container*> m_containers;
};

#endif
