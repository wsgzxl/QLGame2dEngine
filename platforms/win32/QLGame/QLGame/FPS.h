#pragma once
#include <Windows.h>
#include <ctime>
#include <iostream>
/*
   author: weixin wsgzxl
   功能:帧率显示
   2015.3.20
*/
typedef void (*pfunc)(void);
class FPS
{
public:
	FPS(void);
	~FPS(void);
	void ShowFps(bool showflag);//是否显示fps
	int getframefps();//获取每秒显示了多少帧
	void Start();//开始计时
	void Stop();//停止计时
	void Update();//更新
	void CallBack(pfunc func);//回调
	void ReStart();
	DWORD gettick();
private:
	bool show;//是否显示fps;
	bool _start;//是否开始计时;
	DWORD _starttime;//开始时间
	DWORD _starttimecopy;
	int _framecount;//帧数
	pfunc _pfunc;//回调方法
};

