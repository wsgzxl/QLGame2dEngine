/**


* 作者：weixin:wsgzxl

* 日期：2014-3-21 11:16:42

  结构体
**/
#include "SpriteBatch.h"
//顶点类型
typedef struct vector3
{
	float v1;//x
	float v2;//y
	float v3;//z
}Vector3;

typedef struct rect
{
	float v0x;//左上角的顶点x值
	float v0y;//左上角的顶点y值
	float v1x;//右下角的顶点x值
	float v1y;//右下角的顶点y值
}Rect;

