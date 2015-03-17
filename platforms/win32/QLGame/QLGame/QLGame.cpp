#include "TextureManager.h"
#include <glut.h>
GLuint textures[1];
//显示回调函数
void renderScreen(void){
	//把整个窗口清理为当前清理颜色：南瓜橙
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,800,600);
	glMatrixMode( GL_PROJECTION );  
    glLoadIdentity(); 
	glOrtho(-400,400,-300,300,-100,100);
	glClearColor(0,0,1,0);
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);    // 线性滤波
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);    // 线性滤波
	TextureManager::Inst()->BindTexture(textures[0]);
	 glBegin(GL_POLYGON); 
	 GLfloat w=100;
	 GLfloat h=100;
         glTexCoord2d(0,0);glVertex2f(-w, -h);  
        glTexCoord2d(0,1);glVertex2f(-w, h);  
        glTexCoord2d(1,1);glVertex2f(w, h);  
        glTexCoord2d(1,0);glVertex2f(w, -h); 
		glEnd();
		glDisable(GL_TEXTURE_2D);
	glFlush();
	  glutSwapBuffers();
}

void Init()
{
	TextureManager::Inst()->LoadTexture("./wg_06.png",textures[0],GL_RGBA,GL_RGBA );
	
	
}

int main(int argc, char* argv[])
{

	//初始化glut
	glutInit(&argc,argv);
	//单缓冲区
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	//创建窗口，窗口名字为WindowDemo
	glutCreateWindow("QLGameEngine");
	//设置窗口大小
	glutReshapeWindow(800,600);
	Init();
	 //设置显示回调函数  
    glutDisplayFunc(renderScreen); 
	glutMainLoop();
	return 0;
}