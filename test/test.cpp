#include "test.h"

std::string random_string() {
    std::string string(random(1, MAX_LENGTH), '.');
    for (char &c : string) {
        c = random<char>(0x31, 0x7E);
    }
    return string;
}

bool stupid_find(const std::string &word, const std::string &text) {
    if (word.size() > text.size()) {
        return false;
    }
    for (std::size_t i = 0; i <= text.size() - word.size(); ++i) {
        if (word == text.substr(i, word.size())) {
            return true;
        }
    }
    return false;
}
