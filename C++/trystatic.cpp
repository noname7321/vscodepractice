#define GLFW_STATIC
#include <GLFW/glfw3.h>

#include <iostream>

// GLFW 的错误回调函数，用来打印库内部报错信息。
static void errorCallback(int errorCode, const char* description)
{
    std::cerr << "GLFW error " << errorCode << ": " << description << std::endl;
}

int main()
{
    // 注册错误回调，方便排查初始化和创建窗口失败的原因。
    glfwSetErrorCallback(errorCallback);

    // 初始化 GLFW；如果失败，说明库没有正确链接或运行环境有问题。
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

    // 创建一个简单窗口。
    GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW Static Demo", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create window" << std::endl;
        glfwTerminate();
        std::cout << "Press Enter to exit..." << std::endl;
        std::cin.get();
        return 1;
    }

    // 将窗口对应的 OpenGL 上下文设为当前上下文。
    glfwMakeContextCurrent(window);

    // 进入主循环，直到用户关闭窗口。
    while (!glfwWindowShouldClose(window))
    {
        // 设置背景色并清屏。
        glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 显示这一帧画面。
        glfwSwapBuffers(window);

        // 轮询输入和窗口事件。
        glfwPollEvents();
    }

    // 收尾：销毁窗口并关闭 GLFW。
    glfwDestroyWindow(window);
    glfwTerminate();
    std::cout << "Press Enter to exit..." << std::endl;
    std::cin.get();
    return 0;
}