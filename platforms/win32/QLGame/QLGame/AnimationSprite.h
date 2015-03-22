#pragma once
#include "SpriteBatch.h"
#include <vector>
class AnimationSprite
{
public:
	AnimationSprite(void);
	~AnimationSprite(void);
	void AddSpriteBatch(SpriteBatch* spritebatch);
	void Play();//开始播放动画
private:
	int _currentframe;//当前帧
	int _framecount;//动画帧的数量
};

