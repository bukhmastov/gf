#include "screentask6.h"
#include "ui_screentask6.h"

ScreenTask6::ScreenTask6(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask6) {
    ui->setupUi(this);
}

ScreenTask6::~ScreenTask6() {
    delete ui;
}

void ScreenTask6::init() {
    matrix = Static::getFMSRmatrix();
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

        ui->input11->setReadOnly(true);
        ui->input12->setReadOnly(true);
        ui->input13->setReadOnly(true);
        ui->input14->setReadOnly(true);
        ui->input15->setReadOnly(true);
        ui->input16->setReadOnly(true);
        ui->input17->setReadOnly(true);
        ui->input21->setReadOnly(true);
        ui->input22->setReadOnly(true);
        ui->input23->setReadOnly(true);
        ui->input24->setReadOnly(true);
        ui->input25->setReadOnly(true);
        ui->input26->setReadOnly(true);
        ui->input27->setReadOnly(true);
        ui->input31->setReadOnly(true);
        ui->input32->setReadOnly(true);
        ui->input33->setReadOnly(true);
        ui->input34->setReadOnly(true);
        ui->input35->setReadOnly(true);
        ui->input36->setReadOnly(true);
        ui->input37->setReadOnly(true);
        ui->input41->setReadOnly(true);
        ui->input42->setReadOnly(true);
        ui->input43->setReadOnly(true);
        ui->input44->setReadOnly(true);
        ui->input45->setReadOnly(true);
        ui->input46->setReadOnly(true);
        ui->input47->setReadOnly(true);
        ui->input51->setReadOnly(true);
        ui->input52->setReadOnly(true);
        ui->input53->setReadOnly(true);
        ui->input54->setReadOnly(true);
        ui->input55->setReadOnly(true);
        ui->input56->setReadOnly(true);
        ui->input57->setReadOnly(true);
        ui->input61->setReadOnly(true);
        ui->input62->setReadOnly(true);
        ui->input63->setReadOnly(true);
        ui->input64->setReadOnly(true);
        ui->input65->setReadOnly(true);
        ui->input66->setReadOnly(true);
        ui->input67->setReadOnly(true);
        ui->input71->setReadOnly(true);
        ui->input72->setReadOnly(true);
        ui->input73->setReadOnly(true);
        ui->input74->setReadOnly(true);
        ui->input75->setReadOnly(true);
        ui->input76->setReadOnly(true);
        ui->input77->setReadOnly(true);
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
