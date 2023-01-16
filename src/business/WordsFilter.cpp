//
// Created by Алексей Заузин on 11.01.2023.
//

#include "WordsFilter.h"
#include <vector>
#include <regex>

std::vector<std::string> WordsFilter::filterWordList(std::vector<std::string> input) {
    std::vector<std::string> result = std::vector<std::string>();
    for(std::string word: input) {
        if (this->isEndsWithVowel(word)) {
            result.push_back(word);
        }
    }

    return result;
}

bool WordsFilter::isEndsWithVowel(std::string word) {
    return std::regex_match(word, std::regex(".*[AaEeYyUuIiOo]$"));
}
