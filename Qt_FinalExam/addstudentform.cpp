#include "addstudentform.h"
#include "ui_addstudentform.h"

AddStudentForm::AddStudentForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddStudentForm)
{
    ui->setupUi(this);

    //set current date
    ui->label->setText(QDate::currentDate().toString());
}

AddStudentForm::~AddStudentForm()
{
    delete ui;
}

void AddStudentForm::on_insertIntoDbButton_clicked()
{
       QString servername = "DESKTOP-N9TEHFO\\SQLEXPRESS";
       QString dbname = "Test";

      QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","addcon");

       db.setConnectOptions();

       QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

       db.setDatabaseName(dsn);
        if(db.open())
        {

              QString sQuery = "INSERT INTO [Test].[dbo].[Student]([dates],[degree],[studentID],[name],[roomNumber],[leavingTime],[reason],[returnTime],[taxi],[place],[temperature],[duration])VALUES(:date,:studentID,:degre,:name,:roomNumber,:leavingTime,:reason,:returnTime,:taxi,:place,:temperature,:duration)";

              QSqlQuery qry(QSqlDatabase::database("addcon"));
              qry.prepare(sQuery);

              qry.bindValue(":date",QDate::currentDate().toString());
              qry.bindValue(":studentID",ui->studentIDLineEdit->text());
              qry.bindValue(":degre",ui->levelLineEdit->text());
              qry.bindValue(":name",ui->nameLineEdit->text());
              qry.bindValue(":roomNumber",ui->roomLineEdit->text());
              qry.bindValue(":leavingTime",ui->timeLeavingLineEdit->text());
              qry.bindValue(":reason",ui->reasonLineEdit->text());
              qry.bindValue(":returnTime",ui->timeReturnLineEdit->text());
              qry.bindValue(":taxi",ui->taxiLineEdit->text());
              qry.bindValue(":place",ui->placeLineEdit->text());
              qry.bindValue(":temperature",ui->temperatureLineEdit->text());
              qry.bindValue(":duration",ui->durationLineEdit->text());

              if(qry.exec())
                    QMessageBox::information(this, "Connected", "<strong>Record Inserted !</strong>");
        }
        else
        {
            QMessageBox::critical(this, "Error", "Cannot open the database");
        }

        db = QSqlDatabase::database();
        db.close();
        db.removeDatabase("addcon");
}
