#include "static.h"
#include <QString>
#include <QLayout>
#include <QWidget>
#include <QChar>

QString Static::worktype = "Лабораторная работа"; // "Лабораторная работа" "Практическое занятие"
QString Static::worktypeShort = "ЛР"; // "ЛР" "ПЗ"
bool Static::allowSelectVariant = true; // true false

int Static::scoreInitial = 50;
int Static::score4quetion = 2;
int Static::score4task = 1;
QString Static::messageAnswerRight = "Ответ верный (+2 балла)";
QString Static::messageAnswerWrong = "Ответ неверный (-2 балла)";
//                     pi1(x)   i    j    А        B        pi2(x)   k
std::vector<std::tuple<QString, int, int, QString, QString, QString, int>> Static::variants;

std::tuple<QString, int, int, QString, QString, QString, int> Static::getVariant(QString v) {
    if (Static::variants.size() < 50) {
        Static::variants.clear();
        Static::variants.push_back(std::make_tuple("1011", 2, 2, "7621535", "6423123", "221", 3));
        Static::variants.push_back(std::make_tuple("1011", 3, 3, "1423141", "4126346", "211", 5));
        Static::variants.push_back(std::make_tuple("1011", 4, 4, "6241352", "6154365", "221", 7));
        Static::variants.push_back(std::make_tuple("1011", 5, 5, "5413513", "7234143", "211", 3));
        Static::variants.push_back(std::make_tuple("1011", 6, 6, "1763517", "1234345", "221", 5));
        Static::variants.push_back(std::make_tuple("1011", 2, 4, "3754355", "4561745", "211", 7));
        Static::variants.push_back(std::make_tuple("1011", 3, 5, "4374354", "5643745", "221", 3));
        Static::variants.push_back(std::make_tuple("1011", 4, 2, "7157133", "1346461", "211", 5));
        Static::variants.push_back(std::make_tuple("1011", 5, 6, "1654376", "1346143", "221", 7));
        Static::variants.push_back(std::make_tuple("1011", 6, 3, "4634216", "3516467", "211", 3));
        Static::variants.push_back(std::make_tuple("1011", 2, 2, "1414667", "5236161", "221", 5));
        Static::variants.push_back(std::make_tuple("1011", 3, 6, "7565422", "5742456", "211", 7));
        Static::variants.push_back(std::make_tuple("1011", 4, 4, "1346217", "5765422", "221", 3));
        Static::variants.push_back(std::make_tuple("1011", 5, 3, "5562567", "2346267", "211", 5));
        Static::variants.push_back(std::make_tuple("1011", 6, 5, "7562626", "6535413", "221", 7));
        Static::variants.push_back(std::make_tuple("1011", 2, 4, "6214354", "3255623", "211", 3));
        Static::variants.push_back(std::make_tuple("1011", 3, 5, "5623424", "7674443", "221", 5));
        Static::variants.push_back(std::make_tuple("1011", 4, 2, "2346626", "7463265", "211", 7));
        Static::variants.push_back(std::make_tuple("1011", 5, 6, "2626547", "2136653", "221", 3));
        Static::variants.push_back(std::make_tuple("1011", 6, 3, "5743644", "7624221", "211", 5));
        Static::variants.push_back(std::make_tuple("1011", 2, 2, "1435462", "3262163", "221", 7));
        Static::variants.push_back(std::make_tuple("1011", 3, 6, "6434452", "7634545", "211", 3));
        Static::variants.push_back(std::make_tuple("1011", 4, 4, "6434243", "1345466", "221", 5));
        Static::variants.push_back(std::make_tuple("1011", 5, 3, "1435432", "6323421", "211", 7));
        Static::variants.push_back(std::make_tuple("1011", 6, 5, "6347623", "4564632", "221", 3));
        Static::variants.push_back(std::make_tuple("1101", 2, 3, "1465627", "6624451", "211", 5));
        Static::variants.push_back(std::make_tuple("1101", 3, 2, "2154466", "3456462", "221", 7));
        Static::variants.push_back(std::make_tuple("1101", 4, 5, "1345467", "7462342", "211", 3));
        Static::variants.push_back(std::make_tuple("1101", 5, 1, "5654322", "6756341", "221", 5));
        Static::variants.push_back(std::make_tuple("1101", 6, 2, "7647211", "5324633", "211", 7));
        Static::variants.push_back(std::make_tuple("1101", 2, 6, "1435666", "2435462", "221", 3));
        Static::variants.push_back(std::make_tuple("1101", 3, 4, "1454676", "6231454", "211", 5));
        Static::variants.push_back(std::make_tuple("1101", 4, 5, "5623556", "1345422", "221", 7));
        Static::variants.push_back(std::make_tuple("1101", 5, 2, "6432622", "2346747", "211", 3));
        Static::variants.push_back(std::make_tuple("1101", 6, 4, "1345466", "6344544", "221", 5));
        Static::variants.push_back(std::make_tuple("1101", 2, 6, "2456167", "7342423", "211", 7));
        Static::variants.push_back(std::make_tuple("1101", 3, 2, "2315676", "2345455", "221", 3));
        Static::variants.push_back(std::make_tuple("1101", 4, 3, "2134566", "7624344", "211", 5));
        Static::variants.push_back(std::make_tuple("1101", 5, 2, "2354644", "3311366", "221", 7));
        Static::variants.push_back(std::make_tuple("1101", 6, 2, "6453224", "6443116", "211", 3));
        Static::variants.push_back(std::make_tuple("1101", 2, 6, "7724324", "7274445", "221", 5));
        Static::variants.push_back(std::make_tuple("1101", 3, 4, "1345462", "7454367", "211", 7));
        Static::variants.push_back(std::make_tuple("1101", 4, 3, "7455421", "4264211", "221", 3));
        Static::variants.push_back(std::make_tuple("1101", 5, 2, "1466476", "7433452", "211", 5));
        Static::variants.push_back(std::make_tuple("1101", 6, 4, "2676372", "2226567", "221", 7));
        Static::variants.push_back(std::make_tuple("1101", 2, 5, "4573211", "7343256", "211", 3));
        Static::variants.push_back(std::make_tuple("1101", 3, 2, "2467221", "1464222", "221", 5));
        Static::variants.push_back(std::make_tuple("1101", 4, 3, "1164562", "3425676", "211", 7));
        Static::variants.push_back(std::make_tuple("1101", 5, 1, "1657743", "2457627", "221", 3));
        Static::variants.push_back(std::make_tuple("1101", 6, 2, "7434267", "7456111", "211", 5));
    }
    return Static::variants.at(v.toInt());
}

