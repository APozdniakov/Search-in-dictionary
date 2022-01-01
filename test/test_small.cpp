#include <gtest/gtest.h>
#include <vector>
#include "test.h"
#include "trie.h"

TEST(test_small, random) {
    for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
        std::vector<std::string> dictionary(random(1, MAX_LENGTH));
        for (auto &i : dictionary) {
            i = random_string();
        }

        jb_rider_test_task::Trie trie;
        for (std::size_t i = 0; i < dictionary.size(); ++i) {
            trie.add(dictionary[i], i);
        }

        for (int test = 0; test < TESTS; ++test) {
            auto input = random_string();
            std::vector<bool> result(dictionary.size());
            trie.find(input, result);
            for (std::size_t i = 0; i < dictionary.size(); ++i) {
                ASSERT_EQ(result[i], stupid_find(input, dictionary[i]));
            }
        }
    }
}
