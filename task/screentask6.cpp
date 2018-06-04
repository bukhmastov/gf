#include "screentask6.h"
#include "ui_screentask6.h"

ScreenTask6::ScreenTask6(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask6) {
    ui->setupUi(this);
}

ScreenTask6::~ScreenTask6() {
    delete ui;
}

void ScreenTask6::init() {
    matrix.push_back(std::vector<QString>{"1", "1", "1", "1", "1", "1", "1"});
    matrix.push_back(std::vector<QString>{"1", "7", "6", "5", "4", "3", "2"});
    matrix.push_back(std::vector<QString>{"1", "6", "4", "2", "7", "5", "3"});
    matrix.push_back(std::vector<QString>{"1", "5", "2", "6", "3", "7", "4"});
    matrix.push_back(std::vector<QString>{"1", "4", "7", "3", "6", "2", "5"});
    matrix.push_back(std::vector<QString>{"1", "3", "5", "7", "2", "4", "6"});
    matrix.push_back(std::vector<QString>{"1", "2", "3", "4", "5", "6", "7"});
    if (readOnly) {
        ui->input11->setText(matrix.at(0).at(0));
        ui->input12->setText(matrix.at(0).at(1));
        ui->input13->setText(matrix.at(0).at(2));
        ui->input14->setText(matrix.at(0).at(3));
        ui->input15->setText(matrix.at(0).at(4));
        ui->input16->setText(matrix.at(0).at(5));
        ui->input17->setText(matrix.at(0).at(6));

        ui->input21->setText(matrix.at(1).at(0));
        ui->input22->setText(matrix.at(1).at(1));
        ui->input23->setText(matrix.at(1).at(2));
        ui->input24->setText(matrix.at(1).at(3));
        ui->input25->setText(matrix.at(1).at(4));
        ui->input26->setText(matrix.at(1).at(5));
        ui->input27->setText(matrix.at(1).at(6));

        ui->input31->setText(matrix.at(2).at(0));
        ui->input32->setText(matrix.at(2).at(1));
        ui->input33->setText(matrix.at(2).at(2));
        ui->input34->setText(matrix.at(2).at(3));
        ui->input35->setText(matrix.at(2).at(4));
        ui->input36->setText(matrix.at(2).at(5));
        ui->input37->setText(matrix.at(2).at(6));

        ui->input41->setText(matrix.at(3).at(0));
        ui->input42->setText(matrix.at(3).at(1));
        ui->input43->setText(matrix.at(3).at(2));
        ui->input44->setText(matrix.at(3).at(3));
        ui->input45->setText(matrix.at(3).at(4));
        ui->input46->setText(matrix.at(3).at(5));
        ui->input47->setText(matrix.at(3).at(6));

        ui->input51->setText(matrix.at(4).at(0));
        ui->input52->setText(matrix.at(4).at(1));
        ui->input53->setText(matrix.at(4).at(2));
        ui->input54->setText(matrix.at(4).at(3));
        ui->input55->setText(matrix.at(4).at(4));
        ui->input56->setText(matrix.at(4).at(5));
        ui->input57->setText(matrix.at(4).at(6));

        ui->input61->setText(matrix.at(5).at(0));
        ui->input62->setText(matrix.at(5).at(1));
        ui->input63->setText(matrix.at(5).at(2));
        ui->input64->setText(matrix.at(5).at(3));
        ui->input65->setText(matrix.at(5).at(4));
        ui->input66->setText(matrix.at(5).at(5));
        ui->input67->setText(matrix.at(5).at(6));

        ui->input71->setText(matrix.at(6).at(0));
        ui->input72->setText(matrix.at(6).at(1));
        ui->input73->setText(matrix.at(6).at(2));
        ui->input74->setText(matrix.at(6).at(3));
        ui->input75->setText(matrix.at(6).at(4));
        ui->input76->setText(matrix.at(6).at(5));
        ui->input77->setText(matrix.at(6).at(6));
    }
}

bool ScreenTask6::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input11->text() == matrix.at(0).at(0) &&
            ui->input12->text() == matrix.at(0).at(1) &&
            ui->input13->text() == matrix.at(0).at(2) &&
            ui->input14->text() == matrix.at(0).at(3) &&
            ui->input15->text() == matrix.at(0).at(4) &&
            ui->input16->text() == matrix.at(0).at(5) &&
            ui->input17->text() == matrix.at(0).at(6) &&

            ui->input21->text() == matrix.at(1).at(0) &&
            ui->input22->text() == matrix.at(1).at(1) &&
            ui->input23->text() == matrix.at(1).at(2) &&
            ui->input24->text() == matrix.at(1).at(3) &&
            ui->input25->text() == matrix.at(1).at(4) &&
            ui->input26->text() == matrix.at(1).at(5) &&
            ui->input27->text() == matrix.at(1).at(6) &&

            ui->input31->text() == matrix.at(2).at(0) &&
            ui->input32->text() == matrix.at(2).at(1) &&
            ui->input33->text() == matrix.at(2).at(2) &&
            ui->input34->text() == matrix.at(2).at(3) &&
            ui->input35->text() == matrix.at(2).at(4) &&
            ui->input36->text() == matrix.at(2).at(5) &&
            ui->input37->text() == matrix.at(2).at(6) &&

            ui->input41->text() == matrix.at(3).at(0) &&
            ui->input42->text() == matrix.at(3).at(1) &&
            ui->input43->text() == matrix.at(3).at(2) &&
            ui->input44->text() == matrix.at(3).at(3) &&
            ui->input45->text() == matrix.at(3).at(4) &&
            ui->input46->text() == matrix.at(3).at(5) &&
            ui->input47->text() == matrix.at(3).at(6) &&

            ui->input51->text() == matrix.at(4).at(0) &&
            ui->input52->text() == matrix.at(4).at(1) &&
            ui->input53->text() == matrix.at(4).at(2) &&
            ui->input54->text() == matrix.at(4).at(3) &&
            ui->input55->text() == matrix.at(4).at(4) &&
            ui->input56->text() == matrix.at(4).at(5) &&
            ui->input57->text() == matrix.at(4).at(6) &&

            ui->input61->text() == matrix.at(5).at(0) &&
            ui->input62->text() == matrix.at(5).at(1) &&
            ui->input63->text() == matrix.at(5).at(2) &&
            ui->input64->text() == matrix.at(5).at(3) &&
            ui->input65->text() == matrix.at(5).at(4) &&
            ui->input66->text() == matrix.at(5).at(5) &&
            ui->input67->text() == matrix.at(5).at(6) &&

            ui->input71->text() == matrix.at(6).at(0) &&
            ui->input72->text() == matrix.at(6).at(1) &&
            ui->input73->text() == matrix.at(6).at(2) &&
            ui->input74->text() == matrix.at(6).at(3) &&
            ui->input75->text() == matrix.at(6).at(4) &&
            ui->input76->text() == matrix.at(6).at(5) &&
            ui->input77->text() == matrix.at(6).at(6)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
