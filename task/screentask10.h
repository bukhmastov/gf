#ifndef SCREENTASK10_H
#define SCREENTASK10_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask10;
}

class ScreenTask10 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask10(QWidget *parent = 0);
    ~ScreenTask10();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask10 *ui;
    int normalize(int);
    int a, b, c; // Ax^2 + Bx + C = 0
    QString dk; // канонический базис
    QString z1n, z2n, z1k, z2k; // четыре корня (z1n, z2n, z1k, z2k): в нормальном и каноническом базисах
    QString x1, x2; // два корня исходного уравнения
};

#endif // SCREENTASK10_H
