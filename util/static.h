#ifndef STATIC_H
#define STATIC_H

#include <QString>
#include <tuple>

class Static {
public:
    static int scoreInitial;
    static int score4quetion;
    static int score4task;
    static QString messageAnswerRight;
    static QString messageAnswerWrong;
    //                            pi1(x)   i    j    А1       pi2(x)   k
    static std::vector<std::tuple<QString, int, int, QString, QString, int>> variants;

    static std::tuple<QString, int, int, QString, QString, int> getVariant(QString);
    static QString getVpi1(QString);
    static int getVi(QString);
    static int getVj(QString);
    static QString getVa1(QString);
    static QString getVpi2(QString);
    static int getVk(QString);

    static QString getXOR(QString, QString);
    static QString getReadablePolynom(QString);
    static QString multiplyPolynoms(QString, QString, int);
    static void dividePolynoms(QString, QString, int, QString*, QString*);

};

#endif // STATIC_H
