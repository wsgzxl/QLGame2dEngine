#pragma once
#include <Windows.h>
#include <ctime>
#include <iostream>
/*
   author: weixin wsgzxl
   ����:֡����ʾ
   2015.3.20
*/
typedef void (*pfunc)(void);
class FPS
{
public:
	FPS(void);
	~FPS(void);
	void ShowFps(bool showflag);//�Ƿ���ʾfps
	int getframefps();//��ȡÿ����ʾ�˶���֡
	void Start();//��ʼ��ʱ
	void Stop();//ֹͣ��ʱ
	void Update();//����
	void CallBack(pfunc func);//�ص�
	void ReStart();
	DWORD gettick();
private:
	bool show;//�Ƿ���ʾfps;
	bool _start;//�Ƿ�ʼ��ʱ;
	DWORD _starttime;//��ʼʱ��
	DWORD _starttimecopy;
	int _framecount;//֡��
	pfunc _pfunc;//�ص�����
};

