#ifndef SCREENTASK2_H
#define SCREENTASK2_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask2;
}

class ScreenTask2 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask2(QWidget *parent = 0);
    ~ScreenTask2();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask2 *ui;
    std::vector<QString> ans1;
    std::vector<QString> ans2;
    std::vector<QString> ans3;
    std::vector<QString> ans4;
};

#endif // SCREENTASK2_H
