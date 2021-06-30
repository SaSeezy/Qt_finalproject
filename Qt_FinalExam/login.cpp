#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);


}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{

    QString servername = "DESKTOP-N9TEHFO\\SQLEXPRESS";
    QString dbname = "Test";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC","login");

    db.setConnectOptions();

    QString dsn = QString("DRIVER={SQL SERVER};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(servername).arg(dbname);

    db.setDatabaseName(dsn);
    if(db.open())
    {
         bool checker = false;

         QSqlQuery query(QSqlDatabase::database("login"));

         QString password = ui->lineEdit_2->text();

         query.prepare("SELECT [username],[password] FROM [Test].[dbo].[Manager] WHERE [username]=:first");
         query.bindValue(":first", ui->lineEdit->text());

         if(query.exec())
         {
               while(query.next())
               {
                    if(ui->lineEdit->text() == query.value(0) && ui->lineEdit_2->text() == query.value(1))
                            checker = true;
               }
         }

         if(checker==true)
         {
               emit adminSignal();
               close();
         }
         else
               QMessageBox::critical(this, "Error", "<strong>Wrong username or password</strong>");
     }

//    db = QSqlDatabase::database();
//    db.close();
//    QSqlDatabase::removeDatabase("login");
}

