#include "big_words.h"

namespace jb_rider_test_task {
void BigWords::add(const std::string &word, std::size_t index) {
    words.emplace(word, index);
}

bool BigWords::prefix_function(const std::string &string,
                               std::size_t pattern_length) {
    std::vector<std::size_t> p(string.size());
    for (std::size_t i = 1; i < string.size(); ++i) {
        std::size_t j = p[i - 1];
        while (j > 0 && string[i] != string[j]) {
            j = p[j - 1];
        }
        if (string[i] == string[j]) {
            ++j;
        }
        p[i] = j;
    }

    for (std::size_t i = 2 * pattern_length; i < string.size(); ++i) {
        if (p[i] == pattern_length) {
            return true;
        }
    }
    return false;
}

void BigWords::find(const std::string &pattern, std::vector<bool> &mask) const {
    for (auto &[word, index] : words) {
        if (pattern.size() > word.size()) {
            break;
        }
        if (prefix_function(pattern + '$' + word, pattern.size())) {
            mask[index] = true;
        }
    }
}

}  // namespace jb_rider_test_task
