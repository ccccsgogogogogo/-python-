#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <chat.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建Socket对象
    Socket = new QTcpSocket;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_connectBtn_clicked()
{
    //获取ip地址与端口号
    QString ip = ui->ipLineEdit->text();
    QString port = ui->portLineEdit->text();
    //连接服务器
    Socket->connectToHost(QHostAddress(ip),port.toShort());
    //连接成功，Socket发出信号
    connect(Socket,&QTcpSocket::connected,[this]()
    {
        QMessageBox::information(this,"连接提示","连接服务器成功");

        this->hide();
        Chat *c = new Chat(Socket);
        c->show();
    });
    //连接成功，Socket发出信号
    connect(Socket,&QTcpSocket::disconnected,[this]()
    {
       QMessageBox::warning(this,"连接提示","连接服务器异常 网络断开");
    });
}


void MainWindow::on_cancelBtn_clicked()
{
    this->close();
}

