#include "trie.h"

namespace jb_rider_test_task {
Trie::Trie() : root(new Node()) {
}

void Trie::dfs(Node *node, std::vector<bool> &mask) {
    if (!node) {
        return;
    }
    for (auto &[c, next_node] : node->next) {
        dfs(next_node.get(), mask);
    }
    for (auto index : node->indexes) {
        mask[index] = true;
    }
}

void Trie::add_string(const std::string_view &string_view, std::size_t index) {
    Node *node = root.get();
    for (char c : string_view) {
        if (node->next.find(c) == node->next.end()) {
            node->next[c] = std::make_unique<Node>();
        }
        node = node->next[c].get();
    }
    node->indexes.push_back(index);
}

void Trie::add(const std::string &string, std::size_t index) {
    std::string_view string_view(string);
    for (std::size_t i = 0; i < string_view.size(); ++i) {
        add_string(string_view.substr(i), index);
    }
}

void Trie::find(const std::string &pattern, std::vector<bool> &mask) {
    Node *node = root.get();
    for (char c : pattern) {
        if (node->next.find(c) == node->next.end()) {
            return;
        }
        node = node->next[c].get();
    }
    dfs(node, mask);
}

}  // namespace jb_rider_test_task
