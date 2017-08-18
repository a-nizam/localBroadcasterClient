#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pbConnect_clicked();

    void on_pbSendMessage_clicked();

private:
    Ui::MainWindow *ui;

    Client *client;
};

#endif // MAINWINDOW_H
