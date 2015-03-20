/**


* 作者：weixin:wsgzxl

* 日期：2014-3-21 11:16:42
  
  win入口类
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

//渲染模块
void renderScreen(void){
	//把整个窗口清理为当前清理颜色：南瓜橙
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.2f,0.5f,0,0);
	sprite->Draw();
	//spriteb->Draw();
	glutSwapBuffers();
	//cout << "render scene!" << endl;
}

//回调
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
	spriteb=new SpriteBatch("C://项目盘//游戏引擎//qlgame//platforms//win32//QLGame//Debug//1.jpg");
	sprite=new SpriteBatch("C://项目盘//游戏引擎//qlgame//platforms//win32//QLGame//Debug//xm_01.png");
}

//main入口
int main(int argc, char* argv[])
{
	//初始化glut
	glutInit(&argc,argv);
	//单缓冲区
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//创建窗口，窗口名字为WindowDemo
	glutCreateWindow("QL2DGameEngine");
	//设置窗口大小
	glutReshapeWindow(800,600);
	Init();
	glutIdleFunc(Update);
	//设置显示回调函数  
	glutDisplayFunc(renderScreen); 
	printf("opengl version:%s",glGetString(GL_VERSION));
	glutMainLoop();
	return 0;
}