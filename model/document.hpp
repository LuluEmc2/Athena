#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

namespace document
{
	class Document
	{
		public:
			Document(std::string _title, std::string _description = "", double _length = 0);

			std::string GetTitle() const;
			std::string GetDescription() const;
			double GetLength() const;

			void SetTitle(std::string _title);
			void SetDescription(std::string _description);
			void SetLength(double _length);

		private:
			std::string m_title;
			std::string m_description;
			double m_length;
	};
}

#endif
