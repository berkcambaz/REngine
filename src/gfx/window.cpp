#include "window.h"

namespace ren {

	namespace gfx {

		bool Window::m_Keys[MAX_KEYS];
		bool Window::m_MouseButtons[MAX_BUTTONS];
		double Window::m_mx, Window::m_my;

		void window_resize(GLFWwindow* window, int width, int height);

		Window::Window(int width, int height, const char* title) {
			m_Width = width;
			m_Height = height;
			m_Title = title;

			if (!init())
				glfwTerminate();

			for (bool& i : m_Keys)
				i = false;
			for (bool& i : m_MouseButtons)
				i = false;
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
			if (!m_Window) {
				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			//glfwSetWindowUserPointer(m_Window, this);
			glfwSetWindowSizeCallback(m_Window, window_resize);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);

			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
				std::cout << "Failed to initialize GLAD!" << std::endl;
				return false;
			}

			return true;
		}

		bool Window::isKeyPressed(unsigned int keycode) const {
			if (keycode >= MAX_KEYS)
				return false;
			return m_Keys[keycode];
		}

		bool Window::isMouseButtonPressed(unsigned int button)const {
			if (button >= MAX_BUTTONS)
				return false;
			return m_MouseButtons[button];
		}

		void Window::getMousePosition(double& x, double& y) const {
			x = m_mx;
			y = m_my;
		}

		void Window::clear() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update() {
			GLenum error = glGetError();
			if (error != GL_NO_ERROR)
				std::cout << "OpenGL Error: " << error << std::endl;

			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::closed() const {
			return glfwWindowShouldClose(m_Window);
		}

		void window_resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}

		void Window::key_callback(GLFWwindow* window, int key, int keycode, int action, int mods) {
			//Window* win = (Window*)glfwGetWindowUserPointer(window);
			//win->
			m_Keys[key] = action != GLFW_RELEASE;
		}

		void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
			//Window* win = (Window*)glfwGetWindowUserPointer(window);
			//win->
			m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos) {
			m_mx = xpos;
			m_my = ypos;
		}

	}

}