#include "Container.hpp"
#include "Book.hpp"

using namespace std;

Container::Container(string _name, string _description)
{
    m_name = _name;
    m_description = _description;
}

string Container::GetName() const
{
    return m_name;
}

string Container::GetDescription() const
{
    return m_description;
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

void Container::AddContainer(Container* _container)
{
    m_containers.push_back(_container);
}

void Container::RemoveContainer(Container* _container)
{
    m_containers.remove(_container);
}
