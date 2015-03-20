
#include "SpriteBatch.h"
#include "glut.h"
SpriteBatch::SpriteBatch(void)
{
	texid=-1;
	rgb=-1;
	m=0;
}
SpriteBatch::~SpriteBatch(void)
{
	glDeleteTextures(1,&texid);
}

SpriteBatch::SpriteBatch(const char* filename)
{
	new (this) SpriteBatch();
	std::string file(filename);
	rgb=-1;
	std::string extend;
	extend=file.substr(file.length()-3,3);
	if(extend=="png")
	{
		rgb=GL_RGBA;
	}
	else 
	{
		rgb=GL_RGB;
	}
	texid=TextureManager::Inst()->LoadTexture(filename,&imagesize,rgb,rgb);
}

void SpriteBatch::Draw()
{
	//printf("texid:%d\n",texid);
	glBindTexture(GL_TEXTURE_2D,texid);
	//printf("%d\r\n",glGetError());
	//printf("%s\r\n",gluErrorString(glGetError()));
	if(rgb==GL_RGBA)
	{
		glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glPushMatrix();
		glTranslatef(0,0,0);
		m+=1.5f;
		glRotatef(m,0,0,1);
		glBegin(GL_POLYGON); 
		if(texid==-1)return;
		glTexCoord2d(0,0);glVertex2f(-imagesize.width/2, -imagesize.heigth/2);  
		glTexCoord2d(0,1);glVertex2f(-imagesize.width/2, imagesize.heigth/2);  
		glTexCoord2d(1,1);glVertex2f(imagesize.width/2, imagesize.heigth/2);  
		glTexCoord2d(1,0);glVertex2f(imagesize.width/2, -imagesize.heigth/2); 
		glEnd();
		glDisable(GL_BLEND);
		glPopMatrix();
	}
	else
	{
		glBegin(GL_POLYGON); 
		if(texid==-1)return;
	    glTexCoord2d(0,0);glVertex2f(-imagesize.width/2, -imagesize.heigth/2);  
		glTexCoord2d(0,1);glVertex2f(-imagesize.width/2, imagesize.heigth/2);  
		glTexCoord2d(1,1);glVertex2f(imagesize.width/2, imagesize.heigth/2);  
		glTexCoord2d(1,0);glVertex2f(imagesize.width/2, -imagesize.heigth/2); 
		glEnd();
	}
}

void SpriteBatch::Update(float time)
{

}