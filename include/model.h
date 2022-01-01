#ifndef MODEL_H
#define MODEL_H

#include <QString>
#include <QStringList>
#include <QStringListModel>
#include <QTimer>
#include <QtConcurrent>
#include <set>
#include <string>
#include <vector>
#include "big_words.h"
#include "trie.h"
#include "view.h"

namespace jb_rider_test_task {
class Model final : public QStringListModel {
    Q_OBJECT
    View view;
    Trie small_words;
    BigWords big_words;
    std::vector<std::string> words;
    QTimer timer;
    void search(const std::string &);
    Q_SLOT void run_search();
    Q_SIGNAL void result_signal(const QStringList &);

public:
    explicit Model(const std::string &, QObject * = nullptr);
};
}  // namespace jb_rider_test_task

#endif  // MODEL_H
