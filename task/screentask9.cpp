#include "screentask9.h"
#include "ui_screentask9.h"

ScreenTask9::ScreenTask9(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask9) {
    ui->setupUi(this);
}

ScreenTask9::~ScreenTask9() {
    delete ui;
}

void ScreenTask9::init() {
    QString v = ScreenController::store["variant"];
    std::vector<QString> tableBeta = Static::getBetaTable(v);
    std::vector<QString> tableGamma = Static::getGammaTable(v);
    int vj = Static::getVj(v);
    while (true) {
        try {
            // part A
            // Ax^2 + Bx + C = 0
            a = rnd() % 7 + 1;
            b = rnd() % 7 + 1;
            c = rnd() % 7 + 1;
            if (a == b && b == c) {
                continue;
            }
            int aBeta = normalize(a - 1);
            int bBeta = normalize(b - 1 - aBeta);
            int cBeta = normalize(c - 1 - aBeta);
            int d = normalize(cBeta - bBeta * 2);
            int y = Static::getGammaFromBeta(v, d);
            dk = tableBeta.at(normalize(d + 1));  // канонический базис
            dn = tableGamma.at(normalize(y + 1)); // нормальный базис
            // part B
            // функция следа
            ftr = QString::number(Static::getTr(dn));
            if (ftr != "0") {
                // уравнение решений не имеет
                continue;
            }
            // четыре корня (z1n, z2n, z1k, z2k): в нормальном и каноническом базисах
            int z0 = 0;
            int z1 = (z0 + QString(dn.at(1)).toInt()) % 2;
            int z2 = (z1 + QString(dn.at(0)).toInt()) % 2;
            z1n = QString::number(z2) + QString::number(z1) + QString::number(z0);
            z2n = Static::getXOR("111", z1n);
            int z1beta = ((Static::getTableIndex(tableGamma, z1n) - 1) * vj) % 7;
            int z2beta = ((Static::getTableIndex(tableGamma, z2n) - 1) * vj) % 7;
            z1k = tableBeta.at(normalize(z1beta + 1));
            z2k = tableBeta.at(normalize(z2beta + 1));
            // part C
            // два корня исходного уравнения
            int x1beta = (bBeta + z1beta) % 7;
            int x2beta = (bBeta + z2beta) % 7;
            x1 = tableBeta.at(normalize(x1beta + 1));
            x2 = tableBeta.at(normalize(x2beta + 1));
            // проверка
            bBeta = normalize(bBeta + aBeta);
            cBeta = normalize(cBeta + aBeta);
            for (int i = 0; i < 2; i++) {
                int aCheckBeta = (aBeta + (i == 0 ? x1beta : x2beta) * 2) % 7;
                int bCheckBeta = (bBeta + (i == 0 ? x1beta : x2beta)) % 7;
                int cCheckBeta = (cBeta) % 7;
                QString aCheck = tableBeta.at(normalize(aCheckBeta + 1));
                QString bCheck = tableBeta.at(normalize(bCheckBeta + 1));
                QString cCheck = tableBeta.at(normalize(cCheckBeta + 1));
                QString check = Static::getXOR(Static::getXOR(Static::getXOR("000", aCheck), bCheck), cCheck);
                if (check != "000") {
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
    title = title.replace("%a%", QString::number(a));
    title = title.replace("%b%", QString::number(b));
    title = title.replace("%c%", QString::number(c));
    ui->title->setText(title);
    if (readOnly) {
        ui->inputDK->setText(dk);
        ui->inputDN->setText(dn);
        ui->inputTR->setText(ftr);
        ui->inputZ1K->setText(z1k);
        ui->inputZ2K->setText(z2k);
        ui->inputZ1N->setText(z1n);
        ui->inputZ2N->setText(z2n);
        ui->inputX1->setText(x1);
        ui->inputX2->setText(x2);

        ui->inputDK->setReadOnly(true);
        ui->inputDN->setReadOnly(true);
        ui->inputTR->setReadOnly(true);
        ui->inputZ1K->setReadOnly(true);
        ui->inputZ2K->setReadOnly(true);
        ui->inputZ1N->setReadOnly(true);
        ui->inputZ2N->setReadOnly(true);
        ui->inputX1->setReadOnly(true);
        ui->inputX2->setReadOnly(true);
    }
}

int ScreenTask9::normalize(int x) {
    while (x < 0) {
        x += 7;
    }
    while (x > 7) {
        x -= 7;
    }
    return x;
}

bool ScreenTask9::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    // part A
    if (ui->inputDK->text() == dk && ui->inputDN->text() == dn) {
        message->append("А) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("А) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("<br>");
    // part B
    if (
            ui->inputTR->text() == ftr &&
            ui->inputZ1K->text() == z1k && ui->inputZ2K->text() == z2k &&
            ui->inputZ1N->text() == z1n && ui->inputZ2N->text() == z2n
    ) {
        message->append("Б) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("Б) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    message->append("<br>");
    // part C
    if (ui->inputX1->text() == x1 && ui->inputX2->text() == x2) {
        message->append("В) " + Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append("В) " + Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
