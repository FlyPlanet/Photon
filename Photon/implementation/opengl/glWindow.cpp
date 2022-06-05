#include "glWindow.h"
//初始化static变量
Photon::Window::glWindow::glInitFlag = std::once_flag()

Photon::Window::glWindow::glWindow()
{
    //进行opengl的初始化
    std::call_once(this->glInited, []()
                   {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
      std::cout << "Failed to initialize GLAD" << std::endl;
    } });
    //TODO: 这个地方的错误管理还是需要完善的




}
Photon::Window::glWindow::~glWindow(){
    glfwTerminate();
    //销毁glfw
}
void Photon::Window::glWindow::eventForward(GLFWWindow *window){
    //这个地下就是一些关于消息处理的代码了
}
void Photon::Window::glWindow::Show(int width,int height,char[] title){
    this->window = glfwCreateWindow(width,height,title,NULL,NULL);//这个函数里面还是需要填充下的
    if(window==NULL){
        std::cout << "fail" << std::endl;
        glfwTerminate();
        //TODO:错误管理需要完善
    }
    //开始渲染循环
    while (!glfwWindowShouldClose(window)){
        //这个里面就是循环内容了
        
        //处理输入
        eventForward(window);
        //进行渲染

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}