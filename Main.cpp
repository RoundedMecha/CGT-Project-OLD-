#include "Engine/Engine.h"
#include "Engine/Graphics/Shaders/Shader.h"
#include "Engine/Input/Input.h"
#include "Engine/Graphics/Model.h"

int main() 
{
	Engine Engine;
	if (Engine.init((char*)"Name"))
	{
		glm::vec3 c(0, 0, 0);

	
		


		Model m("");
		Shader ourShader("Assets/Shader/ShaderTest.vs", "Assets/Shader/FragTest.fs");
		ourShader.use();
	

		while (true)
		{
			Engine.update();

			
	
			if (Mouse::Button(GLFW_MOUSE_BUTTON_LEFT))
			{
				
			}
			if (Mouse::ButtonPress(GLFW_MOUSE_BUTTON_RIGHT))
			{

			}
			if (Keyboard::Key(GLFW_KEY_W))
			{
				
			}
			if (Keyboard::KeyPress(GLFW_KEY_A))
			{

			}
			if (Keyboard::KeyUp(GLFW_KEY_D))
			{

			}
			if (Keyboard::KeyPress(GLFW_KEY_ESCAPE))
			{
				return(0);
			}

			Engine.ClearSc();

			
			Engine.NextFrame();

		}
	}
}