QString Static::getVpi1(QString v) {
    return std::get<0>(Static::getVariant(v));
}

int Static::getVi(QString v) {
    return std::get<1>(Static::getVariant(v));
}

int Static::getVj(QString v) {
    return std::get<2>(Static::getVariant(v));
}

QString Static::getVa(QString v) {
    return std::get<3>(Static::getVariant(v));
}

QString Static::getVb(QString v) {
    return std::get<4>(Static::getVariant(v));
}

QString Static::getVpi2(QString v) {
    return std::get<5>(Static::getVariant(v));
}

int Static::getVk(QString v) {
    return std::get<6>(Static::getVariant(v));
}

void Static::clearLayout(QLayout* layout) {
    QLayoutItem *wItem;
    while ((wItem = layout->takeAt(0)) != 0) {
        if (wItem->widget()) wItem->widget()->setParent(NULL);
        delete wItem;
    }
}

std::vector<QString> Static::getBetaTable(QString v) {
    std::vector<QString> table;
    int vi = Static::getVi(v);
    QString h = Static::getVpi1(v);
    if (h == "1101") {
        switch (vi) {
        case 2:
            table.push_back("000");
            table.push_back("001");
            table.push_back("100");
            table.push_back("110");
            table.push_back("101");
            table.push_back("010");
            table.push_back("011");
            table.push_back("111");
            break;
        case 3:
            table.push_back("000");
            table.push_back("001");
            table.push_back("011");
            table.push_back("101");
            table.push_back("100");
            table.push_back("111");
            table.push_back("010");
            table.push_back("110");
            break;
        case 4:
            table.push_back("000");
            table.push_back("001");
            table.push_back("110");
            table.push_back("010");
            table.push_back("111");
            table.push_back("100");
            table.push_back("101");
            table.push_back("011");
            break;
        case 5:
            table.push_back("000");
            table.push_back("001");
            table.push_back("111");
            table.push_back("011");
            table.push_back("010");
            table.push_back("101");
            table.push_back("110");
            table.push_back("100");
            break;
        case 6:
            table.push_back("000");
            table.push_back("001");
            table.push_back("101");
            table.push_back("111");
            table.push_back("110");
            table.push_back("011");
            table.push_back("100");
            table.push_back("010");
            break;
        }
    } else {
        switch (vi) {
        case 2:
            table.push_back("000");
            table.push_back("001");
            table.push_back("100");
            table.push_back("111");
            table.push_back("110");
            table.push_back("010");
            table.push_back("101");
            table.push_back("011");
            break;
        case 3:
            table.push_back("000");
            table.push_back("001");
            table.push_back("101");
            table.push_back("110");
            table.push_back("100");
            table.push_back("011");
            table.push_back("010");
            table.push_back("111");
            break;
        case 4:
            table.push_back("000");
            table.push_back("001");
            table.push_back("111");
            table.push_back("010");
            table.push_back("011");
            table.push_back("100");
            table.push_back("110");
            table.push_back("101");
            break;
        case 5:
            table.push_back("000");
            table.push_back("001");
            table.push_back("011");
            table.push_back("101");
            table.push_back("010");
            table.push_back("110");
            table.push_back("111");
            table.push_back("100");
            break;
        case 6:
            table.push_back("000");
            table.push_back("001");
            table.push_back("110");
            table.push_back("011");
            table.push_back("111");
            table.push_back("101");
            table.push_back("100");
            table.push_back("010");
            break;
        }
    }
    return table;
}

