/**
Jogo das Cores
@author Gabriela de Campos Trevisan
*/

#include "Game.h"
#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <GLFW/glfw3.h>
const int W = 1004;
const int H = 650;

Game game;
double lastX = 0, lastY = 0;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, W, H, 0.0, 0.0, 1.0);
	glRasterPos2f(10,615);
	glPixelZoom(1.0f, -1.0f);
}

void render() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	game.start();
	glFlush();
}

void redimensionar(GLFWwindow *window, int w, int h) 
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, W, H, 0.0, 0.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void tratarTeclado(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_R && action == GLFW_PRESS) game.reset();
}

static void tratarPosMouse(GLFWwindow* window, double xpos, double ypos)
{
	lastX = xpos;
	lastY = ypos;	
}

void tratarMouse(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		game.play(lastX, lastY);
	}
}

int CALLBACK WinMain(
	__in  HINSTANCE hInstance,
	__in  HINSTANCE hPrevInstance,
	__in  LPSTR lpCmdLine,
	__in  int nCmdShow
) {
	GLFWwindow* window;
	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(W, H, "Jogo das Cores", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetWindowSizeCallback(window, redimensionar);
	glfwSetKeyCallback(window, tratarTeclado);
	glfwSetCursorPosCallback(window, tratarPosMouse);
	glfwSetMouseButtonCallback(window, tratarMouse);
	
	init();

	while (!glfwWindowShouldClose(window) && glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS)
	{		
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}