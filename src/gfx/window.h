#pragma once

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ren {

	namespace gfx {

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

		class Window {
		private:
			const char* m_Title;
			int m_Width, m_Height;
			GLFWwindow* m_Window;

			static bool m_Keys[MAX_KEYS];
			static bool m_MouseButtons[MAX_BUTTONS];
			static double m_mx, m_my;
		public:
			Window(int width, int height, const char* title);
			~Window();

			void clear();
			void update();
			bool closed() const;

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }

			bool isKeyPressed(unsigned int keycode) const;
			bool isMouseButtonPressed(unsigned int button) const;
			void getMousePosition(double& x, double& y) const;
		private:
			bool init();

			static void key_callback(GLFWwindow* window, int key, int keycode, int action, int mods);
			static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		};

	}

}