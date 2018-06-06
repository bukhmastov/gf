#include "screentask11.h"
#include "ui_screentask11.h"

ScreenTask11::ScreenTask11(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask11) {
    ui->setupUi(this);
}

ScreenTask11::~ScreenTask11() {
    delete ui;
}

void ScreenTask11::init() {
    QString pi = Static::getVpi2(ScreenController::store["variant"]);
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
    // setup ui
    ui->title->setText(ui->title->text().replace("%p%", Static::getReadablePolynom(pi)));
    if (readOnly) {
        ui->input0->setText(tableAlpha.at(0));
        ui->input1->setText(tableAlpha.at(1));
        ui->input2->setText(tableAlpha.at(2));
        ui->input3->setText(tableAlpha.at(3));
        ui->input4->setText(tableAlpha.at(4));
        ui->input5->setText(tableAlpha.at(5));
        ui->input6->setText(tableAlpha.at(6));
        ui->input7->setText(tableAlpha.at(7));

        ui->input0->setEnabled(false);
        ui->input1->setEnabled(false);
        ui->input2->setEnabled(false);
        ui->input3->setEnabled(false);
        ui->input4->setEnabled(false);
        ui->input5->setEnabled(false);
        ui->input6->setEnabled(false);
        ui->input7->setEnabled(false);
    }
}

bool ScreenTask11::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input0->text() == tableAlpha.at(0) &&
            ui->input1->text() == tableAlpha.at(1) &&
            ui->input2->text() == tableAlpha.at(2) &&
            ui->input3->text() == tableAlpha.at(3) &&
            ui->input4->text() == tableAlpha.at(4) &&
            ui->input5->text() == tableAlpha.at(5) &&
            ui->input6->text() == tableAlpha.at(6) &&
            ui->input7->text() == tableAlpha.at(7)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
