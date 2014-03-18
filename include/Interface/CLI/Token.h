#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <vector>
#include <boost/operators.hpp>

namespace Interface
{
    namespace CLI
    {
        class Token : boost::equality_comparable<Token>
        {
        public:
            static std::vector<Token>tokenize(std::string);

            Token(std::string s) :
                value(s){}

            bool operator==(const Token&) const;

            std::string value;


        };
    }
}

#endif
