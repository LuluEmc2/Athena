#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>
#include <list>

using namespace std;

class Container
{
	public:
		Container(string _name, string _description);

		string GetName() const;
		string GetDescription() const;
        list<Container*> GetContainers() const;

		void SetName(string _name);
		void SetDescription(string _description);

		void AddContainer(Container* _container);
		void RemoveContainer(Container* _container);

	private:
		string m_name;
		string m_description;
        list<Container*> m_containers;
};

#endif
