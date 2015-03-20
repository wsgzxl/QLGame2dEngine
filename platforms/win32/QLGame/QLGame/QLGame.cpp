/**


* ���ߣ�weixin:wsgzxl

* ���ڣ�2014-3-21 11:16:42
  
  win�����
**/ 
#include "TextureManager.h"
#include "SpriteBatch.h"
#include "FPS.h"
#include <glut.h>
#include <iostream>
#define Width 800
#define Height 600
using namespace std;

SpriteBatch* sprite;
SpriteBatch* spriteb;
FPS* fps;
float fpsvalue=60;


void Update()
{
	fps->Update();
	float sleeptime=(1000.0f/fpsvalue-fps->gettick());
	if(sleeptime<0)sleeptime=0;
	Sleep(sleeptime);
	fps->ReStart();
	glutPostRedisplay();
}

//��Ⱦģ��
void renderScreen(void){
	//��������������Ϊ��ǰ������ɫ���Ϲϳ�
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f,0.5f,0,0);
	sprite->Draw();
	//spriteb->Draw();
	glutSwapBuffers();
	//cout << "render scene!" << endl;
}

//�ص�
void ShowFps()
{
	std::cout << "show fps" <<endl;
	printf("%d\r\n",fps->getframefps());
}

void Init()
{
	glViewport(0,0,800,600);
	glMatrixMode( GL_PROJECTION );  
	glLoadIdentity(); 
	glOrtho(-Width/2,Width/2,-Height/2,Height/2,-100,100);
	glEnable(GL_TEXTURE_2D);
	fps=new FPS();
	fps->Start();
	fps->ShowFps(true);
	fps->CallBack(&ShowFps);
	spriteb=new SpriteBatch("C://��Ŀ��//��Ϸ����//qlgame//platforms//win32//QLGame//Debug//1.jpg");
	sprite=new SpriteBatch("C://��Ŀ��//��Ϸ����//qlgame//platforms//win32//QLGame//Debug//xm_01.png");
}

//main���
int main(int argc, char* argv[])
{
	//��ʼ��glut
	glutInit(&argc,argv);
	//��������
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//�������ڣ���������ΪWindowDemo
	glutCreateWindow("QL2DGameEngine");
	//���ô��ڴ�С
	glutReshapeWindow(800,600);
	Init();
	glutIdleFunc(Update);
	//������ʾ�ص�����  
	glutDisplayFunc(renderScreen); 
	printf("opengl version:%s",glGetString(GL_VERSION));
	glutMainLoop();
	return 0;
}