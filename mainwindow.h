#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValidator>

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

    void on_arrivalCityLine_textChanged(const QString &arg1);

private:
    void hideAll();

    Ui::MainWindow *ui;
    QRegularExpressionValidator* stringValidator;
};
#endif // MAINWINDOW_H
