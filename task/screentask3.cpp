#include "screentask3.h"
#include "ui_screentask3.h"
#include <bitset>

ScreenTask3::ScreenTask3(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask3) {
    ui->setupUi(this);
}

ScreenTask3::~ScreenTask3() {
    delete ui;
}

void ScreenTask3::init() {
    QString vpi1 = Static::getVpi1(ScreenController::store["variant"]);
    std::vector<QString> table = Static::getGammaTable(ScreenController::store["variant"]);
    int index = 0;
    while (eq.size() < 8) {
        int a = rnd() % 7 + 1;
        int b = rnd() % 7 + 1;
        if (a == 1 || b == 1 || a == b) {
            continue;
        }
        bool isValid = true;
        for (unsigned int i = 0; i < eq.size(); i++) {
            int first = std::get<0>(eq.at(i));
            int second = std::get<0>(eq.at(i));
            if ((a == first && b == second) || (a == second && b == first)) {
                isValid = false;
                break;
            }
        }
        if (!isValid) {
            continue;
        }
        int ab;
        QString ay = table.at(a);
        QString by = table.at(b);
        if (index < 4) {
            QString aby = Static::getXOR(ay, by);
            for (unsigned int i = 0; i < table.size(); i++) {
                if (table.at(i) == aby) {
                    ab = i;
                }
            }
        } else {
            int abi;
            if (index < 6) {
                abi = (a + b - 2) % 7;
            } else {
                abi = ((a - 1) - (b - 1)) % 7;
                if (b - a == 1) {
                    abi = 6;
                }
            }
            ab = abi + 1;
            while (ab < 0) {
                ab += 7;
            }
        }
        eq.push_back(std::make_tuple(a, b, ab));
        index++;
    }
    eq.at(0);
    // setup ui
    ui->title->setText(ui->title->text().replace("%h%", Static::getReadablePolynom(vpi1)));
    ui->label1->setText(QString::number(std::get<0>(eq.at(0))) + "+" + QString::number(std::get<1>(eq.at(0))) + "=");
    ui->label2->setText(QString::number(std::get<0>(eq.at(1))) + "+" + QString::number(std::get<1>(eq.at(1))) + "=");
    ui->label3->setText(QString::number(std::get<0>(eq.at(2))) + "-" + QString::number(std::get<1>(eq.at(2))) + "=");
    ui->label4->setText(QString::number(std::get<0>(eq.at(3))) + "-" + QString::number(std::get<1>(eq.at(3))) + "=");
    ui->label5->setText(QString::number(std::get<0>(eq.at(4))) + "*" + QString::number(std::get<1>(eq.at(4))) + "=");
    ui->label6->setText(QString::number(std::get<0>(eq.at(5))) + "*" + QString::number(std::get<1>(eq.at(5))) + "=");
    ui->label7->setText(QString::number(std::get<0>(eq.at(6))) + "/" + QString::number(std::get<1>(eq.at(6))) + "=");
    ui->label8->setText(QString::number(std::get<0>(eq.at(7))) + "/" + QString::number(std::get<1>(eq.at(7))) + "=");
    if (readOnly) {
        ui->input1->setText(QString::number(std::get<2>(eq.at(0))));
        ui->input2->setText(QString::number(std::get<2>(eq.at(1))));
        ui->input3->setText(QString::number(std::get<2>(eq.at(2))));
        ui->input4->setText(QString::number(std::get<2>(eq.at(3))));
        ui->input5->setText(QString::number(std::get<2>(eq.at(4))));
        ui->input6->setText(QString::number(std::get<2>(eq.at(5))));
        ui->input7->setText(QString::number(std::get<2>(eq.at(6))));
        ui->input8->setText(QString::number(std::get<2>(eq.at(7))));
        ui->input1->setReadOnly(true);
        ui->input2->setReadOnly(true);
        ui->input3->setReadOnly(true);
        ui->input4->setReadOnly(true);
        ui->input5->setReadOnly(true);
        ui->input6->setReadOnly(true);
        ui->input7->setReadOnly(true);
        ui->input8->setReadOnly(true);
    }
}

bool ScreenTask3::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input1->text() == QString::number(std::get<2>(eq.at(0))) &&
            ui->input2->text() == QString::number(std::get<2>(eq.at(1))) &&
            ui->input3->text() == QString::number(std::get<2>(eq.at(2))) &&
            ui->input4->text() == QString::number(std::get<2>(eq.at(3))) &&
            ui->input5->text() == QString::number(std::get<2>(eq.at(4))) &&
            ui->input6->text() == QString::number(std::get<2>(eq.at(5))) &&
            ui->input7->text() == QString::number(std::get<2>(eq.at(6))) &&
            ui->input8->text() == QString::number(std::get<2>(eq.at(7)))
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
