#include "dbwindow.h"
#include "ui_dbwindow.h"

DBWindow::DBWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DBWindow)
{
    ui->setupUi(this);
}

DBWindow::~DBWindow()
{
    delete ui;
}

void DBWindow::on_pushButton_clicked()
{
    emit firstWindow();
    this->close();
}

