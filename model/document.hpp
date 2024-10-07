#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

namespace document
{
	class Document
	{
		public:
			Document(std::string _title, std::string _description = "", double _length = 0);

			std::string get_title() const;
			std::string get_description() const;
			double get_length() const;

			void set_title(std::string _title);
			void set_description(std::string _description);
			void set_length(double _length);

		private:
			std::string m_title;
			std::string m_description;
			double m_length;
	};
}

#endif
