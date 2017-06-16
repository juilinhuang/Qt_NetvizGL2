#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QDir>
#include <QMessageBox>
#include <QDebug>
#include <QKeyEvent>
#include <QSet>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    connect(ui->pushButton, SIGNAL(clicked(bool), ui->widget, );

//    QSet<int> set;
//    set.insert(1);
//    qDebug() << set.contains("aaa");
//    set.insert(2);
//    qDebug() << set.size();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    ui->widget->terminateThread();
}

void MainWindow::on_pushButton_clicked()
{
    ui->widget->terminateThread();
//    QString file = "D:/Qt_project/NetvizGL2/Graphs/EdgeLinks/degreetest.txt";
    QString file = QFileDialog::getOpenFileName(this, "choose a file", "D:/Qt_project/NetvizGL2/Graphs", "All (*.*);; Text (*.txt);; Matrix (*.mtx)");
//    QMessageBox::information(this, "Path", file);
//    setFocus();
    char *p = new char[file.toStdString().size()];
    strcpy(p, file.toStdString().c_str());
    qDebug() << p;
    ui->widget->setPath(p);
    ui->widget->test("1");
    ui->radioButton->setChecked(true);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->widget->test("1");
}

void MainWindow::on_radioButton_clicked()
{
    ui->widget->test("1");
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->widget->test("2");
}

void MainWindow::on_radioButton_3_clicked()
{
    ui->widget->test("3");
}
