#include "screentask1.h"
#include "ui_screentask1.h"

ScreenTask1::ScreenTask1(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask1) {
    ui->setupUi(this);
}

ScreenTask1::~ScreenTask1() {
    delete ui;
}

void ScreenTask1::init() {
    int p = 5;
    switch (rnd() % 4) {
    case 0: p = 5;  break;
    case 1: p = 7;  break;
    case 2: p = 11; break;
    case 3: p = 13; break;
    }
    for (int i = 0; i < 8; i++) {
        int a = rnd() % p + 1;
        int b = rnd() % p + 1;
        int ab = (i / 4 == 0 ? a + b : a * b) % p;
        eq.push_back(std::make_tuple(a, b, ab));
    }
    ui->title->setText(ui->title->text().replace("%p%", QString::number(p)));
    ui->label1->setText(QString::number(std::get<0>(eq.at(0))) + "+" + QString::number(std::get<1>(eq.at(0))) + "=");
    ui->label2->setText(QString::number(std::get<0>(eq.at(1))) + "+" + QString::number(std::get<1>(eq.at(1))) + "=");
    ui->label3->setText(QString::number(std::get<0>(eq.at(2))) + "+" + QString::number(std::get<1>(eq.at(2))) + "=");
    ui->label4->setText(QString::number(std::get<0>(eq.at(3))) + "+" + QString::number(std::get<1>(eq.at(3))) + "=");
    ui->label5->setText(QString::number(std::get<0>(eq.at(4))) + "*" + QString::number(std::get<1>(eq.at(4))) + "=");
    ui->label6->setText(QString::number(std::get<0>(eq.at(5))) + "*" + QString::number(std::get<1>(eq.at(5))) + "=");
    ui->label7->setText(QString::number(std::get<0>(eq.at(6))) + "*" + QString::number(std::get<1>(eq.at(6))) + "=");
    ui->label8->setText(QString::number(std::get<0>(eq.at(7))) + "*" + QString::number(std::get<1>(eq.at(7))) + "=");
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

bool ScreenTask1::validate(Core* core, QString* message) {
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
