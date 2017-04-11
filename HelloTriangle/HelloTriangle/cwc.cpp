#include "cwc.h"
#include <fstream>

using namespace std;

 unsigned long glShaderManager::getFileLength(ifstream& file)
{
	if (!file.good()) return 0;

	unsigned long pos = file.tellg();
	file.seekg(0, ios::end);
	unsigned long len = file.tellg();
	file.seekg(ios::beg);

	return len;
}

int glShaderManager::loadshader(char* filename, GLchar** ShaderSource)
{
	unsigned long* len = new unsigned long();
	ifstream file;
	file.open(filename, ios::in); // opens as ASCII!
	if (!file) return -1;

	*len = getFileLength(file);

	if (*len == 0) return -2;   // Error: Empty File 

	*ShaderSource = (GLchar*)new char[*len + 1];
	if (*ShaderSource == 0) return -3;   // can't reserve memory

	// len isn't always strlen cause some characters are stripped in ascii read...
	// it is important to 0-terminate the real length later, len is just max possible value... 
	*ShaderSource[*len] = 0;

	unsigned int i = 0;
	while (file.good())
	{
		*ShaderSource[i] = file.get();       // get character from file.
		if (!file.eof())
			i++;
	}

	*ShaderSource[i] = 0;  // 0-terminate it at the correct position

	file.close();

	return 0; // No Error
}


int glShaderManager::unloadshader(GLubyte** ShaderSource)
{
	if (*ShaderSource != 0)
		delete[] * ShaderSource;
	*ShaderSource = 0;
	return 0;
}

GLuint* glShaderManager::loadfromFile(char* filename1, char* filename2)
{
	GLuint* programObject;
	if (filename1 == NULL || filename2 == NULL)
	{
		return 0;
	}

	GLchar** VertexShaderSource = new GLchar*();
	GLchar** FragmentShaderSource = new GLchar*();
	loadshader(filename1, VertexShaderSource);
	loadshader(filename2, FragmentShaderSource);
	if (*VertexShaderSource == NULL && *FragmentShaderSource == NULL)
	{
		return 0;
	}

	if ((programObject = glCompilerAndLink::DoCompilerAndLink(*VertexShaderSource, *FragmentShaderSource)) == 0)
	{
		return 0;
	}
	return programObject;


	
}

 GLuint*  glCompilerAndLink::DoCompilerAndLink(GLchar* VertexShaderSource, GLchar* FragmentShaderSource)
{
	 if (VertexShaderSource == NULL || FragmentShaderSource == NULL)
	 {
		 return 0;
	 }

	 GLuint *shaderProgram = NULL;
	 *shaderProgram = glCreateProgram();


	 GLuint vertexShader, fragmentShader;

	 //添加一个vertexShader
	 vertexShader = glCreateShader(GL_VERTEX_SHADER);
	 fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	 glShaderSource(vertexShader, 1, &VertexShaderSource, NULL);
	 glCompileShader(vertexShader);
	//vertexShader验证是否编译成功
	 GLint success;
	 GLchar infoLog[512];
	 glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	 if (!success)
	 {
		 glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		 printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED",infoLog);
		 return 0;
	 }

	 //添加一个FragmentShader
	 glShaderSource(fragmentShader, 1, &FragmentShaderSource, NULL);
	 glCompileShader(fragmentShader);
	 glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	 if (!success)
	 {
		 glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		 printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED", infoLog);
		 return 0;
	 }

	 glAttachShader(*shaderProgram, vertexShader);
	 glAttachShader(*shaderProgram, fragmentShader);
		
	 return shaderProgram;

}