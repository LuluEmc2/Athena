#ifndef _CONTAINER_
#define _CONTAINER_

#include <string>

namespace container 
{
	class Container
	{
		public:
			Container(std::string _name, std::string _description = "");

			std::string GetName() const;
			std::string GetDescription() const;

			void SetName(std::string _name);
			void SetDescription(std::string _description);

		private:
			std::string m_name;
			std::string m_description;
	};
}

#endif
