#pragma once
#include "Core.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;
/*
   精灵绘制类
*/
class SpriteBatch
{
public:
	SpriteBatch(void);
	//载入图片
	SpriteBatch(const char* filename);
	~SpriteBatch(void);
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	void Draw();//渲染
	void Update(float time);
private:
	Vector3 position;//位置
	GLuint texid;//texid
	ImageSize imagesize;
	unsigned int rgb;
	float m;

};

