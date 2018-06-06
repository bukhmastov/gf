#ifndef SCREENTASK12_H
#define SCREENTASK12_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask12;
}

class ScreenTask12 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask12(QWidget *parent = 0);
    ~ScreenTask12();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask12 *ui;
    int normalize(int);
    QString summarize(QString, QString);
    QString subtraction(QString, QString);
    int a, b, c; // Ax^2 + Bx + C = 0
    int bn, cn; // x^2 + Bx + C = 0 - нормированный вид
    int x1, x2; // корни уравнения
};

#endif // SCREENTASK12_H
