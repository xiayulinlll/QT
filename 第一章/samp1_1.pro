# ==============================================
# Qt qmake构建系统项目配置文件 (.pro)
# 该文件定义了项目的构建规则、依赖模块、源文件和部署规则
# qmake会根据此文件生成对应的Makefile文件
# ==============================================

# --------------------------
# 1. Qt模块依赖配置
# QT变量用于指定项目需要链接的Qt功能模块
# 每个模块对应Qt的一个功能库，会自动处理头文件路径和库链接
# --------------------------
# 添加Qt核心模块(core)和基础图形界面模块(gui)
# core模块：所有Qt程序必须依赖，提供信号与槽、事件循环、字符串处理、文件IO等基础功能
# gui模块：提供图形界面的基础框架，如窗口系统、事件处理、绘图等
QT       += core gui

# 条件判断：如果Qt主版本号大于4（即Qt5及以上版本），则额外添加widgets模块
# 重要说明：Qt4中所有控件都包含在gui模块中；Qt5开始将传统桌面控件拆分为独立的widgets模块
# 此写法保证项目可以同时兼容Qt4、Qt5和Qt6版本
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# --------------------------
# 2. 编译配置选项
# CONFIG变量用于设置全局构建配置，影响编译器和链接器行为
# --------------------------
# 指定使用C++11标准进行编译
# Qt5.5及以上默认支持C++11，Qt6默认要求C++17标准
# 如需更高标准可改为c++14、c++17或c++20
CONFIG += c++11

# --------------------------
# 3. 废弃API控制
# DEFINES变量用于定义C/C++预处理器宏
# --------------------------
# 以下行取消注释后，将禁用所有在Qt 6.0.0版本之前被标记为废弃(deprecated)的API
# 作用：强制使用最新的Qt API，避免使用即将被移除的旧功能，提高代码的可维护性和未来兼容性
# 0x060000是Qt版本的十六进制表示：0xMMNNPP（主版本.次版本.补丁版本）
# 例如：0x050F00对应Qt5.15.0，0x060200对应Qt6.2.0
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# --------------------------
# 4. 项目源文件列表
# qmake会自动扫描这些文件并生成对应的编译规则
# --------------------------
# C++源文件列表（.cpp文件）
# 每个源文件会被单独编译为目标文件(.o)，最终链接到可执行程序
SOURCES += \
    main.cpp \
    widget.cpp

# C++头文件列表（.h文件）
# 包含自定义类的声明，Qt的moc工具会扫描这些文件处理Q_OBJECT宏
HEADERS += \
    widget.h

# Qt Designer界面文件列表（.ui文件）
# 这些文件会在编译前被uic(User Interface Compiler)工具自动转换为C++头文件ui_xxx.h
FORMS += \
    widget.ui

# --------------------------
# 5. 部署配置
# 定义程序在不同平台上的安装路径
# 执行make install命令时会将编译生成的可执行文件复制到指定路径
# --------------------------
# Default rules for deployment.
# QNX平台：将可执行文件安装到/tmp/[目标名]/bin目录
qnx: target.path = /tmp/$${TARGET}/bin
# 其他Unix平台（Linux、macOS等）且不是Android平台：安装到/opt/[目标名]/bin目录
else: unix:!android: target.path = /opt/$${TARGET}/bin
# 如果设置了target.path，则将target添加到安装列表中
!isEmpty(target.path): INSTALLS += target
