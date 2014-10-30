#ifndef __QUEST_H__
#define __QUEST_H__


#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;
class QuestScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	CREATE_FUNC(QuestScene);
	static cocos2d::CCScene* scene();

	void menuCloseBack(CCObject* pSender);
protected:
private:
};
#endif