#include "model.h"
#include <QDateTime>
#include <QDebug>
#include <fstream>

namespace jb_rider_test_task {
Model::Model(const std::string &path, QObject *parent)
    : QStringListModel(parent), view(this), timer() {
    static constexpr std::size_t BOUND = 10;
    std::ifstream ifs(path);
    if (ifs.is_open()) {
        std::string word;
        for (std::size_t index = 0; ifs >> word; ++index) {
            if (word.size() < BOUND) {
                small_words.add(word, index);
            } else {
                big_words.add(word, index);
            }
            words.emplace_back(word.c_str());
        }
    }

    connect(&timer, &QTimer::timeout, this, &Model::run_search);
    connect(this, &Model::result_signal, this, &Model::setStringList);
    timer.start(100);
    view.show();
}

void Model::run_search() {
    QtConcurrent::run(
        [this]() { search(view.ui.line_edit->text().toStdString()); });
}

void Model::search(const std::string &pattern) {
    if (pattern.empty()) {
        emit result_signal({});
        return;
    }
    std::vector<bool> mask(words.size());
    small_words.find(pattern, mask);
    big_words.find(pattern, mask);
    QStringList result;
    result.reserve((int)std::count(mask.begin(), mask.end(), true));
    for (std::size_t i = 0; i < words.size(); ++i) {
        if (mask[i]) {
            result.append(words[i].c_str());
        }
    }
    emit result_signal(result);
}

}  // namespace jb_rider_test_task
