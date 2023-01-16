//
// Created by Алексей Заузин on 11.01.2023.
//

#ifndef EXERCISE03_WORDSSPLITTER_H
#define EXERCISE03_WORDSSPLITTER_H
#include <vector>
#include <regex>
#include <string>

class WordsSplitter {
    public:
        std::vector<std::string> splitSentence(std::string input);
    private:
        bool isAlphabeticCharacter(char c);
};


#endif //EXERCISE03_WORDSSPLITTER_H
