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

			void set_name(std::string _name);
			void set_description(std::string _description);

		private:
			std::string m_name;
			std::string m_description;
	};
}

#endif
