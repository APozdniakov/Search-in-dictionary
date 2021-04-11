#ifndef WIDGET_H
#define WIDGET_H

#include <algorithm>
#include <cstddef>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QDebug>

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget() = default;

private:
    QLineEdit *lineEdit;
    QListWidget *listWidget;
    std::string pattern;
    std::vector<std::string> words;
    std::unordered_map<char, std::vector<std::size_t>> small;
    std::vector<std::size_t> big;

    bool isSubstring(const std::string &, const std::string &) const;
    bool isSubseq(const std::string &, const std::string &) const;

    void print(const std::string &text, QColor color);

private slots:
    void search();
};
#endif // WIDGET_H
