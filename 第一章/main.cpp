// 包含自定义Widget类的头文件，用于创建主窗口对象
#include "widget.h"
// 包含QApplication类的头文件，Qt GUI应用程序的核心类
// 负责应用程序的初始化、事件循环、资源管理和退出
#include <QApplication>

// C++程序的入口函数，argc是命令行参数个数，argv是命令行参数数组
int main(int argc, char *argv[])
{
    // 创建QApplication应用程序对象，传入命令行参数
    // Qt会解析这些参数来处理一些全局选项（如显示风格、调试信息等）
    QApplication a(argc, argv);
    
    // 创建自定义的Widget主窗口对象，此时窗口还未显示
    // 父对象为nullptr，表示这是一个顶级窗口
    Widget w;
    
    // 显示主窗口，将窗口及其子组件渲染到屏幕上
    // 默认情况下窗口是隐藏的，必须显式调用show()方法
    w.show();
    
    // 启动应用程序的事件循环，进入阻塞状态
    // 事件循环会不断接收并分发用户输入、系统消息等事件
    // 直到调用QApplication::quit()或关闭所有顶级窗口才会返回
    return a.exec();
}
