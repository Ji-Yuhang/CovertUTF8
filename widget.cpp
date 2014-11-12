#include "widget.hxx"
#include "ui_widget.h"
#include <QMessageBox>
#include <QPropertyAnimation>
#include <QTimer>
#include <QLabel>
#include <QHBoxLayout>
//int MessageWidget::g_num = 0;
//MessageWidget::MessageWidget(MessageType type, const QString& title, const QString& content )
//{
//    ++g_num;
//    this->setWindowTitle(title);
//    this->resize(400,100);
//    QHBoxLayout * layout = new QHBoxLayout();
//    QLabel* label = new QLabel(content);
//    layout->addWidget(label);
//    this->setLayout(layout);

//    if (type == Information)
//        this->setStyleSheet("background-color:green;color:black;font-size:16px;");
//    else if (type == Warning)
//        this->setStyleSheet("background-color:red;color:black;font-size:16px;");

//    this->setAttribute(Qt::WA_DeleteOnClose);
//    this->setWindowFlags(Qt::FramelessWindowHint);
    
//    this->showNormal();
//    QPoint p = QCursor::pos();
//    this->setGeometry(p.x(),p.y() + g_num * this->height(),this->width(),this->height());
//    QTimer::singleShot(3000,this, SLOT(close()));

    
    
    
//}

//MessageWidget::~MessageWidget()
//{
//    --g_num;
//}
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    
    connect(ui->toutf, SIGNAL(clicked()), this, SLOT(toUtf8()));
    connect(ui->tocn, SIGNAL(clicked()), this, SLOT(toZhcn()));
    
}

Widget::~Widget()
{
    delete ui;
}

void Widget::toUtf8()
{
    QString s = ui->cn->toPlainText();
    QByteArray b = s.toUtf8();
    QByteArray h = b.toHex().toUpper();
    QByteArray w;
    for (int i = 0; i < h.size(); i += 2) {
        w.append("\\x");
        w.append(h.at(i));
        w.append(h.at(i+1));
    }
    ui->utf->setPlainText(w);
//    foreach (var, container) {
        
//    }
//    new MessageWidget(MessageWidget::Information, "I am title", "I am content");
//    QMessageBox* box = new QMessageBox(QMessageBox::Warning,"I am title","I am content");
//    QTimer::singleShot(1000,box,SLOT(accept()));
//    QPropertyAnimation ani(box, "windowOpacity");
//    ani.setDuration(1000);
//    ani.setKeyValueAt(0.0,1.0);
//    ani.setKeyValueAt(1.0,0.0);
//    ani.start();
//    box->exec();
//    box->setModal(false);
//    QEventLoop loop;
//    QTimer::singleShot(3000,&loop,SLOT(quit()));
//    loop.exec();
    
    
}

void Widget::toZhcn()
{
    QString s = ui->utf->toPlainText();
    QString ss = s.remove("\\x");

    
    QByteArray  block;
    QDataStream out(&block, QIODevice::WriteOnly);
    for (int i = 0; i < ss.size(); i= i+ 2) {
        QString mid = ss.mid(i,2);
        bool ok = false;
        quint8 bit8 = mid.toUInt(&ok,16);
        out << bit8;
    }
    QString t = QString::fromUtf8(block);
//    QByteArray b = QString::fromUtf8(ss.)
    ui->cn->setPlainText(t);
//    new MessageWidget(MessageWidget::Warning, "I am title", "I am content");
    
}
