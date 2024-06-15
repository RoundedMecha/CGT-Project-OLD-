#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>


class Engine 
{
private:
	static GLFWwindow* window;
	static float deltaTime;
	float lastFT;
public:
	//note change later to allow change in res
	static int SCR_Width;
	static int SCR_Height;
	static float getdeltaTime();
	//
	Engine();
	~Engine();

	void update();
	void render();

	void ClearSc();
	void NextFrame();

	bool init(char* winName);
};