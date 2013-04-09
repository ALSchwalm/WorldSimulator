#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <vector>

namespace Interface
{
	namespace CLI
	{
		class Token
		{
		public:
			static std::vector<Token>tokenize(std::string);

			Token(std::string s) :
				value(s){}

			bool operator==(const Token &);
			bool operator!=(const Token &);

			std::string value;


		};
	}
}

#endif
