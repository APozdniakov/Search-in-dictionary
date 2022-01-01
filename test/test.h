#ifndef TEST_H
#define TEST_H

#include <chrono>
#include <random>
#include <string>

static constexpr int ITERATIONS = 50;
static constexpr int TESTS = 50;
static constexpr int MAX_LENGTH = 100;

template <typename T>
T random(T l, T r) {
    static std::mt19937 rnd(
        std::chrono::high_resolution_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<T> random(l, r);
    return random(rnd);
}

std::string random_string();

bool stupid_find(const std::string &, const std::string &);

#endif  // TEST_H
