#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Server = new QTcpServer;

    Server->listen(QHostAddress::AnyIPv4,PORT);

    //客户端发起连接，Server发出信号
    connect(Server,&QTcpServer::newConnection,this,&MainWindow::newClinetHandler);
}

void MainWindow::newClinetHandler()
{
    //建立TCP连接
    QTcpSocket * Socket = Server->nextPendingConnection();
    //Socket->peerAddress(); //获取客户端地址
    //Socket->peerPort();    //获取客户端端口

    ui->ipLineEdit->setText(Socket->peerAddress().toString());
    ui->portLineEdit->setText(QString::number(Socket->peerPort()));

    //服务器收到客户端发送的信息，Socket发送readyread信号
    connect(Socket,&QTcpSocket::readyRead,this,&MainWindow::ClientInfoSlot);
}

void MainWindow::ClientInfoSlot()
{
    //获取信号的发送者
    QTcpSocket * s = (QTcpSocket *)sender();
    ui->lineEdit->setText(QString(s->readAll()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
