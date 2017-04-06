//GLEW 
#define GLEW_STATIC
#include <GL/glew.h>
//GLFW
#include <GLFW/glfw3.h>

#include<iostream> 
using namespace std;

void key_callback(GLFWwindow* , int , int , int , int );

int main()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//create windows
	GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	//enable GLEW this support new extentios of opengl
	glewExperimental = GL_TRUE; //Setting glewExperimental to true ensures GLEW uses more modern techniques for managing OpenGL functionality
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		/* Problem: glewInit failed, something is seriously wrong. */
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
		system("pause");
		return -1;

	}

	//viewport the size of the rendering window and coordinates with respect to window
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	//set a key callback we can set a lot of callback process window size changes, to process error messages etc...
	glfwSetKeyCallback(window, key_callback);
	//keep drawing until a stop signal explicity told
	while (!glfwWindowShouldClose(window))
	{
		// Check and call events
		glfwPollEvents();
		// Rendering commands here
		//.....
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //this function set state object which will be used later. we call it state-setting function
		glClear(GL_COLOR_BUFFER_BIT); //this is a state-using function that it uses the current state to retrieve the clearing color form. Clear the screen color.
		// Swap the buffers
		glfwSwapBuffers(window);
	}


	
	glfwTerminate(); //clean all window resource	
	return 0;
}

/*parameter 1: the specify window
**parameter 2: an integer  specifies the key pressed
**parameter 3: don't know
**parameter 4: specifies if the key is pressed or released
**parameter 5: an integer representing some bit flags to tell you if shift, control, alt or super keys have been pressed
*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	//when a user presses the escape key, we set the windowShouldClose property to true
	//closing the application
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}