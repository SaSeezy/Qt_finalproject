#ifndef FILEUPLOADDIALOG_H
#define FILEUPLOADDIALOG_H

#include <QDialog>
#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QString>
#include <QFile>


namespace Ui {
class FileUploadDialog;
}

class FileUploadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FileUploadDialog(QWidget *parent = nullptr);
    ~FileUploadDialog();

private slots:
    void uploadFinished(QNetworkReply *reply);
    void uploadProgress(qint64 bytesSent, qint64 bytesTotal);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FileUploadDialog *ui;
    QNetworkAccessManager *m_manager;
    QString m_fileName;
    QFile *m_file;
};

#endif // FILEUPLOADDIALOG_H
