#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>
#include <list>

using namespace std;

class Book;

class Container
{
	public:
		Container(string _name, string _description);
		string GetName() const;
		string GetDescription() const;
        list<Book*> GetBooks() const;
        list<Container*> GetContainers() const;
		void AddBook(Book* _book);
		void RemoveBook(Book* _book);
		void AddContainer(Container* _container);
		void RemoveContainer(Container* _container);

	private:
		string m_name;
		string m_description;
		list<Book*> m_books;
        list<Container*> m_containers;
};

#endif
