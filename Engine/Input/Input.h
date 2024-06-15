#pragma once

#include <GLFW/glfw3.h>

class Mouse
{
private:
	static double X, Y;

	static bool button[];
	static bool buttonPress[];
	static bool buttonUp[];
public:

	static void CursorCall(GLFWwindow* window, double RX,double RY);
	static void MouseKeyCall(GLFWwindow* window, int Button, int state, int mod);

	static double getCursorX();
	static double getCursorY();

	static bool Button(int Button);
	static bool ButtonPress(int Button);
	static bool ButtonUP(int Button);

};

class Keyboard
{
private:

	static bool key[];
	static bool keyPress[];
	static bool keyUp[];


public:
	static void KeyCall(GLFWwindow* window, int k, int scan, int state, int mod);
	static bool Key(int key);
	static bool KeyPress(int key);
	static bool KeyUp(int key);
	
	
	


};
