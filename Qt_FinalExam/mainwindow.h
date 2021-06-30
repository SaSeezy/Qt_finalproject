#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addstudentform.h"
#include "about.h"

#include <QMainWindow>
#include <QGridLayout>
#include <QGraphicsView>
#include <QSqlTableModel>
#include <QPrinter>

QT_BEGIN_NAMESPACE
    namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void print(QPrinter *printer);

    void on_AddButton_clicked();

    void on_printButton_clicked();

    void on_reloadButton_clicked();

    void on_resetButton_clicked();

    void on_actionNew_Window_triggered();

    void on_actionReload_triggered();

    void on_actionPrint_triggered();

    void on_actionReset_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_6_clicked();

    void on_uploadFileButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlDatabase db;

};
#endif // MAINWINDOW_H
