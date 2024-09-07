#include "Container.hpp"
#include "Book.hpp"

using namespace std;

Container::Container(string _name)
{
    m_name = _name;
}

string Container::GetName() const
{
    return m_name;
}

list<Book*> Container::GetBooks() const
{
    return m_books;
}

list<Container*> Container::GetContainers() const
{
    return m_containers;
}

void Container::AddBook(Book* _book)
{
    m_books.push_back(_book);
}

void Container::RemoveBook(Book* _book)
{
    m_books.remove(_book);
}
