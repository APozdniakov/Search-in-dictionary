#include <QApplication>
#include "model.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    jb_rider_test_task::Model model(argc > 1 ? argv[1] : "words.txt");
    return QApplication::exec();
}
