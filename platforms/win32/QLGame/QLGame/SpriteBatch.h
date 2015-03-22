#pragma once
#include "Core.h"
#include "TextureManager.h"
#include <iostream>
#include <string>
using namespace std;
/*
   ���������
*/
class SpriteBatch
{
public:
	SpriteBatch(void);
	//����ͼƬ
	SpriteBatch(std::string filename,Rect* rect=NULL
		);
	~SpriteBatch(void);
	void SetPosition(Vector3 position);
	Vector3 GetPosition();
	void Draw();//��Ⱦ
	void Update(float time);
	void Rotate(float angle);//��תangle��
	void Scale(float scale);//����
	float GetScale();//��ȡ����ֵ
private:
	Vector3 position;//λ��
	float _angle;//��ǰ�ĽǶ�
	GLuint texid;//texid
	ImageSize imagesize;
	unsigned int rgb;
	float _scale;//����
	Rect* _rect;//���η�Χ
};

