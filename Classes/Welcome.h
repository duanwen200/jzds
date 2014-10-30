#ifndef __WELCOME_H__
#define __WELCOME_H__

#include "cocos2d.h"

USING_NS_CC;

class WelcomeLayer :public cocos2d::CCLayer
{
public:
	virtual bool init();

	static cocos2d::CCScene* scene();

	CREATE_FUNC(WelcomeLayer);
	void toGame(CCObject* pSender);
protected:
private:
};
#endif //__WELCOME_H__