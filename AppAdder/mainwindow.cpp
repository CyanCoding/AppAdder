#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Buttons
    ui->locateIcon->setText("..!");
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_locateIcon_clicked() {
    // Get the user's home directory, like '/home/jason'
    struct passwd *pw = getpwuid(getuid());
    const char *homedir = pw->pw_dir;

    QString selectedIcon = QFileDialog::getOpenFileName(this, "Choose Icon", homedir, "PNG Image (*.png)");

    // Sets the icon box to the icon's file location
    ui->iconBox->setText(selectedIcon);
}

