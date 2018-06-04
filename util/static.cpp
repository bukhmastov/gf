#include "static.h"
#include <QString>
#include <QChar>

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";
std::vector<std::tuple<QString, int, int, QString, QString, int>> Static::variants;

//         pi1(x)   i    j    А1       pi2(x)   k
std::tuple<QString, int, int, QString, QString, int> Static::getVariant(QString v) {
    if (Static::variants.size() < 49) {
        Static::variants.clear();
        Static::variants.push_back(std::make_tuple("1101", 2, 2, "7621535", "122", 3));
        Static::variants.push_back(std::make_tuple("1101", 3, 3, "1423141", "112", 5));
        Static::variants.push_back(std::make_tuple("1101", 4, 4, "6241352", "122", 7));
        Static::variants.push_back(std::make_tuple("1101", 5, 5, "5413513", "112", 3));
        Static::variants.push_back(std::make_tuple("1101", 6, 6, "1763517", "122", 5));
        Static::variants.push_back(std::make_tuple("1101", 2, 4, "3754355", "112", 7));
        Static::variants.push_back(std::make_tuple("1101", 3, 5, "4374354", "122", 3));
        Static::variants.push_back(std::make_tuple("1101", 4, 2, "7157133", "112", 5));
        Static::variants.push_back(std::make_tuple("1101", 5, 6, "1654376", "122", 7));
        Static::variants.push_back(std::make_tuple("1101", 6, 3, "4634216", "112", 3));
        Static::variants.push_back(std::make_tuple("1101", 2, 2, "1414667", "122", 5));
        Static::variants.push_back(std::make_tuple("1101", 3, 6, "7565422", "112", 7));
        Static::variants.push_back(std::make_tuple("1101", 4, 4, "1346217", "122", 3));
        Static::variants.push_back(std::make_tuple("1101", 5, 3, "5562567", "112", 5));
        Static::variants.push_back(std::make_tuple("1101", 6, 5, "7562626", "122", 7));
        Static::variants.push_back(std::make_tuple("1101", 2, 4, "6214354", "112", 3));
        Static::variants.push_back(std::make_tuple("1101", 3, 5, "5623424", "122", 5));
        Static::variants.push_back(std::make_tuple("1101", 4, 2, "2346626", "112", 7));
        Static::variants.push_back(std::make_tuple("1101", 5, 6, "2626547", "122", 3));
        Static::variants.push_back(std::make_tuple("1101", 6, 3, "5743644", "112", 5));
        Static::variants.push_back(std::make_tuple("1101", 2, 2, "1435462", "122", 7));
        Static::variants.push_back(std::make_tuple("1101", 3, 6, "6434452", "112", 3));
        Static::variants.push_back(std::make_tuple("1101", 4, 4, "6434243", "122", 5));
        Static::variants.push_back(std::make_tuple("1101", 5, 3, "1435432", "112", 7));
        Static::variants.push_back(std::make_tuple("1101", 6, 5, "6347623", "122", 3));
        Static::variants.push_back(std::make_tuple("1011", 2, 3, "1465627", "112", 5));
        Static::variants.push_back(std::make_tuple("1011", 3, 2, "2154466", "122", 7));
        Static::variants.push_back(std::make_tuple("1011", 4, 5, "1345467", "112", 3));
        Static::variants.push_back(std::make_tuple("1011", 5, 1, "5654322", "122", 5));
        Static::variants.push_back(std::make_tuple("1011", 6, 2, "7647112", "112", 7));
        Static::variants.push_back(std::make_tuple("1011", 2, 6, "1435666", "122", 3));
        Static::variants.push_back(std::make_tuple("1011", 3, 4, "1454676", "112", 5));
        Static::variants.push_back(std::make_tuple("1011", 4, 5, "5623556", "122", 7));
        Static::variants.push_back(std::make_tuple("1011", 5, 2, "6432622", "112", 3));
        Static::variants.push_back(std::make_tuple("1011", 6, 4, "1345466", "122", 5));
        Static::variants.push_back(std::make_tuple("1011", 2, 6, "2456167", "112", 7));
        Static::variants.push_back(std::make_tuple("1011", 3, 2, "2315676", "122", 3));
        Static::variants.push_back(std::make_tuple("1011", 4, 3, "2134566", "112", 5));
        Static::variants.push_back(std::make_tuple("1011", 5, 2, "2354644", "122", 7));
        Static::variants.push_back(std::make_tuple("1011", 6, 2, "6453224", "112", 3));
        Static::variants.push_back(std::make_tuple("1011", 2, 6, "7724324", "122", 5));
        Static::variants.push_back(std::make_tuple("1011", 3, 4, "1345462", "112", 7));
        Static::variants.push_back(std::make_tuple("1011", 4, 3, "7455421", "122", 3));
        Static::variants.push_back(std::make_tuple("1011", 5, 2, "1466476", "112", 5));
        Static::variants.push_back(std::make_tuple("1011", 6, 4, "2676372", "122", 7));
        Static::variants.push_back(std::make_tuple("1011", 2, 5, "4573112", "112", 3));
        Static::variants.push_back(std::make_tuple("1011", 3, 2, "2467122", "122", 5));
        Static::variants.push_back(std::make_tuple("1011", 4, 3, "1164562", "112", 7));
        Static::variants.push_back(std::make_tuple("1011", 5, 1, "1657743", "122", 3));
        Static::variants.push_back(std::make_tuple("1011", 6, 2, "7434267", "112", 5));
    }
    return Static::variants.at(v.toInt());
}

