/*
 * Markov.cpp
 *
 *  Created on: Mar 2, 2013
 *      Author: Adam
 */

#include "Utils/Markov.h"
#include "Utils/Utils.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

using namespace Utils;


std::map<char, std::vector<char> > Markov::MarkovMap;

Markov & Markov::getInstance()
{
    static Markov m;
    return m;
}

Markov::Markov()
{
    using namespace std;

    ifstream fFile;
    string name = "";
    const std::string letters = "abcdefghijklmnopqrstuvwxyz";
    vector<string> names;

    fFile.open("names.txt");
    if (!fFile.is_open())
    {
        throw(runtime_error("Error opening names.txt"));
    }

    while (fFile >> name)
    {
        names.push_back(name);
    }
    fFile.close();

    for (unsigned int i = 0; i < names.size(); i++)
    {
        for (unsigned int j = 0; j < names[i].length()-1; j++)
        {
            if (letters.find(names[i][j]) != string::npos)
                MarkovMap[names[i][j]].push_back(names[i][j+1]);
        }
    }
}


std::string Markov::getWord(unsigned int size, bool properName) const
{
    const std::string letters = "abcdefghijklmnopqrstuvwxyz";
    std::string word = "";

    int letter = letters[Utils::uniform(0, letters.size())];

    for (unsigned int i=0; i < size; ++i)
    {
        letter = MarkovMap[letter][Utils::uniform(0, MarkovMap[letter].size())];
        word += letter;
    }

    if (properName)
        word[0] = toupper(word[0]);

    return word;
}

std::string Markov::getWord(bool properName) const
{
    unsigned int size = Utils::uniform(5, 15);

    return getWord(size, properName);
}

std::string Markov::getProperWord() const
{
    return getWord(true);
}

std::string Markov::getProperWord(unsigned int size) const
{
    return getWord(size, true);
}

std::string Markov::getRegionName() const
{
    if (Utils::uniform(0, 2))
    {
        return "Region of " + getProperWord();
    }
    else
    {
        return getProperWord() + " Region";
    }
}

std::string Markov::getVillageName() const
{
    if (Utils::uniform(0, 2))
    {
        return "Village of " + getProperWord();
    }
    else
    {
        return getProperWord() + " Village";
    }
}

std::string Markov::getIndividualName(std::string familyName) const
{
    if (!familyName.empty())
    {
        return getProperWord() + " " + familyName;
    }
    else
    {
        return getProperWord() + " " + getProperWord();
    }
}
