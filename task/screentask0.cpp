#include "screentask0.h"
#include "ui_screentask0.h"

ScreenTask0::ScreenTask0(QWidget *parent) : ScreenController(parent), ui(new Ui::ScreenTask0) {
    ui->setupUi(this);
}

ScreenTask0::~ScreenTask0() {
    delete ui;
}

void ScreenTask0::init() {

    labelPI1 = ui->labelPI1->text();
    labelI = ui->labelI->text();
    labelJ = ui->labelJ->text();
    labelA = ui->labelA->text();
    labelPI2 = ui->labelPI2->text();
    labelK = ui->labelK->text();

    for (int i = 1; i <= 50; i++) {
        ui->variant->addItem(QString::number(i));
    }

    if (Static::allowSelectVariant) {
        if (readOnly) {
            int variant = ScreenController::store["variant"].toInt();
            ui->variant->setCurrentIndex(variant);
            ui->variant->setEnabled(false);
            variantSelected(variant);
        } else {
            QObject::connect(ui->variant, SIGNAL(currentIndexChanged(int)), this, SLOT(variantSelected(int)));
            ui->variant->setCurrentIndex(0);
            variantSelected(0);
        }
    } else {
        int variant = rnd() % 50;
        variantSelected(variant);
        Static::clearLayout(ui->variantChooserContainerContent);
        Static::clearLayout(ui->variantChooserContainer);
        ui->variant->setCurrentIndex(variant);
        ui->variant->setEnabled(false);
    }
}

void ScreenTask0::variantSelected(int index) {
    QString variant = QString::number(index);
    ScreenController::store["variant"] = variant;
    ui->labelPI1->setText(QString(labelPI1).replace("%pi%", Static::getVpi1(variant)));
    ui->labelI->setText(QString(labelI).replace("%i%", QString::number(Static::getVi(variant))));
    ui->labelJ->setText(QString(labelJ).replace("%j%", QString::number(Static::getVj(variant))));
    ui->labelA->setText(QString(labelA).replace("%a%", Static::getVa(variant)));
    ui->labelPI2->setText(QString(labelPI2).replace("%pi%", Static::getVpi2(variant)));
    ui->labelK->setText(QString(labelK).replace("%k%", QString::number(Static::getVk(variant))));
}

bool ScreenTask0::validate(Core*, QString*) {
    return true;
}
