#include "Input.h"

double Mouse::X = 0;
double Mouse::Y = 0;

bool Mouse::button[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonPress[GLFW_MOUSE_BUTTON_LAST] = { 0 };
bool Mouse::buttonUp[GLFW_MOUSE_BUTTON_LAST] = { 0 };

bool Keyboard::key[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keyPress[GLFW_KEY_LAST] = { 0 };
bool Keyboard::keyUp[GLFW_KEY_LAST] = { 0 };


void Mouse::CursorCall(GLFWwindow* window ,double RX,double RY)
{

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	X = RX;
	Y = height - RY;



}

void Mouse::MouseKeyCall(GLFWwindow* window,int Button,int state,int mod)
{
	if(button < 0)
	{
		return;
	}
	if (state != GLFW_RELEASE && button[Button] == false) 
	{
		buttonPress[Button] = true;
		buttonUp[Button] = false;
	}
	else if (state == GLFW_RELEASE && button[Button] == true) 
	{
		buttonPress[Button] = false;
		buttonUp[Button] = true;
	}

	button[Button] = state != GLFW_RELEASE;

}



double Mouse::getCursorX()
{

	return X;
}
double Mouse::getCursorY()
{

	return Y;
}
bool Mouse::ButtonPress(int Button)
{

	bool i = buttonPress[Button];
	buttonPress[Button] = false;
	return i;
}
bool Mouse::ButtonUP(int Button)
{

	bool i = buttonUp[Button];
	buttonUp[Button] = false;
	return i;
}
bool Mouse::Button(int Button)
{

	return button[Button];
}



void Keyboard::KeyCall(GLFWwindow* window, int k, int scan, int state, int mod)
{
	if (k < 0)
	{
		return;
	}
	if (state != GLFW_RELEASE && key[k] == false)
	{
		keyPress[k] = true;
		keyUp[k] = false;
	}
	else if (state == GLFW_RELEASE && key[k] == true)
	{
		keyPress[k] = false;
		keyUp[k] = true;
	}

	key[k] = state != GLFW_RELEASE;


}
bool Keyboard::KeyPress(int k) 
{
	bool i = keyPress[k];
	keyUp[k] = false;
	return i;
}
bool Keyboard::KeyUp(int k)
{

	bool i = keyUp[k];
	keyUp[k] = false;
	return i;
}
bool Keyboard::Key(int k)
{
	bool i = key[k];
	return i;

}