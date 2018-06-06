#include "screentask0.h"
#include "ui_screentask0.h"

ScreenTask0::ScreenTask0(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask0) {
    ui->setupUi(this);
}

ScreenTask0::~ScreenTask0() {
    delete ui;
}

void ScreenTask0::init() {
    for (int i = 0; i < 50; i++) {
        ui->variant->addItem(QString::number(i + 1));
    }
    if (readOnly) {
        ui->variant->setCurrentIndex(ScreenController::store["variant"].toInt());
        ui->variant->setEnabled(false);
    }
}

bool ScreenTask0::validate(Core*, QString*) {
    ScreenController::store["variant"] = QString::number(ui->variant->currentIndex());
    return true;
}
