#ifndef ADDSTUDENTFORM_H
#define ADDSTUDENTFORM_H


#include <QDialog>
#include <QMessageBox>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlQuery>


namespace Ui {
class AddStudentForm;
}

class AddStudentForm : public QDialog
{
    Q_OBJECT

public:
    explicit AddStudentForm(QWidget *parent = nullptr);
    ~AddStudentForm();

private slots:
    void on_insertIntoDbButton_clicked();

private:
    Ui::AddStudentForm *ui;
};

#endif // ADDSTUDENTFORM_H
