#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>

using namespace std;

class Container
{
	public:
		Container(string _name, string _description = "");

		string GetName() const;
		string GetDescription() const;

		void SetName(string _name);
		void SetDescription(string _description);

	private:
		string m_name;
		string m_description;
};

#endif
