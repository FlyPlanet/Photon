#include "Window.h"
Photon::Window::Window::Window() {
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
int Photon::Window::Window::fps() {
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
void Photon::Window::Window::InitGlWindow(int width, int height, char *title) {
  window = glfwCreateWindow(width, height, title, NULL, NULL);

  if (window == nullptr) {
    // TODO:这里要加入窗口创建错误的处理代码
  }
}
void Photon::Window::Window::Show() { InitGlWindow(680, 480, "fuck"); }
void Photon::Window::Window::MsgLoop() {
  while (glfwWindowShouldClose(window)) {
    //这里是获取事件呢

    //这里加入事件通知
    //窗口要做的啊，直接通知组件就好了

    std::cout << "当前fps为" << fps() << std::endl;
  }
  // TODO:这里通知各个组件即将关闭窗口了
}