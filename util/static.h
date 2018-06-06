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
    //                            pi1(x)   i    j    А        B        pi2(x)   k
    static std::vector<std::tuple<QString, int, int, QString, QString, QString, int>> variants;

    static std::tuple<QString, int, int, QString, QString, QString, int> getVariant(QString);
    static QString getVpi1(QString);
    static int getVi(QString);
    static int getVj(QString);
    static QString getVa(QString);
    static QString getVb(QString);
    static QString getVpi2(QString);
    static int getVk(QString);

    static std::vector<QString> getBetaTable(QString);
    static std::vector<QString> getGammaTable(QString);
    static int getTableIndex(std::vector<QString>, QString);
    static int getGammaFromBeta(QString, int);
    static int getTr(QString);
    static std::vector<std::vector<QString>> getFMSmatrix();
    static std::vector<std::vector<QString>> getFMSRmatrix();

    static QString getXOR(QString, QString);
    static QString getReadablePolynom(QString);
    static QString multiplyPolynoms(QString, QString, int);
    static void dividePolynoms(QString, QString, int, QString*, QString*);
    static int summarize(std::vector<QString>, int, int);

};

#endif // STATIC_H
