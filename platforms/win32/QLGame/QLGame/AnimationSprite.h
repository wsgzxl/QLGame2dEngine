#pragma once
#include "SpriteBatch.h"
#include <vector>
class AnimationSprite
{
public:
	AnimationSprite(void);
	~AnimationSprite(void);
	void AddSpriteBatch(SpriteBatch* spritebatch);
	void Play();//��ʼ���Ŷ���
private:
	int _currentframe;//��ǰ֡
	int _framecount;//����֡������
};

