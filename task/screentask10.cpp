#include "screentask10.h"
#include "ui_screentask10.h"

ScreenTask10::ScreenTask10(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask10) {
    ui->setupUi(this);
}

ScreenTask10::~ScreenTask10() {
    delete ui;
}

void ScreenTask10::init() {
    int vk = 5;
    int pi = 285;
    // поле 2^8
    std::vector<QString> tableAlpha;
    std::vector<int> alpha;
    for (int i = 0; i < 255; i++) {
        alpha.push_back(0);
    }
    alpha[0] = 1;
    tableAlpha.push_back("00000001");
    for (int i = 1; i < 255; i++) {
        alpha[i] = alpha[i - 1] * 2;
        if (alpha[i] > 255) {
            alpha[i] = alpha[i] xor pi;
        }
        QString element;
        int w = alpha[i];
        for (int j = 0; j < 8; j++) {
            element.prepend(QString::number(w % 2));
            w /= 2;
        }
        tableAlpha.push_back(element);
    }
    // нормальное поле 2^8
    std::vector<QString> tableGamma;
    std::vector<int> gamma;
    std::vector<int> norm;
    for (int i = 0; i < 255; i++) {
        gamma.push_back(0);
    }
    gamma[0] = 255;
    for (int i = 0; i < 8; i++) {
        norm.push_back(alpha.at(((int) pow(2, i) * vk) % 255));
    }
    tableGamma.push_back("11111111");
    for (int i = 1; i < 255; i++) {
        for (int j1 = 0; j1 < 2; j1++) {
            for (int j2 = 0; j2 < 2; j2++) {
                for (int j3 = 0; j3 < 2; j3++) {
                    for (int j4 = 0; j4 < 2; j4++) {
                        for (int j5 = 0; j5 < 2; j5++) {
                            for (int j6 = 0; j6 < 2; j6++) {
                                for (int j7 = 0; j7 < 2; j7++) {
                                    for (int j8 = 0; j8 < 2; j8++) {
                                        int cc = (norm.at(0) * j8) ^ (norm.at(1) * j7) ^ (norm.at(2) * j6) ^ (norm.at(3) * j5) ^ (norm.at(4) * j4) ^ (norm.at(5) * j3) ^ (norm.at(6) * j2) ^ (norm.at(7) * j1);
                                        if (cc == alpha.at(i)) {
                                            gamma[i] = j1 * 128 + j2 * 64 + j3 * 32 + j4 * 16 + j5 * 8 + j6 * 4 + j7 * 2 + j8;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        QString element;
        int w = gamma[i];
        for (int j = 0; j < 8; j++) {
            element.prepend(QString::number(w % 2));
            w /= 2;
        }
        tableGamma.push_back(element);
    }
    // квадратное уравнение
    while (true) {
        try {
            // Ax^2 + Bx + C = 0
            a = rnd() % 254 + 1;
            b = rnd() % 254 + 1;
            c = rnd() % 254 + 1;
            if (a == b && b == c) {
                continue;
            }
            int aAlpha = normalize(a - 1);
            int bAlpha = normalize(b - 1 - aAlpha);
            int cAlpha = normalize(c - 1 - aAlpha);
            int d = normalize(cAlpha - bAlpha * 2);
            dk = QString::number(normalize(d + 1)); // канонический базис
            QString dGamma = tableGamma.at(normalize(dk.toInt() - 1));
            // функция следа
            int ftr = Static::getTr(dGamma);
            if (ftr != 0) {
                // уравнение решений не имеет
                continue;
            }
            // четыре корня (z1n, z2n, z1k, z2k): в нормальном и каноническом базисах
            int z0 = 0;
            int z1 = (z0 + QString(dGamma.at(6)).toInt()) % 2;
            int z2 = (z1 + QString(dGamma.at(5)).toInt()) % 2;
            int z3 = (z2 + QString(dGamma.at(4)).toInt()) % 2;
            int z4 = (z3 + QString(dGamma.at(3)).toInt()) % 2;
            int z5 = (z4 + QString(dGamma.at(2)).toInt()) % 2;
            int z6 = (z5 + QString(dGamma.at(1)).toInt()) % 2;
            int z7 = (z6 + QString(dGamma.at(0)).toInt()) % 2;
            z1n = QString::number(z7) + QString::number(z6) + QString::number(z5) + QString::number(z4) + QString::number(z3) + QString::number(z2) + QString::number(z1) + QString::number(z0);
            z2n = Static::getXOR("11111111", z1n);
            int z1alpha = Static::getTableIndex(tableGamma, z1n) + 1;
            int z2alpha = Static::getTableIndex(tableGamma, z2n) + 1;
            z1k = tableAlpha.at(normalize(z1alpha - 1));
            z2k = tableAlpha.at(normalize(z2alpha - 1));
            // два корня исходного уравнения
            int x1alpha = normalize(bAlpha + z1alpha);
            int x2alpha = normalize(bAlpha + z2alpha);
            x1 = tableAlpha.at(normalize(x1alpha - 1));
            x2 = tableAlpha.at(normalize(x2alpha - 1));
            // проверка
            bAlpha = normalize(bAlpha + aAlpha);
            cAlpha = normalize(cAlpha + aAlpha);
            for (int i = 0; i < 2; i++) {
                int aCheckAlpha = normalize(aAlpha + ((i == 0 ? x1alpha : x2alpha) - 1) * 2);
                int bCheckAlpha = normalize(bAlpha + ((i == 0 ? x1alpha : x2alpha) - 1));
                int cCheckAlpha = normalize(cAlpha);
                QString aCheck = tableAlpha.at(normalize(aCheckAlpha - 1));
                QString bCheck = tableAlpha.at(normalize(bCheckAlpha - 1));
                QString cCheck = tableAlpha.at(normalize(cCheckAlpha - 1));
                QString check = Static::getXOR(Static::getXOR(Static::getXOR("0000000", aCheck), bCheck), cCheck);
                if (check != "0000000") {
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
    ui->list->addItem("| n     | n → α       | n → γ       |");
    for (unsigned int i = 0; i < tableAlpha.size(); i++) {
        ui->list->addItem("| " + QString::number(i + 1).rightJustified(3, '0') + " | " + tableAlpha.at(i) + " | " + tableGamma.at(i) + " |");
    }
    if (readOnly) {
        ui->inputDK->setText(dk);
        ui->inputZ1K->setText(z1k);
        ui->inputZ2K->setText(z2k);
        ui->inputZ1N->setText(z1n);
        ui->inputZ2N->setText(z2n);
        ui->inputX1->setText(x1);
        ui->inputX2->setText(x2);

        ui->inputDK->setEnabled(false);
        ui->inputZ1K->setEnabled(false);
        ui->inputZ2K->setEnabled(false);
        ui->inputZ1N->setEnabled(false);
        ui->inputZ2N->setEnabled(false);
        ui->inputX1->setEnabled(false);
        ui->inputX2->setEnabled(false);
    }
}

int ScreenTask10::normalize(int x) {
    while (x < 0) {
        x += 255;
    }
    while (x > 255) {
        x -= 255;
    }
    return x;
}

bool ScreenTask10::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->inputDK->text() == dk &&
            ui->inputZ1K->text() == z1k && ui->inputZ2K->text() == z2k &&
            ui->inputZ1N->text() == z1n && ui->inputZ2N->text() == z2n &&
            ui->inputX1->text() == x1 && ui->inputX2->text() == x2
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
