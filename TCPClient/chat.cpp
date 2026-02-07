#include "chat.h"
#include "ui_chat.h"

Chat::Chat(QTcpSocket * s,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Chat)
{
    ui->setupUi(this);
    Socket = s;
}

Chat::~Chat()
{
    delete ui;
}

void Chat::on_clearBtn_clicked()
{
    ui->lineEdit->clear();
}


void Chat::on_sendBtn_clicked()
{
    QByteArray ba;
    ba.append(ui->lineEdit->text().toUtf8());
    Socket->write(ba);
}