QString Static::getVpi1(QString n) {
    return std::get<0>(Static::getVariant(n));
}

int Static::getVi(QString n) {
    return std::get<1>(Static::getVariant(n));
}

int Static::getVj(QString n) {
    return std::get<2>(Static::getVariant(n));
}

QString Static::getVa1(QString n) {
    return std::get<3>(Static::getVariant(n));
}

QString Static::getVpi2(QString n) {
    return std::get<4>(Static::getVariant(n));
}

int Static::getVk(QString n) {
    return std::get<5>(Static::getVariant(n));
}

QString Static::getXOR(QString p1, QString p2) {
    QString p12;
    for (int i = 0; i < p1.size(); i++) {
        p12.append(p1.at(i) == p2.at(i) ? "0" : "1");
    }
    return p12;
}

QString Static::getReadablePolynom(QString poly) {
    QString readable = "";
    int size = poly.size();
    for (int i = 0; i < size; i++) {
        if (poly.at(i) == QChar('1')) {
            if (!readable.isEmpty()) {
                readable += "+";
            }
            if (i == 0) {
                readable += "1";
            }
            if (i == 1) {
                readable += "x";
            }
            if (i > 1) {
                readable += "x<sup>" + QString::number(i) + "</sup>";
            }
        }
    }
    return readable;
}

QString Static::multiplyPolynoms(QString p1, QString p2, int n) {
    QString p12;
    std::vector<int> p12v;
    for (int i = 0; i < p1.size() + p2.size() - 1; i++) {
        p12v.push_back(0);
    }
    for (int i = 0; i < p1.size(); i++) {
        for (int j = 0; j < p2.size(); j++) {
            p12v.at(i + j) += QString(p1.at(i)).toInt() * QString(p2.at(j)).toInt();
        }
    }
    for (unsigned int i = 0; i < p12v.size(); i++) {
        p12.append(QString::number(p12v.at(i) % n));
    }
    return p12;
}

void Static::dividePolynoms(QString p1, QString p2, int n, QString *result, QString *residue) {
    std::vector<int> p1v;
    std::vector<int> p2v;
    std::vector<int> p12v;
    for (int i = 0; i < p1.size(); i++) {
        p1v.push_back(QString(p1.at(i)).toInt());
    }
    for (int i = 0; i < p2.size(); i++) {
        p2v.push_back(QString(p2.at(i)).toInt());
    }
    while (p1v.size() >= p2v.size()) {
        std::vector<int> p1vt;
        std::vector<int> p2vt;
        for (unsigned int i = 0; i < p2v.size(); i++) {
            p2vt.push_back(p2v.at(i));
        }
        unsigned int p12vs = p1v.size() - p2vt.size();
        for (unsigned int i = 0; i < p12vs; i++) {
            p2vt.insert(p2vt.begin(), 0);
        }
        unsigned int size = p1v.size();
        int p1t = p1v.at(size - 1);
        int p2t = p2vt.at(size - 1);
        int multiply = p1t / p2t;
        for (unsigned int i = 0; i < size; i++) {
            p2vt[i] = p2vt[i] * multiply;
        }
        for (unsigned int i = 0; i < size; i++) {
            p1vt.push_back(p1v.at(i) - p2vt.at(i));
        }
        p1v.clear();
        bool write = false;
        for (int i = size - 1; i >= 0; i--) {
            if (!write && p1vt.at(i) == 0) {
                continue;
            }
            write = true;
            p1v.insert(p1v.begin(), p1vt.at(i));
        }
        p12v.push_back(multiply);
    }
    for (int i = p12v.size() - 1; i >= 0; i--) {
        result->push_back(QString::number(abs(p12v.at(i) % n)));
    }
    for (int i = p1v.size() - 1; i >= 0; i--) {
        residue->push_back(QString::number(abs(p1v.at(i) % n)));
    }
}



























