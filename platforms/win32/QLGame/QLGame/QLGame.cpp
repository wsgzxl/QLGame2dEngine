#include "TextureManager.h"
#include <glut.h>
GLuint textures[1];
//��ʾ�ص�����
void renderScreen(void){
	//��������������Ϊ��ǰ������ɫ���Ϲϳ�
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,800,600);
	glMatrixMode( GL_PROJECTION );  
    glLoadIdentity(); 
	glOrtho(-400,400,-300,300,-100,100);
	glClearColor(0,0,1,0);
	glEnable(GL_TEXTURE_2D);
	glEnable (GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);    // �����˲�
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);    // �����˲�
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

	//��ʼ��glut
	glutInit(&argc,argv);
	//��������
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA);
	//�������ڣ���������ΪWindowDemo
	glutCreateWindow("QLGameEngine");
	//���ô��ڴ�С
	glutReshapeWindow(800,600);
	Init();
	 //������ʾ�ص�����  
    glutDisplayFunc(renderScreen); 
	glutMainLoop();
	return 0;
}