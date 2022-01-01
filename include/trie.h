#ifndef TRIE_H
#define TRIE_H

#include <cstddef>
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

namespace jb_rider_test_task {
class Trie {
    struct Node {
        std::unordered_map<char, std::unique_ptr<Node>> next;
        std::vector<std::size_t> indexes;
    };
    std::unique_ptr<Node> root;
    void dfs(Node *, std::vector<bool> &);
    void add_string(const std::string_view &, std::size_t);

public:
    Trie();
    void add(const std::string &, std::size_t);
    void find(const std::string &, std::vector<bool> &);
};
}  // namespace jb_rider_test_task

#endif  // TRIE_H
