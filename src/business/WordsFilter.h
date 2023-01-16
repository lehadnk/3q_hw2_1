//
// Created by Алексей Заузин on 11.01.2023.
//

#ifndef EXERCISE03_WORDSFILTER_H
#define EXERCISE03_WORDSFILTER_H


#include <vector>
#include <string>

class WordsFilter {
    public:
        std::vector<std::string> filterWordList(std::vector<std::string> input);
    private:
        bool isEndsWithVowel(std::string word);
};


#endif //EXERCISE03_WORDSFILTER_H
