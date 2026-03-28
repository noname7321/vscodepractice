#define GLFW_DLL
#include <GLFW/glfw3.h>

#include <iostream>

// GLFW 的错误回调函数，用来打印库内部报错信息。
static void errorCallback(int errorCode, const char* description)
{
	std::cerr << "GLFW error " << errorCode << ": " << description << std::endl;
}

int main()
{
	// 先注册错误回调，后面初始化失败时更容易看到原因。
	glfwSetErrorCallback(errorCallback);

	// 初始化 GLFW，失败就直接退出。
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		std::cout << "Press Enter to exit..." << std::endl;
		std::cin.get();
		return 1;
	}

	// 创建一个 640x480 的窗口。
	GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW DLL Demo", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cerr << "Failed to create window" << std::endl;
		glfwTerminate();
		std::cout << "Press Enter to exit..." << std::endl;
		std::cin.get();
		return 1;
	}

	// 把当前 OpenGL 上下文绑定到这个窗口上。
	glfwMakeContextCurrent(window);

	// 主循环：窗口没关闭之前一直刷新画面并处理事件。
	while (!glfwWindowShouldClose(window))
	{
		// 设置清屏颜色，然后清空颜色缓冲区。
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// 交换前后缓冲，显示刚才绘制的内容。
		glfwSwapBuffers(window);

		// 处理键盘、鼠标、窗口关闭等事件。
		glfwPollEvents();
	}

	// 释放窗口资源并终止 GLFW。
	glfwDestroyWindow(window);
	glfwTerminate();
	std::cout << "Press Enter to exit..." << std::endl;
	std::cin.get();
	return 0;
}
