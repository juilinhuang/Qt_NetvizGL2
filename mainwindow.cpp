#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QSet>
#include <QColor>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qDebug() << "close";
    ui->widget->terminateThread();
}

void MainWindow::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this,
                                                "choose a file",
                                                "D:/Qt_project/NetvizGL2 - Copy/Graphs",
                                                "All (*.*);; Text (*.txt);; Matrix (*.mtx)");
    if(!file.isEmpty()){
        char *p = new char[file.toStdString().size()];
        strcpy(p, file.toStdString().c_str());
        ui->widget->loadGraph(p);
        ui->radioButton->setChecked(true);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QColor color;
    color = QColorDialog::getColor(Qt::white, this);
    qDebug() << "RGB ( " << color.red() << ", " << color.green() << ", " << color.blue() << " )";
    ui->widget->setSelectedVertexColour(color.red(), color.green(), color.blue());
}

void MainWindow::on_radioButton_clicked()
{
    ui->widget->changeAlgorithm("1");
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->widget->changeAlgorithm("2");
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->widget->changeAlgorithm("3");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->widget->degreeC();
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->widget->distanceC();
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->widget->betweennessC();
}
