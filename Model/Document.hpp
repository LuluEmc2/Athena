#ifndef _DOCUMENT_
#define _DOCUMENT_

#include <string>

using namespace std;

class Document
{
	public:
		Document(string _title, string _description = "", float _length = 0);

		string GetTitle() const;
		string GetDescription() const;
		float GetLength() const;

		void SetTitle(string _title);
		void SetDescription(string _description);
		void SetLength(float _length);

	private:
		string m_title;
		string m_description;
		float m_length;
};

#endif
