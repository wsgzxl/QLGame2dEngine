
#include "SpriteBatch.h"
#include "glut.h"
SpriteBatch::SpriteBatch(void)
{
	texid=-1;
	rgb=-1;
	_angle=-180;
	Vector3 v;
	v.v1=0;v.v2=0;v.v3=0;
	SetPosition(v);
	_scale=1;
}
SpriteBatch::~SpriteBatch(void)
{
	glDeleteTextures(1,&texid);
}

SpriteBatch::SpriteBatch(std::string filename,Rect* rect)
{
	new (this) SpriteBatch();
	_rect=rect;
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
		glTranslatef(position.v1,position.v2,position.v3);
		glScalef(_scale,_scale,_scale);
		glRotatef(_angle,0,0,1);
		glBegin(GL_POLYGON); 
		if(texid==-1)return;
		float v0x=0.0f;
		float v0y=0.0f;
		float v1x=1.0f;
		float v1y=1.0f;
		float width=imagesize.width;
		float height=imagesize.heigth;
		if(_rect!=NULL)
		{
			v0x=_rect->v0x/width;
			v0y=_rect->v0y/height;
			v1x=_rect->v1x/width;
			v1y=_rect->v1y/height;
			width=_rect->v1x-_rect->v0x;
			height=_rect->v1y-_rect->v0y;
		}
		glTexCoord2d(v0x,v0y);glVertex2f(-width/2, -height/2);  
		glTexCoord2d(v0x,v1y);glVertex2f(-width/2, height/2);  
		glTexCoord2d(v1x,v1y);glVertex2f(width/2, height/2);  
		glTexCoord2d(v1x,v0y);glVertex2f(width/2, -height/2); 
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

void SpriteBatch::SetPosition(Vector3 position)
{
	this->position=position;
}

void SpriteBatch::Rotate(float angle)
{
	_angle=-180+angle;
}

Vector3 SpriteBatch::GetPosition()
{
	return position;
}

void SpriteBatch::Scale(float scale)
{
	_scale=scale;
}

float SpriteBatch::GetScale()
{
	return _scale;
}