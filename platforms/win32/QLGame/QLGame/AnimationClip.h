/*
atuhor weixin wsgzxl
2015.3.22
�������� 
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
	int _currentframe;//��ǰҪ���ŵ�֡
	int _framecount;//��֡��
	float _timeinterval;//ʱ�����л�����
	vector<SpriteBatch*> _animationlist;//�����б�
	float _timeclock;
};

