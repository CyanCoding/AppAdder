#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

char *homedir;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Get the user's home directory, like '/home/jason'
    struct passwd *pw = getpwuid(getuid());
    homedir = pw->pw_dir;
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_locateIcon_clicked() {
    QString selectedIcon = QFileDialog::getOpenFileName(this, "Choose Icon", homedir, "PNG Image (*.png)");

    // Sets the icon box to the icon's file location
    ui->iconBox->setText(selectedIcon);
}


void MainWindow::on_locateApp_clicked() {
    QString selectedApp = QFileDialog::getOpenFileName(this, "Choose App", homedir);

    // Sets the icon box to the icon's file location
    ui->appBox->setText(selectedApp);
}

