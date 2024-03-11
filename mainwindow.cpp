#include <mainwindow.h>
#include <ui_mainwindow.h>

DataBase::DataBase() {};

DataBase::DataBase(const char* serverIP, const char* user, const char* passwd, const char*dbName) {
    connection = mysql_init(nullptr);
    mysql_real_connect(connection, serverIP, user, passwd, dbName, 0, NULL, 0);
}

DataBase::DataBase(const DataBase& copy) {
    if (copy.connection != nullptr) {
        connection = mysql_init(nullptr);
        mysql_real_connect(connection, copy.connection->host, copy.connection->user, copy.connection->passwd, copy.connection->db, 0, NULL, 0);
    }
}

DataBase& DataBase::operator=(const DataBase& copy) {
    if (this != &copy) {
        delete connection;
        if (copy.connection != nullptr) {
            connection = mysql_init(nullptr);
            mysql_real_connect(connection, copy.connection->host, copy.connection->user, copy.connection->passwd, copy.connection->db, 0, NULL, 0);
        }
    }
    return *this;
}

void DataBase::setNewConnection(char* serverIP, char* user, char* passwd, char*dbName) {
    mysql_close(connection);
    connection = mysql_init(nullptr);
    mysql_real_connect(connection, serverIP, user, passwd, dbName, 0, NULL, 0);
}

MYSQL_RES* DataBase::performQuery(const char *query) {
    mysql_query(connection, query);
    return mysql_use_result(connection);
}

bool DataBase::isConnectionValid() {
    if (connection != nullptr) {
        return true;
    } else {
        return false;
    }
}

DataBase::~DataBase() {
    mysql_close(connection);
}

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