std::vector<QString> Static::getGammaTable(QString) {
    std::vector<QString> tableGamma;
    tableGamma.push_back("000");
    tableGamma.push_back("111");
    tableGamma.push_back("001");
    tableGamma.push_back("010");
    tableGamma.push_back("101");
    tableGamma.push_back("100");
    tableGamma.push_back("110");
    tableGamma.push_back("011");
    return tableGamma;
    /*int vj = Static::getVj(v);
    std::vector<QString> tableBeta = Static::getBetaTable(v);
    std::vector<QString> tableGamma;
    int b1 = vj;           // для y1
    int b2 = (vj * 2) % 7; // для y2
    int b4 = (vj * 4) % 7; // для y4
    for (unsigned int i = 0; i < 8; i++) {
        tableGamma.push_back("000");
    }
    for (unsigned int i = 1; i < 8; i++) {
        int y1 = (i / 1) % 2;
        int y2 = (i / 2) % 2;
        int y4 = (i / 4) % 2;
        QString betaXor = "000";
        if (y1 == 1) {
            betaXor = Static::getXOR(betaXor, tableBeta.at(b1 + 1));
        }
        if (y2 == 1) {
            betaXor = Static::getXOR(betaXor, tableBeta.at(b2 + 1));
        }
        if (y4 == 1) {
            betaXor = Static::getXOR(betaXor, tableBeta.at(b4 + 1));
        }
        int b = 0;
        for (unsigned int j = 0; j < tableBeta.size(); j++) {
            if (tableBeta.at(j) == betaXor) {
                b = j - 1;
                break;
            }
        }
        int y = Static::getGammaFromBeta(v, b);
        tableGamma[y + 1] = QString::number(y4) + QString::number(y2) + QString::number(y1);
    }
    return tableGamma;*/
}

int Static::getTableIndex(std::vector<QString> table, QString element) {
    for (unsigned int i = 0; i < table.size(); i++) {
        if (table.at(i) == element) {
            return i;
        }
    }
    throw std::runtime_error("Shit happened");
}

int Static::getGammaFromBeta(QString v, int b) {
    int vj = Static::getVj(v);
    for (int i = 0; i < 7; i++) {
        if ((i * vj) % 7 == b) {
            return i;
        }
    }
    throw std::runtime_error("Shit happened");
}

int Static::getTr(QString p) {
    int tr = QString(p.at(0)).toInt();
    for (int i = 1; i < p.size(); i++) {
        tr ^= QString(p.at(i)).toInt();
    }
    return tr;
}

std::vector<std::vector<QString>> Static::getFMSmatrix() {
    std::vector<std::vector<QString>> matrix;
    matrix.push_back(std::vector<QString>{"1", "1", "1", "1", "1", "1", "1"});
    matrix.push_back(std::vector<QString>{"1", "2", "3", "4", "5", "6", "7"});
    matrix.push_back(std::vector<QString>{"1", "3", "5", "7", "2", "4", "6"});
    matrix.push_back(std::vector<QString>{"1", "4", "7", "3", "6", "2", "5"});
    matrix.push_back(std::vector<QString>{"1", "5", "2", "6", "3", "7", "4"});
    matrix.push_back(std::vector<QString>{"1", "6", "4", "2", "7", "5", "3"});
    matrix.push_back(std::vector<QString>{"1", "7", "6", "5", "4", "3", "2"});
    return matrix;
}

std::vector<std::vector<QString>> Static::getFMSRmatrix() {
    std::vector<std::vector<QString>> matrix;
    matrix.push_back(std::vector<QString>{"1", "1", "1", "1", "1", "1", "1"});
    matrix.push_back(std::vector<QString>{"1", "7", "6", "5", "4", "3", "2"});
    matrix.push_back(std::vector<QString>{"1", "6", "4", "2", "7", "5", "3"});
    matrix.push_back(std::vector<QString>{"1", "5", "2", "6", "3", "7", "4"});
    matrix.push_back(std::vector<QString>{"1", "4", "7", "3", "6", "2", "5"});
    matrix.push_back(std::vector<QString>{"1", "3", "5", "7", "2", "4", "6"});
    matrix.push_back(std::vector<QString>{"1", "2", "3", "4", "5", "6", "7"});
    return matrix;
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
        if (poly.at(i) != QChar('0')) {
            if (!readable.isEmpty()) {
                readable += "+";
            }
            if (i == 0) {
                readable += poly.at(i);
            } else if (poly.at(i) != QChar('1')) {
                readable += poly.at(i);
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

int Static::summarize(std::vector<QString> table, int a, int b) {
    QString ay = table.at(a);
    QString by = table.at(b);
    QString aby = Static::getXOR(ay, by);
    for (unsigned int i = 0; i < table.size(); i++) {
        if (table.at(i) == aby) {
            return i;
        }
    }
    throw std::runtime_error("Shit happened");
}


























