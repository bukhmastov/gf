#ifndef SCREENTASK0_H
#define SCREENTASK0_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask0;
}

class ScreenTask0 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask0(QWidget *parent = 0);
    ~ScreenTask0();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask0 *ui;
};

#endif // SCREENTASK0_H
