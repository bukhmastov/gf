#include "screenwelcome.h"
#include "ui_screenwelcome.h"

ScreenWelcome::ScreenWelcome(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenWelcome) {
    ui->setupUi(this);
}

ScreenWelcome::~ScreenWelcome() {
    delete ui;
}

void ScreenWelcome::init() {
    ScreenController::store["variant"] = QString::number(rnd() % 50 + 1);
}

bool ScreenWelcome::validate(Core*, QString*) {
    return true;
}
