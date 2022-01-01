#include <gtest/gtest.h>
#include <vector>
#include "big_words.h"
#include "test.h"

TEST(test_big, random) {
    for (int iteration = 0; iteration < ITERATIONS; ++iteration) {
        std::vector<std::string> dictionary(random(1, MAX_LENGTH));
        for (auto &i : dictionary) {
            i = random_string();
        }

        jb_rider_test_task::BigWords big_words;
        for (std::size_t i = 0; i < dictionary.size(); ++i) {
            big_words.add(dictionary[i], i);
        }

        for (int test = 0; test < TESTS; ++test) {
            auto input = random_string();
            std::vector<bool> result(dictionary.size());
            big_words.find(input, result);
            for (std::size_t i = 0; i < dictionary.size(); ++i) {
                ASSERT_EQ(result[i], stupid_find(input, dictionary[i]));
            }
        }
    }
}
