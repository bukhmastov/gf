#include "screentask2.h"
#include "ui_screentask2.h"

ScreenTask2::ScreenTask2(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask2) {
    ui->setupUi(this);
}

ScreenTask2::~ScreenTask2() {
    delete ui;
}

void ScreenTask2::init() {
    int n = rnd() % 5 + 2;
    QString h = Static::getVpi1(ScreenController::store["variant"]);
    // part A
    if (h == "1101") {
        switch (n) {
        case 2:
            ans1.push_back("001");
            ans1.push_back("100");
            ans1.push_back("110");
            ans1.push_back("101");
            ans1.push_back("010");
            ans1.push_back("011");
            ans1.push_back("111");
            break;
        case 3:
            ans1.push_back("001");
            ans1.push_back("011");
            ans1.push_back("101");
            ans1.push_back("100");
            ans1.push_back("111");
            ans1.push_back("010");
            ans1.push_back("110");
            break;
        case 4:
            ans1.push_back("001");
            ans1.push_back("110");
            ans1.push_back("010");
            ans1.push_back("111");
            ans1.push_back("100");
            ans1.push_back("101");
            ans1.push_back("011");
            break;
        case 5:
            ans1.push_back("001");
            ans1.push_back("111");
            ans1.push_back("011");
            ans1.push_back("010");
            ans1.push_back("101");
            ans1.push_back("110");
            ans1.push_back("100");
            break;
        case 6:
            ans1.push_back("011");
            ans1.push_back("101");
            ans1.push_back("111");
            ans1.push_back("110");
            ans1.push_back("011");
            ans1.push_back("100");
            ans1.push_back("010");
            break;
        }
    } else {
        switch (n) {
        case 2:
            ans1.push_back("001");
            ans1.push_back("100");
            ans1.push_back("111");
            ans1.push_back("110");
            ans1.push_back("010");
            ans1.push_back("101");
            ans1.push_back("011");
            break;
        case 3:
            ans1.push_back("001");
            ans1.push_back("101");
            ans1.push_back("110");
            ans1.push_back("100");
            ans1.push_back("011");
            ans1.push_back("010");
            ans1.push_back("111");
            break;
        case 4:
            ans1.push_back("001");
            ans1.push_back("111");
            ans1.push_back("010");
            ans1.push_back("011");
            ans1.push_back("100");
            ans1.push_back("110");
            ans1.push_back("101");
            break;
        case 5:
            ans1.push_back("001");
            ans1.push_back("011");
            ans1.push_back("101");
            ans1.push_back("010");
            ans1.push_back("110");
            ans1.push_back("111");
            ans1.push_back("100");
            break;
        case 6:
            ans1.push_back("011");
            ans1.push_back("110");
            ans1.push_back("011");
            ans1.push_back("111");
            ans1.push_back("101");
            ans1.push_back("100");
            ans1.push_back("010");
            break;
        }
    }
    // part B
    ans2.push_back("1");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    ans2.push_back("7");
    // part C
    if ((h == "1101" && (n == 2 || n == 4)) || (h == "1011" && (n == 3 || n == 5 || n == 6))) {
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
    if (h == "1101") {
        ans4.push_back("111");
        ans4.push_back("001");
        ans4.push_back("010");
        ans4.push_back("101");
        ans4.push_back("100");
        ans4.push_back("110");
        ans4.push_back("011");
    } else {
        ans4.push_back("111");
        ans4.push_back("001");
        ans4.push_back("010");
        ans4.push_back("101");
        ans4.push_back("100");
        ans4.push_back("110");
        ans4.push_back("011");
    }
    // setup ui
    QString title = ui->title->text();
    title = title.replace("%h%", Static::getReadablePolynom(h));
    title = title.replace("%n%", QString::number(n));
    ui->title->setText(title);
    if (readOnly) {
        ui->input11->setText(ans1.at(0));
        ui->input12->setText(ans1.at(1));
        ui->input13->setText(ans1.at(2));
        ui->input14->setText(ans1.at(3));
        ui->input15->setText(ans1.at(4));
        ui->input16->setText(ans1.at(5));
        ui->input17->setText(ans1.at(6));

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

        ui->input41->setText(ans4.at(0));
        ui->input42->setText(ans4.at(1));
        ui->input43->setText(ans4.at(2));
        ui->input44->setText(ans4.at(3));
        ui->input45->setText(ans4.at(4));
        ui->input46->setText(ans4.at(5));
        ui->input47->setText(ans4.at(6));
    }
}

bool ScreenTask2::validate(Core* core, QString* message) {
    if (readOnly) {
        return true;
    }
    if (
            ui->input11->text() == ans1.at(0) &&
            ui->input12->text() == ans1.at(1) &&
            ui->input13->text() == ans1.at(2) &&
            ui->input14->text() == ans1.at(3) &&
            ui->input15->text() == ans1.at(4) &&
            ui->input16->text() == ans1.at(5) &&
            ui->input17->text() == ans1.at(6) &&

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

            ui->input41->text() == ans4.at(0) &&
            ui->input42->text() == ans4.at(1) &&
            ui->input43->text() == ans4.at(2) &&
            ui->input44->text() == ans4.at(3) &&
            ui->input45->text() == ans4.at(4) &&
            ui->input46->text() == ans4.at(5) &&
            ui->input47->text() == ans4.at(6)
    ) {
        message->append(Static::messageAnswerRight);
        core->changeScore(2);
    } else {
        message->append(Static::messageAnswerWrong);
        core->changeScore(-2);
    }
    return true;
}
