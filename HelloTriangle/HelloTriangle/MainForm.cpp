#include "cwc.h"


int main()
{
	glShaderManager SM;
	GLuint* ProgramShader = SM.loadfromFile("D:\\Դ����\\OpenGLProject\\HelloTriangle\\HelloTriangle\\Debug\\vertexshader.txt", "D:\\Դ����\\OpenGLProject\\HelloTriangle\\HelloTriangle\\Debug\\fragmentshader.txt");
	system("pause");
}