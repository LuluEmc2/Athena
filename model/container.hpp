#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>

namespace container 
{
	class Container
	{
		public:
			Container(std::string _name, std::string _description = "");

			std::string get_name() const;
			std::string get_description() const;

		private:
			std::string m_name;
			std::string m_description;
	};
}

#endif
