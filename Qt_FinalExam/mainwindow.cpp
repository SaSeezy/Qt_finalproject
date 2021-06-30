#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "login.h"
#include "tableprinter.h"
#include "fileuploaddialog.h"


#include <QPrintPreviewDialog>


class PrintBorder : public PagePrepare {
public:
    virtual void preparePage(QPainter *painter);
    static int pageNumber;
};

int PrintBorder::pageNumber = 0;

void PrintBorder::preparePage(QPainter *painter) { // print a border on each page
    QRect rec = painter->viewport();
    painter->setPen(QPen(QColor(0, 0, 0), 1));
    painter->drawRect(rec);
    painter->translate(10, painter->viewport().height() - 10);
    painter->drawText(0, 0, QString("Page %1").arg(pageNumber));
    pageNumber += 1;
}

void MainWindow::print(QPrinter *printer) {

    // ------------------ simplest example --------------------------

    QPainter painter;
    if(!painter.begin(printer)) {
        //qWarning() << "can't start printer";
        return;
    }
    // print table
    TablePrinter tablePrinter(&painter, printer);
    QVector<QString> headers = QVector<QString>() << "Date" << "Student ID" << "Degree"<< "Name"<< "Room Number"<< "Leaving Time"<< "Reason"<< "Return Time"<< "Taxi" << "Place"<< "Temperature"<< "Duration" ;
    QVector<int> columnStretch = QVector<int>() << 2 << 2 << 1 << 1 << 1 << 1 << 2 << 1 << 1 << 2 << 1 << 1;
    if(!tablePrinter.printTable(ui->tableView->model(), columnStretch,headers)) {
        //qDebug() << tablePrinter.lastError();
    }
    painter.end();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(875,650);
    ui->widget_2->resize(167,167);

    ui->comboBox->addItem("PhD");
    ui->comboBox->addItem("Master");
    ui->comboBox->addItem("Bachelor");

    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("DESKTOP-N9TEHFO\\SQLEXPRESS");
    db.setDatabaseName("mydsn");

    //db = new Database("maincon");
    if(db.open())
    {
        model = new QSqlTableModel(this);

        model = new QSqlTableModel(this);
        model->setTable("Student");
        model->select();

        ui->tableView->setModel(model);
    }

//    db = QSqlDatabase::database();
//    db.close();
//    QSqlDatabase::removeDatabase("maincon");
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();

}


void print(QPrinter *printer)
{

}

void print_two_tables(QPrinter *printer)
{

}

void uglyPrint(QPrinter *printer)
{

}


void MainWindow::on_AddButton_clicked()
{
    AddStudentForm form;
    form.setModal(true);
    form.exec();
}

void MainWindow::on_printButton_clicked()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_reloadButton_clicked()
{
    if(db.open())
    {
        model = new QSqlTableModel(this);

        model = new QSqlTableModel(this);
        model->setTable("Student");
        model->select();

        ui->tableView->setModel(model);
    }
}

void MainWindow::on_resetButton_clicked()
{
    if(db.open())
    {
        QString sQuery = "DELETE FROM [Test].[dbo].[Student]";

        QSqlQuery query;
        query.prepare(sQuery);

        int reply = QMessageBox::question(this, "Question", "Do you want to delete all data from the table", QMessageBox ::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
                if(query.exec())
                {
                          QMessageBox::information(this, "Information", "Form reset!");
                }

         }
    }
}

void MainWindow::on_actionNew_Window_triggered()
{
    AddStudentForm form;
    form.setModal(true);
    form.exec();
}

void MainWindow::on_actionReload_triggered()
{
    if(db.open())
    {
        model = new QSqlTableModel(this);

        model = new QSqlTableModel(this);
        model->setTable("Student");
        model->select();

        ui->tableView->setModel(model);
    }
}

void MainWindow::on_actionPrint_triggered()
{
    QPrintPreviewDialog dialog;
    connect(&dialog, SIGNAL(paintRequested(QPrinter*)), this, SLOT(print(QPrinter*)));
    dialog.exec();
}

void MainWindow::on_actionReset_triggered()
{
    if(db.open())
    {
        QString sQuery = "DELETE FROM [Test].[dbo].[Student]";

        QSqlQuery query;
        query.prepare(sQuery);

        int reply = QMessageBox::question(this, "Question", "Do you want to delete all data from the table", QMessageBox ::Yes | QMessageBox::No);

        if (reply == QMessageBox::Yes)
        {
                if(query.exec())
                {
                          QMessageBox::information(this, "Information", "Form reset!");
                }

         }
    }
}

void MainWindow::on_actionAbout_triggered()
{
    About dialog;
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_pushButton_6_clicked()
{
    About dialog;
    dialog.setModal(true);
    dialog.exec();
}

void MainWindow::on_uploadFileButton_clicked()
{
    FileUploadDialog fileUpload;
    fileUpload.setModal(true);
    fileUpload.exec();
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    //to show students with the same degree in a Dialog

    QMessageBox::information(this, "Information", arg1);
}
