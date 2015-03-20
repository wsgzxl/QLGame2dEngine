#include "FPS.h"


FPS::FPS(void)
{
	this->show=false;
}
FPS::~FPS(void)
{
}

int FPS::getframefps()
{
	return _framecount;
}

void FPS::Start()
{
	if(!show) return;
	_start=true;
	_framecount=0;
	_starttime=GetTickCount();
	_starttimecopy=_starttime;
}

void FPS::ReStart()
{
	if(!show) return;
	_starttimecopy=GetTickCount();
}

DWORD FPS::gettick()
{
	return GetTickCount()-_starttimecopy;
}

void FPS::Stop()
{
	_start=false;
}

void FPS::Update()
{
	if(!show || !_start) return;
	_framecount++;
	if(GetTickCount()-_starttime>=1000)
	{
		time_t timenow;
		time_t tt = time(NULL);//这句返回的只是一个时间cuo
        tm* t= localtime(&tt);
        printf("%d-%02d-%02d %02d:%02d:%02d\n", 
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday,
            t->tm_hour,
            t->tm_min,
            t->tm_sec);
		(*_pfunc)();
		_framecount=0;
		_starttime=GetTickCount();
	}
}

void FPS::ShowFps(bool showflag)
{
	this->show=showflag;
}

void FPS::CallBack(pfunc _pfunc)
{
	this->_pfunc=_pfunc;
}