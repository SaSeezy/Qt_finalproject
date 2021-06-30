#include "mainwindow.h"
#include "login.h"

#include <QApplication>
#include <QSplashScreen>
#include <QThread>
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QPixmap pixmap(":/logo/Images/Logo/NPU.png");
    QSplashScreen splash(pixmap);
    splash.show();

    a.thread()->sleep(5); // wait for just 1 second and then show main window
    a.processEvents();

    MainWindow window;
    Login login;

    QTimer::singleShot(2500,&splash, &QSplashScreen::close);
    QTimer::singleShot(2500,&login, &QSplashScreen::show);
    QObject::connect(&login, &Login::adminSignal, &window, &MainWindow::show);

    return a.exec();
}
