#ifndef __PAUSE_SCENE_H__
#define __PAUSE_SCENE_H__


#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;

class PauseScene:public CCLayer
{
public:
	PauseScene();
	~PauseScene();
	virtual bool init();
	CREATE_FUNC(PauseScene);
	virtual void registerWithTouchDispatcher(void);
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	static PauseScene* create(const char* backgroundImage);

	virtual void onEnter();
	virtual void onExit();


	CC_SYNTHESIZE_RETAIN(CCSprite*, m__sfBackGround, SpriteBackGround);

	void buttonCallback(CCObject* pSender);
	void pauseaction(CCObject * sender,CCControlEvent);
	CCObject* m_callbackListener;
	SEL_CallFuncN m_callback;
	void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);
protected:
private:
};
#endif