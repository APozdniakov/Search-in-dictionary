#ifndef VIEW_H
#define VIEW_H

#include "model_fwd.h"
#include "ui_view.h"

namespace jb_rider_test_task {
class View final : public QMainWindow {
    Q_OBJECT
    friend Model;
    Ui::View ui;

public:
    explicit View(Model *model, QWidget *parent = nullptr);
};
}  // namespace jb_rider_test_task

#endif  // VIEW_H
