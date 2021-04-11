#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),
      lineEdit(new QLineEdit()),
      listWidget(new QListWidget()) {
    setWindowTitle("Search in dictionary");

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->addWidget(lineEdit);
    gridLayout->addWidget(listWidget);
    setLayout(gridLayout);

    std::ifstream ifs("../dictionary/words.txt");
    if (ifs.is_open()) {
        for (std::string word; ifs >> word;) {
            words.push_back(std::move(word));
        }
    }

    for (std::size_t i = 0; i < words.size(); ++i) {
        for (std::size_t j = 0; j < words[i].size(); ++j) {
            auto *ptr = &small[words[i][j]];
            if (ptr->empty() || ptr->back() != i) {
                ptr->push_back(i);
            }
        }
        if (words[i].size() >= 10) big.push_back(i);
    }

    connect(lineEdit, &QLineEdit::textChanged, this, &Widget::search);
}

void Widget::search() {
    auto new_pattern = lineEdit->text().toStdString();
    if (!pattern.empty() && pattern.size() <= new_pattern.size() &&
            pattern == new_pattern.substr(0, pattern.size())) {
        pattern = new_pattern;
        for (int row = 0; row < listWidget->count(); ++row) {
            if (!isSubstring(pattern, listWidget->item(row)->text().toStdString())) {
                delete listWidget->item(row--);
            }
        }
        return;
    }

    listWidget->clear();
    pattern = new_pattern;
    if (pattern.empty()) {
        return;
    }
    if (pattern.size() >= 10) {
        for (std::size_t &id : big) {
            if (isSubstring(pattern, words[id])) {
                print(words[id], Qt::red);
            }
        }
    } else {
        auto it = small.find(pattern[0]);
        if (it == small.end()) return;
        for (std::size_t &id : it->second) {
            if (pattern.size() == 1 ||
                isSubstring(pattern, words[id])) {
                print(words[id], Qt::red);
            } /*else if (isSubseq(pattern, word)) {
                print(word, Qt::blue);
            }*/
        }
    }
}

void Widget::print(const std::string &text, QColor color) {
    listWidget->addItem(text.c_str());
    listWidget->item(listWidget->count() - 1)->setForeground(color);
}

bool Widget::isSubstring(const std::string &pattern, const std::string &word) const {
    if (pattern.size() > word.size()) return false;
    std::string Str = pattern + '$' + word;

    std::size_t n = Str.size();
    std::vector<std::size_t> p(n);
    for (std::size_t i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && Str[i] != Str[j]) {
            j = p[j-1];
        }
        if (Str[i] == Str[j]) ++j;
        p[i] = j;
    }

    for (std::size_t i = pattern.size(); i < n; ++i) {
        if (p[i] == pattern.size()) return true;
    }
    return false;
}

bool Widget::isSubseq(const std::string &pattern, const std::string &word) const {
    std::vector<std::vector<std::size_t>> next(word.size() + 1, std::vector<std::size_t>(256, word.size() + 1));
    for (std::size_t i = word.size() - 1; i != std::size_t(-1); --i) {
        next[i] = next[i + 1];
        next[i][word[i]] = i + 1;
    }

    std::size_t j = 0;
    for (char i : pattern) {
        if (next[j][i] == word.size() + 1) return false;
        j = next[j][i];
    }
    return true;
}
