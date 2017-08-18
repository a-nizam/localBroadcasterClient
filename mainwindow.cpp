#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    client(new Client)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pbConnect_clicked() {
    client->connect();
}

void MainWindow::on_pbSendMessage_clicked() {
    client->sendMessage(ui->teMessage->toPlainText());
}
