#include "Engine.h"
#include <iostream>
#include "Input/Input.h"

int Engine::SCR_Width = 1920;
int Engine::SCR_Height = 1080;
GLFWwindow* Engine::window = NULL;
float Engine::deltaTime = 0;

Engine::Engine() 
{
	
}
Engine::~Engine()
{
}
bool Engine::init(char* winName)
{
	if (!glfwInit())
	{
		std::cout <<"Fail" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	//add error check;
	window = glfwCreateWindow(SCR_Width, SCR_Height, winName, NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return false;
	}

	//OpenGL Init and setup
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	//double buffer
	glfwSwapInterval(1);

	//view 
	glViewport(0, 0, width, height);


	glfwSetCursorPosCallback(window, Mouse::CursorCall);
	glfwSetMouseButtonCallback(window, Mouse::MouseKeyCall);
	glfwSetKeyCallback(window, Keyboard::KeyCall);

	//centre window to screen
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	int xPos = (mode->width - SCR_Width);
	int yPos = (mode->height - SCR_Height);
	glfwSetWindowPos(window, xPos, yPos);

	
	//Add option for GL_PROJECTION for 2D game?? 
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	////set left to right depth may need to be changed depending on game
	//glOrtho(0, width,0,height,-100,10000);
	//glDepthRange(-100, 100);
	//glMatrixMode(GL_MODELVIEW);
	////Allows transparency?? may only work for sprites
	//glEnable(GL_ALPHA_TEST);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	lastFT = glfwGetTime();
	return true;
}
void Engine::update()
{
	float currentFT = glfwGetTime();
	deltaTime = currentFT - lastFT;
	lastFT = currentFT;
	glfwPollEvents();
}

void Engine::render()
{
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Render Loop

	glfwSwapBuffers(window);
}

void Engine::NextFrame()
{
	glfwSwapBuffers(window);
}
void Engine::ClearSc()
{
	glClearColor(0, 0, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
float Engine::getdeltaTime()
{
	return deltaTime;
}