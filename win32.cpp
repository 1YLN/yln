#include <Windows.h>

bool isDrawing = false;// 是否正在绘制
POINT startPoint;// 起始点

//窗口过程函数声明
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static HDC hdc;//画布
	static HPEN hpen;//画笔
	static int drawMode = 0;
	
	switch (uMsg) {
	case WM_CREATE:
		hpen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));//画笔创建
		break;		
	case WM_RBUTTONDOWN://按下鼠标右键
		drawMode =! drawMode;
		if (drawMode == 1) {
			SetWindowText(hwnd, L"矩形模式(右键切换)");
		}
		else {
			SetWindowText(hwnd, L"线条模式(右键切换)");
		}
		break;
	case WM_LBUTTONDOWN://按下鼠标左键
		isDrawing = true;
		startPoint.x = LOWORD(lParam);//低位x
		startPoint.y = HIWORD(lParam);//高位y
		break;
	case WM_MOUSEMOVE://鼠标移动
		if (isDrawing) {
			POINT currentPoint;//更新鼠标位置
			currentPoint.x = LOWORD(lParam);
			currentPoint.y = HIWORD(lParam);
			hdc = GetDC(hwnd);
			SelectObject(hdc, hpen);
			if (drawMode == 1) {
				Rectangle(hdc, startPoint.x, startPoint.y,currentPoint.x, currentPoint.y);//矩形绘制
			}
			else {
				MoveToEx(hdc, startPoint.x, startPoint.y, NULL);//移动画笔位置
				LineTo(hdc, currentPoint.x, currentPoint.y);//绘线
				startPoint = currentPoint;
			}
			ReleaseDC(hwnd, hdc);
		}
		break;
	case WM_LBUTTONUP://鼠标左键抬起
		isDrawing = false;
		break;
	case WM_DESTROY:
		DeleteObject(hpen);// 释放画笔资源
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam); //处理未处理的消息
	}
	return 0;
}
//类似于main
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPreInstance,LPSTR lpCmdLine,int nShowCmd) {
	//注册窗口
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("win");
	RegisterClass(&wc);
	//创建窗口
	HWND hwnd = CreateWindowEx(0, TEXT("win"), TEXT("win32画板(右键切换模式)"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, NULL, NULL, hInstance, NULL);
	if (!hwnd)return 0;
	//显示更新窗口
	ShowWindow(hwnd, nShowCmd);
	UpdateWindow(hwnd);
	//循环获取消息
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);//翻译消息
		DispatchMessage(&msg);//分发消息
	}
	return 0;
}