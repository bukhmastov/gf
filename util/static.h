#ifndef STATIC_H
#define STATIC_H

#include <QString>

class Static {
public:
    static int scoreInitial;
    static int score4quetion;
    static int score4task;
    static QString messageAnswerRight;
    static QString messageAnswerWrong;

private:
    static std::pair<double, double> two2euclide(int);
};

#endif // STATIC_H
