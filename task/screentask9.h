#ifndef SCREENTASK9_H
#define SCREENTASK9_H

#include <QFrame>
#include "util/core.h"
#include "util/screencontroller.h"

namespace Ui {
    class ScreenTask9;
}

class ScreenTask9 : public ScreenController {
    Q_OBJECT

public:
    explicit ScreenTask9(QWidget *parent = 0);
    ~ScreenTask9();
    ScreenController* init(int, bool);
    bool validate(Core*, QString*);

protected:
    void init();

private:
    Ui::ScreenTask9 *ui;
    int normalize(int);
    int a, b, c; // Ax^2 + Bx + C = 0
    QString dk, dn; // канонический и нормальный базис
    QString ftr; // функция следа
    QString z1n, z2n, z1k, z2k; // четыре корня (z1n, z2n, z1k, z2k): в нормальном и каноническом базисах
    QString x1, x2; // два корня исходного уравнения
};

#endif // SCREENTASK9_H
