#ifndef SCREENTASK1_H
#define SCREENTASK1_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"
#include <tuple>

namespace Ui {
    class ScreenTask1;
}

class ScreenTask1 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask1(QWidget *parent = 0);
    ~ScreenTask1();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask1 *ui;
    std::vector<std::tuple<int, int, int>> eq;
};

#endif // SCREENTASK1_H
