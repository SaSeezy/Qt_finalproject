#include "fileuploaddialog.h"
#include "ui_fileuploaddialog.h"

#include <QFileDialog>
#include <QUrl>
#include <QDebug>

FileUploadDialog::FileUploadDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileUploadDialog)
{
    ui->setupUi(this);

    m_manager = new QNetworkAccessManager(this);
    connect(m_manager, &QNetworkAccessManager::finished, this, &FileUploadDialog::uploadFinished);
}

FileUploadDialog::~FileUploadDialog()
{
    delete ui;
}

void FileUploadDialog::uploadFinished(QNetworkReply *reply)
{
    if (!reply->error())
    {
        m_file->close();
        m_file->deleteLater();
        reply->deleteLater();
    }
}

void FileUploadDialog::uploadProgress(qint64 bytesSent, qint64 bytesTotal)
{
    ui->progressBar->setValue(100 * bytesSent/bytesTotal);
}

void FileUploadDialog::on_pushButton_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this, "Get Any File");
    ui->lineEdit->setText(m_fileName);
}

void FileUploadDialog::on_pushButton_2_clicked()
{
    m_file = new QFile(m_fileName);

    QFileInfo fileInfo(*m_file);
    QUrl url(ui->lineEdit_2->text() + fileInfo.fileName());
    url.setUserName("login");
    url.setPassword("password");
    url.setPort(21);

    if (m_file->open(QIODevice::ReadOnly))
    {
        QNetworkReply *reply = m_manager->put(QNetworkRequest(url), m_file);
        connect(reply, &QNetworkReply::uploadProgress, this, &FileUploadDialog::uploadProgress);
    }

}
