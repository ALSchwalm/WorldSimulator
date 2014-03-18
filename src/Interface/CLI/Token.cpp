
#include "Interface/CLI/Token.h"
#include <boost/tokenizer.hpp>

namespace Interface
{
    namespace CLI
    {
        std::vector<Token>Token::tokenize(std::string line)
        {

            /*
            In order to allow generic inputs (i.e. show <INDIVIDUAL NAME>) a special char is needed to represent the generic.
            '*' is this char. Tokens containing '*' are eq to any non empty token. By a happy coincidence, this also lets us
            give possible completions for the next argument. So when the user has typed in all of one argument, followed by a
            space, append an '*'. This will show all possible completions from the current position, as all of the next tokens
            are eq to the appended '*'.
            */
            if (line.back() == ' ' || line.size() == 0)
                line+="*";

            std::vector<Token> tokens;

            using escapeList = boost::escaped_list_separator<char>;
            escapeList Separator('\\', ' ', '\"');
            boost::tokenizer<escapeList> tok(line, Separator );

            for(auto token : tok) {
                tokens.push_back(token);
            }

            return tokens;
        }

        bool Token::operator==(const Token & rhs) const
        {
            if (rhs.value.find(this->value) == 0)
            {
                return true;
            }
            //FIXME if user inputs '*', will count as any token
            else if ((rhs.value == "*" && this->value.size() > 0) ||
                    (rhs.value.size() > 0 && this->value == "*"))
            {
                return true;
            }
            return false;
        }
    }
}
