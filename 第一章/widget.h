// 头文件保护宏，防止头文件被重复包含
#ifndef WIDGET_H
#define WIDGET_H

// 包含QWidget类的头文件，所有Qt界面组件的基类
// 提供窗口的基本功能，如绘制、事件处理、布局管理等
#include <QWidget>

// Qt命名空间开始标记，用于避免命名冲突
QT_BEGIN_NAMESPACE
// 前向声明Ui命名空间中的Widget类
// 这个类是由Qt的uic工具根据widget.ui文件自动生成的
// 包含了界面上所有组件的定义和初始化代码
namespace Ui { class Widget; }
// Qt命名空间结束标记
QT_END_NAMESPACE

// 自定义Widget类，继承自QWidget
class Widget : public QWidget
{
    // Q_OBJECT宏，Qt元对象系统的核心
    // 必须添加这个宏才能使用Qt的信号与槽、属性、动态类型转换等特性
    // 这个宏会在编译时由moc工具生成额外的元对象代码
    Q_OBJECT

public:
    // 构造函数，parent参数指定父窗口
    // 如果parent为nullptr，则创建一个顶级窗口
    // 默认参数为nullptr
    Widget(QWidget *parent = nullptr);
    
    // 析构函数，用于释放资源
    ~Widget();

private:
    // 指向自动生成的Ui::Widget类对象的指针
    // 通过这个指针可以访问界面上的所有组件
    Ui::Widget *ui;
};
// 头文件保护宏的结束
#endif // WIDGET_H
