#ifndef __CHUANGGUAN_SCENE_H__
#define __CHUANGGUAN_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;


class ChuangguanScene : public cocos2d::CCLayer
{
public:
	virtual bool init();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(ChuangguanScene);

	void startGame(CCObject* pSender);
	void addPhysical(CCObject* pSender);
	void speed(CCObject* pSender);
	void menuCloseCallback(CCObject* pSender);
protected:
private:
	int speedNum;
	CCLabelTTF* username;
	CCLabelTTF* Physical;
	CCLabelTTF* gold;
	CCLabelTTF* Diamond;
	CCLabelTTF* level;
};
#endif