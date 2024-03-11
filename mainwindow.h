#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QValidator>

#include <mysql.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
    void on_buttonSearch_clicked();

    void on_departureDateButton_clicked();

    void on_dateCalendar_clicked(const QDate &date);

    void on_backDateButton_clicked();

    void on_menuGroupBox_clicked();

    void on_changeButton_clicked();

private:
    void hideAll();

    Ui::MainWindow *ui;
    QRegularExpressionValidator* stringValidator;
};

class DataBase {
public:
    DataBase();

    DataBase(const char* serverIP, const char* user, const char* passwd, const char*dbName);

    DataBase(const DataBase& copy);

    DataBase& operator=(const DataBase& copy);

    void setNewConnection(char* serverIP, char* user, char* passwd, char*dbName);

    MYSQL_RES* performQuery(const char *query);

    bool isConnectionValid();

    ~DataBase();

private:
    MYSQL *connection = nullptr;
};
#endif // MAINWINDOW_H
