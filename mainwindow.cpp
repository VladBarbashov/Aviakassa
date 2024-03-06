#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <mysql.h>
struct connection_details
{
    const char *server, *user, *password, *database;
};

MYSQL* mysql_connection_setup(struct connection_details mysql_details){
    MYSQL *connection = mysql_init(NULL); // mysql instance

    //connect database
    if(!mysql_real_connect(connection, mysql_details.server, mysql_details.user, mysql_details.password, mysql_details.database, 0, NULL, 0)){
        exit(1);
    }

    return connection;
}

// mysql_res = mysql result
MYSQL_RES* mysql_perform_query(MYSQL *connection, const char *sql_query){
    //send query to db
    if(mysql_query(connection, sql_query)){
        exit(1);
    }

    return mysql_use_result(connection);
}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dbWindow = new DBWindow();
    connect(dbWindow, &DBWindow::firstWindow, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonSearch_clicked()
{

}

void MainWindow::on_actionDB_triggered()
{
    dbWindow->show();
    //this->close();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

