#include "Window.h"
#include <mutex>
Photon::Window::Window::Window()
{
    std::call_once(this->glInited, []() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
        }
    });
}

void Photon::Window::Window::InitGlWindow(int width, int height, char* title)
{
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window == nullptr) {
        // TODO:这里要加入窗口创建错误的处理代码
    }
}
void Photon::Window::Window::Show()
{
    InitGlWindow(680,480,"fuck");
}
void Photon::Window::Window::MsgLoop()
{
    while (glfwWindowShouldClose(window)) {}
    // TODO:这里通知各个组件即将关闭窗口了
}