#include "Author.hpp"
#include "Book.hpp"

using namespace std;

Author::Author(string _name)
{
    m_name = _name;
}

string Author::GetName() const
{
    return m_name;
}

list<Book*> Author::GetBooks() const
{
    return m_books;
}
