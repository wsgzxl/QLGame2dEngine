/*
atuhor weixin wsgzxl
2015.3.22
动画剪辑 
*/
#pragma once
#include <string>
#include "SpriteBatch.h"
#include <vector>
using namespace std;
class AnimationClip
{
public:
	AnimationClip(float timeinterval);
	~AnimationClip(void);
	void AddSpriteBatch(SpriteBatch* batch);
	void Update(float time);
	void Draw();
private:
	int _currentframe;//当前要播放的帧
	int _framecount;//总帧数
	float _timeinterval;//时间间隔切换动画
	vector<SpriteBatch*> _animationlist;//动画列表
	float _timeclock;
};

