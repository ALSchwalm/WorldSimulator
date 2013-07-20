
#include "Interface/CLI/Token.h"
#include <sstream>

namespace Interface
{
    namespace CLI
    {
        std::vector<Token>Token::tokenize(std::string line)
        {

            /*
            In order to allow generic inputs (i.e. show <INDIVIDUAL NAME>) a special char is needed to represent the generic.
            '*' is this char. Tokens containing '*' are eq to any non empty token. By a happy coincidnece, this also lets us
            give possible completions for the next argument. So when the user has typed in all of one argument, followed by a
            space, append an '*'. This will show all possible completions from the current position, as all of the next tokens
            are eq to the appended '*'.
            */
            if (line.back() == ' ' || line.size() == 0)
                line+="*";

            std::string buf;
            std::stringstream ss(line);

            std::vector<Token> tokens;

            while (ss >> buf) {
                if (buf[0] == '\"'){                //the user has wrapped some text in quotes
                    std::string quoteToken = buf;
                    quoteToken += " ";              //re add the spaces
                    while (ss >> buf) {
                        quoteToken += buf;
                        if (buf[buf.size()-1] == '\"')      //end of quotes
                            break;
                        quoteToken += " ";
                    }
                    buf = quoteToken.substr(1, quoteToken.size()-2);    //remove the quotes
                }

                tokens.push_back(Token(buf));
            }
            return tokens;
        }

        bool Token::operator==(const Token & rhs)
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

        bool Token::operator!=(const Token & rhs)
        {
            return !((*this) == rhs);
        }

    }
}
