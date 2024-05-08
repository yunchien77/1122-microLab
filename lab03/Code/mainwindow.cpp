#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "led_control.cpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QImage bright(QString("../bright.jpeg"));
    QImage dark(QString("../dark.jpeg"));
    ui -> bright1 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright2 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright3 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright4 ->setPixmap(QPixmap::fromImage(dark));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_mybutton_clicked()
{
    QString test = ui -> test-> text();
    QImage bright(QString("../bright.jpeg"));
    QImage dark(QString("../dark.jpeg"));
    ui -> bright1 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright2 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright3 ->setPixmap(QPixmap::fromImage(dark));
    ui -> bright4 ->setPixmap(QPixmap::fromImage(dark));


    if (ui -> checkBox_1 -> isChecked() == true)
   {
        ui -> bright1 ->setPixmap(QPixmap::fromImage(bright));
        ui -> test ->setText("1 on");
        LED_main(1, 1, 1, 0);
    }
    else{
        ui -> test ->setText("1 off");
        ui -> bright1 ->setPixmap(QPixmap::fromImage(dark));
        LED_main(1, 1, 0, 0);
    }
    if (ui -> checkBox_2 -> isChecked() == true)
   {
        ui -> bright2 ->setPixmap(QPixmap::fromImage(bright));
        ui -> test ->setText("2 on");
        LED_main(1, 2, 1, 0);
    }
    else{
        ui -> test ->setText("2 off");
        ui -> bright2 ->setPixmap(QPixmap::fromImage(dark));
        LED_main(1, 2, 0, 0);
    }
    if (ui -> checkBox_3 -> isChecked() == true)
   {
        ui -> bright3 ->setPixmap(QPixmap::fromImage(bright));
        ui -> test ->setText("1 on");
        LED_main(1, 3, 1, 0);
    }
    else{
        ui -> test ->setText("1 off");
        ui -> bright3 ->setPixmap(QPixmap::fromImage(dark));
        LED_main(1, 3, 0, 0);
    }
    if (ui -> checkBox_4 -> isChecked() == true)
   {
        ui -> bright4 ->setPixmap(QPixmap::fromImage(bright));
        ui -> test ->setText("1 on");
        LED_main(1, 4, 1, 0);
    }
    else{
        ui -> test ->setText("1 off");
        ui -> bright4 ->setPixmap(QPixmap::fromImage(dark));
        LED_main(1, 4, 0, 0);
    }


}



void MainWindow::on_mybutton_2_clicked()
{
    LED_main(2, 0, 0,ui->lineEdit->text().toInt());
}
