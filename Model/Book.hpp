#ifndef _BOOK_
#define _BOOK_

#include "Container.hpp"
#include <string>

using namespace std;

class Book
{
	public:
		Book(string _title, string _description, int _pages);

		string GetTitle() const;
		string GetDescription() const;
		int GetPages() const;
		list<Container*> GetContainers() const;

		void SetTitle(string _title);
		void SetDescription(string _description);
		void SetPages(int _pages);

		void AddContainer(Container* _container);
		void RemoveContainer(Container* _container);

	private:
		string m_title;
		string m_description;
		int m_pages;
		list<Container*> m_containers;

};

#endif
