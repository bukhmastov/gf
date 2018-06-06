#include "screentask12.h"
#include "ui_screentask12.h"

ScreenTask12::ScreenTask12(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask12) {
    ui->setupUi(this);
}

ScreenTask12::~ScreenTask12() {
    delete ui;
}

void ScreenTask12::init() {
    QString pi = Static::getVpi2(ScreenController::store["variant"]);
    int vk = Static::getVk(ScreenController::store["variant"]);
    std::vector<QString> tableAlpha;
    std::vector<QString> tableBeta;
    // alpha
    int rq1 = 1;
    int rq2 = 0;
    int rq3 = pi == "221" ? 2 : 1;
    int rq4 = 2;
    int rq5;
    tableAlpha.push_back("01");
    tableAlpha.push_back("10");
    for (int i = 2; i < 8; i++) {
        rq5 = rq1;
        rq1 = rq2;
        rq2 = 0;
        if (rq5 == 1) {
            rq2 = (rq2 + (3 - rq4)) % 3;
            rq1 = (rq1 + (3 - rq3)) % 3;
        }
        if (rq5 == 2) {
            rq2 = (rq2 + rq4) % 3;
            rq1 = (rq1 + rq3) % 3;
        }
        tableAlpha.push_back(QString::number(rq1) + QString::number(rq2));
    }
    // beta
    for (int i = 0; i < 8; i++) {
        int al = (i * vk) % 8;
        tableBeta.push_back(tableAlpha.at(al));
    }
    // equation
    while (true) {
        try {
            // Ax^2 + Bx + C = 0
            a = rnd() % 8 + 1;
            b = rnd() % 8 + 1;
            c = rnd() % 8 + 1;
            if (a == b && b == c) {
                continue;
            }
            int aBeta = normalize(a - 1);
            int bBeta = normalize(b - 1 - aBeta);
            int cBeta = normalize(c - 1 - aBeta);
            // part A
            bn = normalize(bBeta + 1);
            cn = normalize(cBeta + 1);
            // part B
            int h = Static::getTableIndex(tableBeta, subtraction(tableBeta.at(normalize(bBeta * 2)), tableBeta.at(cBeta))) / 2;
            x1 = Static::getTableIndex(tableBeta, subtraction(tableBeta.at(bBeta), tableBeta.at(h))) + 1;
            x2 = Static::getTableIndex(tableBeta, summarize(tableBeta.at(bBeta), tableBeta.at(h))) + 1;
            // проверка
            bBeta = normalize(bBeta + aBeta);
            cBeta = normalize(cBeta + aBeta);
            for (int i = 0; i < 2; i++) {
                int aCheckBeta = (aBeta + ((i == 0 ? x1 : x2) - 1) * 2) % 8;
                int bCheckBeta = (bBeta + ((i == 0 ? x1 : x2) - 1)) % 8;
                int cCheckBeta = (cBeta) % 8;
                QString aCheck = tableBeta.at(normalize(aCheckBeta));
                QString bCheck = tableBeta.at(normalize(bCheckBeta));
                QString cCheck = tableBeta.at(normalize(cCheckBeta));
                QString check = summarize(summarize(summarize("00", aCheck), bCheck), cCheck);
                if (check != "00") {
                    // проверка не пройдена
                    goto failed;
                }
            }
        } catch (...) {
            goto failed;
        }
        // уравнение решено
        break;
        failed:;
    }
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%p%", Static::getReadablePolynom(pi));
    title = title.replace("%k%", QString::number(vk));
    ui->title->setText(title);
    QString titleA = ui->titleA->text();
    titleA = titleA.replace("%a%", QString::number(a));
    titleA = titleA.replace("%b%", QString::number(b));
    titleA = titleA.replace("%c%", QString::number(c));
    ui->titleA->setText(titleA);
    if (readOnly) {
        ui->inputBN->setText(QString::number(bn));
        ui->inputCN->setText(QString::number(cn));
        ui->inputX1->setText(QString::number(x1));
        ui->inputX2->setText(QString::number(x2));

        ui->inputBN->setReadOnly(true);
        ui->inputCN->setReadOnly(true);
        ui->inputX1->setReadOnly(true);
        ui->inputX2->setReadOnly(true);
    }
}

int ScreenTask12::normalize(int x) {
    while (x < 0) {
        x += 8;
    }
    while (x > 8) {
        x -= 8;
    }
    return x;
}

QString ScreenTask12::summarize(QString a, QString b) {
    int a1 = a.at(0).digitValue();
    int a2 = a.at(1).digitValue();
    int b1 = b.at(0).digitValue();
    int b2 = b.at(1).digitValue();
    int ab1 = (a1 + b1) % 3;
    int ab2 = (a2 + b2) % 3;
    return QString::number(ab1) + QString::number(ab2);
}

QString ScreenTask12::subtraction(QString a, QString b) {
    int a1 = a.at(0).digitValue();
    int a2 = a.at(1).digitValue();
    int b1 = b.at(0).digitValue();
    int b2 = b.at(1).digitValue();
    int ab1 = a1 - b1;
    int ab2 = a2 - b2;
    if (ab1 < 0) {
        ab1 += 3;
    }
    if (ab2 < 0) {
        ab2 += 3;
    }
    return QString::number(ab1) + QString::number(ab2);
}

bool ScreenTask12::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    // part A
    if (ui->inputBN->text() == QString::number(bn) && ui->inputCN->text() == QString::number(cn)) {
        message->append("А) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("А) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("<br>");
    // part B
    int valid = 0;
    for (int i = 0; i < 2; i++) {
        if (ui->inputX1->text() == QString::number(i == 0 ? x1 : x2)) {
            valid++;
        } else if (ui->inputX2->text() == QString::number(i == 0 ? x1 : x2)) {
            valid++;
        }
    }
    if (valid == 2) {
        message->append("Б) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("Б) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
