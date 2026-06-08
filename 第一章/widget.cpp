// 包含当前类的头文件
#include "widget.h"
// 包含自动生成的ui_widget.h头文件
// 这个文件是由uic工具在编译时根据widget.ui文件生成的
// 包含了Ui::Widget类的完整定义
#include "ui_widget.h"

// Widget类构造函数的实现
// 使用初始化列表调用父类QWidget的构造函数，并初始化ui指针
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    // 在堆上创建Ui::Widget类的对象
    , ui(new Ui::Widget)
{
    // 调用setupUi方法，传入this指针（当前Widget对象）
    // 这个方法会完成以下工作：
    // 1. 创建界面上所有的组件对象
    // 2. 设置组件的属性（如大小、位置、文本、字体等）
    // 3. 建立组件之间的信号与槽连接（如果在Qt Designer中设置了）
    // 4. 将所有组件添加到当前Widget窗口中
    ui->setupUi(this);
}

// Widget类析构函数的实现
Widget::~Widget()
{
    // 释放Ui::Widget对象占用的内存
    // 避免内存泄漏
    delete ui;
}
