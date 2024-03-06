#ifndef DBWINDOW_H
#define DBWINDOW_H

#include <QDialog>

namespace Ui {
class DBWindow;
}

class DBWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DBWindow(QWidget *parent = nullptr);
    ~DBWindow();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DBWindow *ui;
};

#endif // DBWINDOW_H
