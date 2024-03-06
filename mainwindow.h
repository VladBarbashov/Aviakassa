#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dbwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_buttonSearch_clicked();

    void on_actionDB_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    DBWindow* dbWindow;
};
#endif // MAINWINDOW_H
