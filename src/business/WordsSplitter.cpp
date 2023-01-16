//
// Created by Алексей Заузин on 11.01.2023.
//

#include <string>
#include "WordsSplitter.h"
#include <regex>

std::vector<std::string> WordsSplitter::splitSentence(std::string input) {
    std::vector<std::string> result = std::vector<std::string>();
    std::string buffer = "";

    for (int i = 0; i <= input.size(); i++) {
        if (this->isAlphabeticCharacter(input[i])) {
            buffer.push_back(input[i]);
        } else {
            if (buffer.size() > 0) {
                result.push_back(buffer);
                buffer.clear();
            }
        }
    }

    return result;
}

bool WordsSplitter::isAlphabeticCharacter(char c) {
    std::string str;
    str.append(&c);
    return std::regex_match(str, std::regex("[aA-zZ].*"));
}
