#ifndef WIDGET_HXX
#define WIDGET_HXX

#include <QWidget>

namespace Ui {
class Widget;
}
//class MessageWidget : QWidget 
//{
//public:
//    enum MessageType {
//        Warning = 0,
//        Information
//    };
//    MessageWidget(MessageType type,const QString& title, const QString&  content);
//    ~MessageWidget();

//   static int g_num;
//public slots:
    
//};
class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
public slots:
    void toUtf8();
    void toZhcn();
    void gbk_to_cn();


};

#endif // WIDGET_HXX
