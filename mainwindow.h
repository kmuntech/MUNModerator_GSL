#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include "globals.h"
#include <QFile>
#include <QTextStream>
#include <QListWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionOpen_2_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_actionStart_Calling_Speakers_triggered();

    void on_listWidget_2_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_actionSave_triggered();

    void on_actionAbout_triggered();

    void on_actionOpen_General_Speakers_List_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
