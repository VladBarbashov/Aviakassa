#include <mainwindow.h>
#include <ui_mainwindow.h>

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stringValidator(new QRegularExpressionValidator(QRegularExpression("[А-я]{1,20}"),this)) {
    ui->setupUi(this);
    hideAll();
    ui->departureCityLine->setValidator(stringValidator);
    ui->arrivalCityLine->setValidator(stringValidator);
}

MainWindow::~MainWindow() {
    delete stringValidator;
    delete ui;
}

void MainWindow::on_buttonSearch_clicked() {
    ui->buttonSearch->setText(QString::number(ui->buttonSearch->sizeHint().height()));
    // DataBase db("localhost", "vladislav", "8239", "flights");
    // MYSQL_RES* res = db.performQuery("show databases");
    // while (MYSQL_ROW row = mysql_fetch_row(res)){
    //     std::cout << row[0] << std::endl;
    // }
    //if (db.isConnectionValid() == false) QMessageBox::warning(this, "Error", db.performQuery("show databases;")->current_row[0]);
}

void MainWindow::hideAll() {
    ui->departureCityList->setVisible(false);
    ui->arrivalCityList->setVisible(false);
    ui->dateCalendar->setVisible(false);
    ui->oneWayButton->setVisible(false);
}

void MainWindow::on_departureDateButton_clicked() {
    hideAll();
    ui->dateCalendar->setVisible(true);
}

void MainWindow::on_backDateButton_clicked() {
    hideAll();
    ui->dateCalendar->setVisible(true);
    ui->oneWayButton->setVisible(true);
}

void MainWindow::on_dateCalendar_clicked(const QDate &date) {
    hideAll();
}

void MainWindow::on_menuGroupBox_clicked() {
    hideAll();
}

void MainWindow::on_changeButton_clicked() {

}

void MainWindow::on_arrivalCityLine_textChanged(const QString &arg1) {

}
