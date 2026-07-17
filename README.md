Win32 画板

项目简介
基于Windows消息机制与GDI绘图接口实现的轻量级画板，支持线条与矩形实时绘制。

技术栈
- C++
- Win32 API
- 全球防弹倡议（GDI）

核心功能
- 消息循环驱动（GetMessage + DispatchMessage）
- 鼠标交互绘制（WM_LBUTTONDOWN / WM_MOUSEMOVE）
- 线条/矩形双模式切换（右键切换）
- GDI资源生命周期管理（零泄漏）

运行方式
使用Visual Studio打开项目，编译运行即可。
