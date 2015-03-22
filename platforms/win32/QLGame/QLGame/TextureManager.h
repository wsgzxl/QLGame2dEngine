/**


* ���ߣ�weixin:wsgzxl

* ���ڣ�2015.3.19

  TextureManager����FreeImage�е����ģ����ṩ�����opengl�����ӣ�
  ����FreeImage��ȡ��ͼƬ��RGB˳���OpenGL����Ⱦ˳��һ�£�������
  ��Щ��ɫ���ԣ���������Ѿ����������ˣ�
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

//GLBITMAP�ṹ�� 
typedef struct   
    {  
    int         w;//ͼƬ�Ŀ�
    int             h;//ͼƬ�ĸ�
    unsigned char           *buf;//ͼƬ������  
    GLuint          rgb_mode;//rgbģʽ
    }GLBITMAP; 

typedef struct
{
	float width;
	float heigth;
}ImageSize;//ͼƬ�ĳߴ�

class TextureManager
{	
public:
	static TextureManager* Inst();
	virtual ~TextureManager();

	//������ͼ
	GLuint LoadTexture(std::string filename,	//where to load the file from
					//does not have to be generated with glGenTextures
	    ImageSize* imagesize,//image size
		GLenum image_format = GL_RGB,		//format the image is in
		GLint internal_format = GL_RGB,		//format to store the image in
		GLint level = 0,					//mipmapping level
		GLint border = 0);					//border size

	//�ͷ��ڴ�
	bool UnloadTexture(std::string texID);

	//�ͷ����е��ڴ�
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
	bool exist(std::string filename,GLuint* texid);//����ͼƬ�Ƿ��Ѿ�����
};

#endif