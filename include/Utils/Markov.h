/*
 * Markov.h
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#ifndef MARKOV_H_
#define MARKOV_H_

#include <map>
#include <string>
#include <vector>

namespace Utils
{
    class Markov {
    public:
        static Markov& getInstance();

        std::string getWord(bool properName=0) const ;
        std::string getWord(unsigned int, bool properName=0) const ;
        std::string getProperWord() const;
        std::string getProperWord(unsigned int) const;

        std::string getRegionName() const;
        std::string getVillageName() const;
        std::string getIndividualName(std::string familyName = "") const;


    private:

        static std::map<char, std::vector<char> > MarkovMap;
        Markov();

    };
}

#endif /* MARKOV_H_ */
