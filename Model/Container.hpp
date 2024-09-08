#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>
#include <list>

using namespace std;

class Document;

class Container
{
	public:
		Container(string _name, string _description);

		string GetName() const;
		string GetDescription() const;
        list<Document*> GetDocuments() const;
        list<Container*> GetContainers() const;

		void SetName(string _name);
		void SetDescription(string _description);

		void AddDocument(Document* _document);
		void RemoveDocument(Document* _document);
		void AddContainer(Container* _container);
		void RemoveContainer(Container* _container);

	private:
		string m_name;
		string m_description;
		list<Document*> m_documents;
        list<Container*> m_containers;
};

#endif
