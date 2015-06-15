#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Curr_Comm_FileName.clear();
    ui->label->setAlignment(Qt::AlignHCenter);
    ui->label_2->setAlignment(Qt::AlignHCenter);
    ui->label_3->setAlignment(Qt::AlignHCenter);
    ui->label_5->setAlignment(Qt::AlignHCenter);
    ui->label_6->setAlignment(Qt::AlignHCenter);
    ui->label_7->setAlignment(Qt::AlignHCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_2_triggered()
{
    while(ui->listWidget->count()>0)
    {
        ui->listWidget->takeItem(0);
    }
    while(ui->listWidget_2->count()>0)
    {
        ui->listWidget_2->takeItem(0);
    }
    Curr_Comm_FileName=QFileDialog::getOpenFileName(this,tr("Open File..."),"D://");
    QFile Curr_File(Curr_Comm_FileName);
    Curr_File.open( QIODevice::ReadOnly);
    QTextStream Curr_File_Stream(&Curr_File);
    QMessageBox::information(this,tr("info"),Curr_Comm_FileName);
    while(!Curr_File_Stream.atEnd())
    {
        QString speaker = Curr_File_Stream.readLine();
        QListWidgetItem *i;
        i=new QListWidgetItem;
        i->setText(speaker);
        ui->listWidget->addItem(i);
    }
    ui->actionOpen_General_Speakers_List->setEnabled(true);
    ui->label_5->setText("Total = "+QString::number(ui->listWidget->count()));
    ui->label_6->setText("Total = "+QString::number(ui->listWidget_2->count()));
}

void MainWindow::on_pushButton_clicked()
{
    QListWidgetItem *i,*j;
    j=new QListWidgetItem;
    i=ui->listWidget->currentItem();
    j->setText(i->text());
    ui->listWidget_2->addItem(j);
    ui->label_5->setText("Total = "+QString::number(ui->listWidget->count()));
    ui->label_6->setText("Total = "+QString::number(ui->listWidget_2->count()));
}

void MainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem *i;
    i=new QListWidgetItem;
    i=ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    delete i;
    if(ui->listWidget_2->count()==0)
    {
        ui->actionStart_Calling_Speakers->setEnabled(true);
        ui->pushButton_3->setEnabled(false);
    }
    ui->label_5->setText("Total = "+QString::number(ui->listWidget->count()));
    ui->label_6->setText("Total = "+QString::number(ui->listWidget_2->count()));
}

void MainWindow::on_actionStart_Calling_Speakers_triggered()
{
    ui->pushButton_3->setEnabled(true);
    Curr_Speaker=0;
    ui->actionStart_Calling_Speakers->setEnabled(false);
}

void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{
    Curr_Speaker = ui->listWidget_2->row(item);
    ui->label_7->setText(QString::number(Curr_Speaker)+" Speakers Completed");
    ui->label_4->setText("");
}

void MainWindow::on_pushButton_3_clicked()
{
    QListWidgetItem *i;
    i=new QListWidgetItem;
    if(ui->listWidget_2->count()>Curr_Speaker)
    {
        i=ui->listWidget_2->item(Curr_Speaker);
        Curr_Speaker++;
        ui->label_4->setText(i->text());
        ui->label_4->setAlignment(Qt::AlignHCenter);
        ui->label_7->setText(QString::number(Curr_Speaker)+" Speakers Completed");
    }
    else
    {
        QMessageBox::about(this,tr("Error"),"All Speakers Completed!");
    }

}

void MainWindow::on_actionSave_triggered()
{
    QString Save_FileName = QFileDialog::getSaveFileName(this,tr("Save File..."),"D://");
    QFile Curr_File(Save_FileName);
    Curr_File.open( QIODevice::WriteOnly);
    QTextStream Curr_File_Stream(&Curr_File);
    for(int i=0;i<ui->listWidget_2->count();i++)
    {
        QListWidgetItem *j;
        j=ui->listWidget_2->item(i);
        Curr_File_Stream<<j->text()<<"\n";
    }
    Curr_File.flush();
    Curr_File.close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,tr("About..."),"Developed by KMUN 2015 Tech Team");
}

void MainWindow::on_actionOpen_General_Speakers_List_triggered()
{
    while(ui->listWidget_2->count()>0)
    {
        ui->listWidget_2->takeItem(0);
    }
    Curr_Comm_FileName=QFileDialog::getOpenFileName(this,tr("Open File..."),"D://");
    QFile Curr_File(Curr_Comm_FileName);
    Curr_File.open( QIODevice::ReadOnly);
    QTextStream Curr_File_Stream(&Curr_File);
    QMessageBox::information(this,tr("info"),Curr_Comm_FileName);
    while(!Curr_File_Stream.atEnd())
    {
        QString speaker = Curr_File_Stream.readLine();
        QListWidgetItem *i;
        i=new QListWidgetItem;
        i->setText(speaker);
        ui->listWidget_2->addItem(i);
    }
    ui->label_5->setText("Total = "+QString::number(ui->listWidget->count()));
    ui->label_6->setText("Total = "+QString::number(ui->listWidget_2->count()));
}
