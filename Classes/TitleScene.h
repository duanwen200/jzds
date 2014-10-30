#ifndef __TITLESCENE_H__
#define __TITLESCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class TitleScene : public cocos2d::CCLayerColor
{
public:

	virtual bool init();
	CREATE_FUNC(TitleScene);
	static cocos2d::CCScene* scene();

	void addPhysical(CCObject* pSender);
	void addGold(CCObject* pSender);
	void addDiamone(CCObject* pSender);
	void menuCloseBack(CCObject* pSender);
	void userInfo(CCObject* pSender);
	//void setCallbackFunc(CCObject* target, SEL_CallFuncN callfun);



protected:
private:
	//CCObject* m_callbackListener;
	//SEL_CallFuncN m_callback;
};
#endif