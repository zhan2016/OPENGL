#ifndef CIRCLE_H
#define CIRCLE_H


#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <fstream>
//你的代码写在这里
class glShader;
class glCompilerAndLink;

class glShaderManager
{

	private:
	unsigned long getFileLength(std::ifstream& file); //getFileLength
	int loadshader(char* filename, GLchar** ShaderSource); //load shader
	int unloadshader(GLubyte** ShaderSource); //unload shader

	public:
		GLuint* loadfromFile(char* filename1, char* filename2); //load多个文件
};

class glCompilerAndLink
{
public:static GLuint*  DoCompilerAndLink(GLchar* VertexShaderSource, GLchar* FragmentShaderSource);
};

#endif //防止重复编译 固定格式 zwj 20170411