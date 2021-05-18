#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cctype>
#include <filesystem>

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

    // Copy the image file to the /home/jason/.icons folder
    std::string imageCopyLocation = homedir;
    std::string copyFileName = (std::string)name.toUtf8().constData() + ".png";

    imageCopyLocation += "/.icons/" + copyFileName;

    std::string copyFromLocation = iconLocation.toUtf8().constData();

    std::ifstream imageSource(copyFromLocation, std::ios::binary);
    std::ofstream imageDestination(imageCopyLocation, std::ios::binary);

    imageDestination << imageSource.rdbuf();

    // Create the applications folder if it doesn't already exist
    // /home/jason/Applications
    std::string appsFolder = homedir;
    appsFolder += "/Applications";

    // If the folder doesn't exist, create it.
    if (std::filesystem::is_directory(appsFolder)
            || std::filesystem::exists(appsFolder)) {
        std::filesystem::create_directory(appsFolder);
    }

    // Copy the application file to the Application folder
    copyFromLocation = appLocation.toUtf8().constData();
    std::string copyToLocation = appsFolder + "/" + getFilePath(appLocation.toUtf8().constData());

    std::ifstream appSource(copyFromLocation, std::ios::binary);
    std::ofstream appDestination(copyToLocation, std::ios::binary);

    appDestination << appSource.rdbuf();

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
    fileContents += "Name=" + (std::string)name.toUtf8().constData() + "\n"; // Name=AppAdder
    fileContents += "Exec=" + copyToLocation + "\n"; //Exec=/home/jason/Applications/app.AppImage
    fileContents += "Terminal=" + terminal + "\n"; // Terminal=false
    fileContents += "Type=Application\n";
    fileContents += "Icon=" + copyFileName + "\n"; // Icon=/home/jason/.icons/app.png
    fileContents += "\nTryExec=" + copyToLocation + "\n"; // TryExec=/home/jason/Applications/app.AppImage

    fileContents += "\n[Desktop Action Remove]\n";
    fileContents += "Name=Uninstall app from system\n";
    fileContents += "Exec=rm " + copyToLocation + " " + imageCopyLocation + "\n";
}

