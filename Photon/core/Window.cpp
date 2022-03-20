#include "Window.h"
Photon::Window::Window::Window()
{
	
}
int Photon::Window::Window::fps()
{
	static int fps = 0;
	static int lastTime = this->clock.time_since_epoch().count(); // ms
	static int frameCount = 0;
	++frameCount;
	int curTime = this->clock.time_since_epoch().count();
	if (curTime - lastTime > 1000) // 取固定时间间隔为1秒
	{
		fps = frameCount;
		frameCount = 0;
		lastTime = curTime;
	}
	return fps;
}
void Photon::Window::Window::InitGlWindow(int width, int height, char *title)
{
	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == nullptr)
	{
		// TODO:这里要加入窗口创建错误的处理代码
	}
}
void Photon::Window::Window::Show() { InitGlWindow(680, 480, "fuck"); }
void Photon::Window::Window::MsgLoop()
{
	while (glfwWindowShouldClose(window))
	{
		//这里是获取事件呢
		

		std::cout << "当前fps为" << fps() << std::endl;
	}
	// TODO:这里通知各个组件即将关闭窗口了
}