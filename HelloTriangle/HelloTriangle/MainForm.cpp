#include "cwc.h"


int main()
{
	glShaderManager SM;
	GLuint* ProgramShader = SM.loadfromFile("D:\\源代码\\OpenGLProject\\HelloTriangle\\HelloTriangle\\Debug\\vertexshader.txt", "D:\\源代码\\OpenGLProject\\HelloTriangle\\HelloTriangle\\Debug\\fragmentshader.txt");
	system("pause");
}