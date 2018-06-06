#ifndef SCREENTASK11_H
#define SCREENTASK11_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask11;
}

class ScreenTask11 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask11(QWidget *parent = 0);
    ~ScreenTask11();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask11 *ui;
    std::vector<QString> tableAlpha;
};

#endif // SCREENTASK11_H
