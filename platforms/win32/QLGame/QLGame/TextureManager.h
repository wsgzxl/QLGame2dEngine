/**


* 作者：weixin:wsgzxl

* 日期：2015.3.19

  TextureManager类有FreeImage中得来的，是提供的针对opengl的例子，
  但是FreeImage读取的图片的RGB顺序和OpenGL的渲染顺序不一致，导致了
  有些颜色不对，在这儿我已经更正过来了！
**/ 

#ifndef TextureManager_H
#define TextureManager_H

#include <windows.h>
#include <glut.h>
#include <string>
#include "FreeImage.h"
#include <map>
#include <vector>
#include <string>

//GLBITMAP结构体 
typedef struct   
    {  
    int         w;//图片的宽
    int             h;//图片的高
    unsigned char           *buf;//图片的数据  
    GLuint          rgb_mode;//rgb模式
    }GLBITMAP; 

typedef struct
{
	float width;
	float heigth;
}ImageSize;//图片的尺寸

class TextureManager
{	
public:
	static TextureManager* Inst();
	virtual ~TextureManager();

	//载入贴图
	GLuint LoadTexture(std::string filename,	//where to load the file from
					//does not have to be generated with glGenTextures
	    ImageSize* imagesize,//image size
		GLenum image_format = GL_RGB,		//format the image is in
		GLint internal_format = GL_RGB,		//format to store the image in
		GLint level = 0,					//mipmapping level
		GLint border = 0);					//border size

	//释放内存
	bool UnloadTexture(std::string texID);

	//释放所有的内存
	void UnloadAllTextures();

protected:
	
	TextureManager();
	TextureManager(const TextureManager& tm);
	TextureManager& operator=(const TextureManager& tm);
	GLBITMAP* FIBitmap2GLBitmap(FIBITMAP *fibmp);
	void FreeGLBitmap(GLBITMAP *glbmp);
	static TextureManager* m_inst;
	std::map<std::string, GLuint> m_texID;

private:
	bool exist(std::string filename,GLuint* texid);//检查此图片是否已经存在
};

#endif