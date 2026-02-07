#ifndef CHAT_H
#define CHAT_H

#include <QMainWindow>
#include <QTcpSocket>

namespace Ui {
class Chat;
}

class Chat : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chat(QTcpSocket * s,QWidget *parent = nullptr);
    ~Chat();

private slots:
    void on_clearBtn_clicked();

    void on_sendBtn_clicked();

private:
    Ui::Chat *ui;
    QTcpSocket * Socket;
};

#endif // CHAT_H
