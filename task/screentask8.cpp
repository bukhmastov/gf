#include "screentask8.h"
#include "ui_screentask8.h"

ScreenTask8::ScreenTask8(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask8) {
    ui->setupUi(this);
}

ScreenTask8::~ScreenTask8() {
    delete ui;
}

void ScreenTask8::init() {
    std::vector<std::vector<QString>> matrix = Static::getFMSRmatrix();
    std::vector<QString> table = Static::getBetaTable(ScreenController::store["variant"]);
    QString b = Static::getVb(ScreenController::store["variant"]);
    for (int i = 0; i < 7; i++) {
        int x = 0;
        for (int j = 0; j < 7; j++) {
            int z = QString(b.at(j)).toInt();
            int m = matrix.at(i).at(j).toInt();
            int multiply = 0;
            if (z != 0 && m != 0) {
                multiply = (z - 1 + m - 1) % 7 + 1;
            }
            x = Static::summarize(table, x, multiply);
        }
        answer.append(QString::number(x));
    }
    answer.at(0);
    ui->title->setText(ui->title->text().replace("%b%", b));
    if (readOnly) {
        ui->input->setText(answer);
        ui->input->setEnabled(false);
    }
}

bool ScreenTask8::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (ui->input->text() == answer) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
