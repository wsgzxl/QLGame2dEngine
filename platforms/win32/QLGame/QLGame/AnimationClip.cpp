#include "AnimationClip.h"


AnimationClip::AnimationClip(float timeinterval)
{
	_currentframe=0;
	_framecount=0;
	_timeinterval=timeinterval;
	_timeclock=0;
	_animationlist.clear();
}


AnimationClip::~AnimationClip(void)
{
	
}

/*
   Ìí¼ÓSpriteBatch¾²Ì¬¾«Áé
*/
void AnimationClip::AddSpriteBatch(SpriteBatch* spritebatch)
{
	_animationlist.push_back(spritebatch);
	_framecount++;
}

void AnimationClip::Update(float time)
{
	_timeclock+=time;
	if(_timeclock>_timeinterval)
	{
		_timeclock-=_timeinterval;
		_currentframe=(++_currentframe)%_framecount;

	}
}

void AnimationClip::Draw()
{
	_animationlist[_currentframe]->Draw();
}