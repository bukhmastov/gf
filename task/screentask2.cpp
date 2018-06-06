#include "screentask2.h"
#include "ui_screentask2.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    // part A
    ans1 = Static::getBetaTable(ScreenController::store["variant"]);
    // part B
    ans2.push_back("1");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    // part C
    int vi = Static::getVi(ScreenController::store["variant"]);
    QString vpi1 = Static::getVpi1(ScreenController::store["variant"]);
    if ((vpi1 == "1101" && (vi == 2 || vi == 4)) || (vpi1 == "1011" && (vi == 3 || vi == 5 || vi == 6))) {
        ans3.push_back("1");
        ans3.push_back("0");
        ans3.push_back("0");
        ans3.push_back("1");
        ans3.push_back("0");
        ans3.push_back("1");
        ans3.push_back("1");
    } else {
        ans3.push_back("1");
        ans3.push_back("1");
        ans3.push_back("1");
        ans3.push_back("0");
        ans3.push_back("1");
        ans3.push_back("0");
        ans3.push_back("0");
    }
    // part D
    int vj = Static::getVj(ScreenController::store["variant"]);
    ans4 = Static::getGammaTable(ScreenController::store["variant"]);
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%h%", Static::getReadablePolynom(vpi1));
    title = title.replace("%vi%", QString::number(vi));
    title = title.replace("%vj%", QString::number(vj));
    ui->title->setText(title);
    if (readOnly) {
        ui->input11->setText(ans1.at(1));
        ui->input12->setText(ans1.at(2));
        ui->input13->setText(ans1.at(3));
        ui->input14->setText(ans1.at(4));
        ui->input15->setText(ans1.at(5));
        ui->input16->setText(ans1.at(6));
        ui->input17->setText(ans1.at(7));
        ui->input21->setText(ans2.at(0));
        ui->input22->setText(ans2.at(1));
        ui->input23->setText(ans2.at(2));
        ui->input24->setText(ans2.at(3));
        ui->input25->setText(ans2.at(4));
        ui->input26->setText(ans2.at(5));
        ui->input27->setText(ans2.at(6));
        ui->input31->setText(ans3.at(0));
        ui->input32->setText(ans3.at(1));
        ui->input33->setText(ans3.at(2));
        ui->input34->setText(ans3.at(3));
        ui->input35->setText(ans3.at(4));
        ui->input36->setText(ans3.at(5));
        ui->input37->setText(ans3.at(6));
        ui->input41->setText(ans4.at(1));
        ui->input42->setText(ans4.at(2));
        ui->input43->setText(ans4.at(3));
        ui->input44->setText(ans4.at(4));
        ui->input45->setText(ans4.at(5));
        ui->input46->setText(ans4.at(6));
        ui->input47->setText(ans4.at(7));

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
    }
}

bool ScreenTask2::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input11->text() == ans1.at(1) &&
            ui->input12->text() == ans1.at(2) &&
            ui->input13->text() == ans1.at(3) &&
            ui->input14->text() == ans1.at(4) &&
            ui->input15->text() == ans1.at(5) &&
            ui->input16->text() == ans1.at(6) &&
            ui->input17->text() == ans1.at(7) &&

            ui->input21->text() == ans2.at(0) &&
            ui->input22->text() == ans2.at(1) &&
            ui->input23->text() == ans2.at(2) &&
            ui->input24->text() == ans2.at(3) &&
            ui->input25->text() == ans2.at(4) &&
            ui->input26->text() == ans2.at(5) &&
            ui->input27->text() == ans2.at(6) &&

            ui->input31->text() == ans3.at(0) &&
            ui->input32->text() == ans3.at(1) &&
            ui->input33->text() == ans3.at(2) &&
            ui->input34->text() == ans3.at(3) &&
            ui->input35->text() == ans3.at(4) &&
            ui->input36->text() == ans3.at(5) &&
            ui->input37->text() == ans3.at(6) &&

            ui->input41->text() == ans4.at(1) &&
            ui->input42->text() == ans4.at(2) &&
            ui->input43->text() == ans4.at(3) &&
            ui->input44->text() == ans4.at(4) &&
            ui->input45->text() == ans4.at(5) &&
            ui->input46->text() == ans4.at(6) &&
            ui->input47->text() == ans4.at(7)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
