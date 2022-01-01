#include "view.h"
#include "model.h"

namespace jb_rider_test_task {
View::View(Model *model, QWidget *parent) : QMainWindow(parent), ui() {
    ui.setupUi(this);
    ui.list_view->setModel(model);
}
}  // namespace jb_rider_test_task
