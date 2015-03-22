#pragma once
#include "Core.h"
#include "TextureManager.h"
#include <iostream>
#include <string>
using namespace std;
/*
   精灵绘制类
*/
class SpriteBatch
{
public:
	SpriteBatch(void);
	//载入图片
	SpriteBatch(std::string filename,Rect* rect=NULL
		);
	~SpriteBatch(void);
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	void Draw();//渲染
	void Update(float time);
	void Rotate(float angle);//旋转angle度
	void Scale(float scale);//缩放
	float GetScale();//获取缩放值
private:
	Vector3 position;//位置
	float _angle;//当前的角度
	GLuint texid;//texid
	ImageSize imagesize;
	unsigned int rgb;
	float _scale;//缩放
	Rect* _rect;//矩形范围
};

