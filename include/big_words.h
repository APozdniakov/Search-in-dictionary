#ifndef SEARCH_H
#define SEARCH_H

#include <cstddef>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace jb_rider_test_task {
class BigWords final {
    struct Comparator {
        bool operator()(const std::pair<std::string, std::size_t> &lhs,
                        const std::pair<std::string, std::size_t> &rhs) const {
            return lhs.first.size() > rhs.first.size();
        }
    };
    std::multiset<std::pair<std::string, std::size_t>, Comparator> words;
    static bool prefix_function(const std::string &, std::size_t);

public:
    void add(const std::string &, std::size_t);
    void find(const std::string &, std::vector<bool> &) const;
};
}  // namespace jb_rider_test_task

#endif  // SEARCH_H
