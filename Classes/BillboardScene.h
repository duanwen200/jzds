#ifndef __BILLBOARD_H__
#define __BILLBOARD_H__


#include "cocos2d.h"
#include "cocos-ext.h"
using namespace cocos2d;
using namespace cocos2d::extension;


class BillboardScene : public cocos2d::CCLayer
{
public:
	BillboardScene();
	~BillboardScene();
	virtual bool init();
	CREATE_FUNC(BillboardScene);
	virtual void registerWithTouchDispatcher(void);
	bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
	static BillboardScene* create(const char* backgroundImage);


	CC_SYNTHESIZE_RETAIN(CCSprite*, m__sfBackGround, SpriteBackGround);
	void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);


	void buttonCallback(CCObject* pSender);
	void pauseaction(CCObject * sender,CCControlEvent);
	CCObject* m_callbackListener;
	SEL_CallFuncN m_callback;



	virtual void onEnter();
	virtual void onExit();
protected:
private:
};
#endif