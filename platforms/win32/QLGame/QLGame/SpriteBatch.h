#pragma once
#include "Core.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;
/*
   ���������
*/
class SpriteBatch
{
public:
	SpriteBatch(void);
	//����ͼƬ
	SpriteBatch(const char* filename);
	~SpriteBatch(void);
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	void Draw();//��Ⱦ
	void Update(float time);
private:
	Vector3 position;//λ��
	GLuint texid;//texid
	ImageSize imagesize;
	unsigned int rgb;
	float m;

};

