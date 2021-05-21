#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QStandardPaths>

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>

char *homedir;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Get the user's home directory, like '/home/jason'
    struct passwd *pw = getpwuid(getuid());
    homedir = pw->pw_dir;
}

// Gets the file name from the file path
// Input: /home/jason/app.AppImage
// Output: app.AppImage
std::string getFilePath(std::string path) {
    const size_t last_slash_idx = path.find_last_of("\\/");

    if (std::string::npos != last_slash_idx) {
        path = path.erase(0, last_slash_idx + 1);
    }

    return path;
}

// Writes data to the .desktop file
void writeData(std::string data, std::string path) {
    std::ofstream file(path);

    file << data;

    file.close();
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


void MainWindow::on_createButton_clicked() {
    QString name = ui->nameBox->text();
    QString appLocation = ui->appBox->text();
    QString iconLocation = ui->iconBox->text();
    bool terminalSelected = ui->terminalCheckbox->isChecked();

    // Set the terminal string
    std::string terminal = "false";
    if (terminalSelected == true)
        terminal = "true";

    /*
     * This is the correct form for a .desktop file:
     *
     * [Desktop Entry]
     * Name=AppAdder
     * Exec=/home/jason/app.AppImage
     * Terminal=false
     * Type=Application
     * Icon=app.png
     * TryExec=/home/jason/app.AppImage
     *
     */


    std::string fileContents = "";

    fileContents += "[Desktop Entry]\n";
    fileContents += "Type=Application\n";
    fileContents += "Encoding=UTF-8\n";
    fileContents += "Name=" + (std::string)name.toUtf8().constData() + "\n"; // Name=AppAdder
    fileContents += "Comment=A simple program\n";
    fileContents += "Exec=" + (std::string)appLocation.toUtf8().constData() + "\n";
    fileContents += "Icon=" + (std::string)iconLocation.toUtf8().constData() + "\n";
    fileContents += "Terminal=" + terminal + "\n"; // Terminal=false
    fileContents += "Actions=Remove;\n";

    fileContents += "\n[Desktop Action Remove]\n";
    fileContents += "Name=Uninstall app from system\n";

    std::string desktopFilePath = homedir;
    desktopFilePath += "/.local/share/applications/" + (std::string) name.toUtf8().constData() + ".desktop";

    fileContents += "Exec=rm " + desktopFilePath + "\n";

    writeData(fileContents, desktopFilePath);
}

