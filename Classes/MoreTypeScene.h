#ifndef __MORETYPE_SCENE_H__
#define __MORETYPE_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "Game4Key.h"
#include "Game5Key.h"
#include "Game6Key.h"
#include "Common.h"

#include "SelectSong1.h"
#include "cocos-ext.h"

#include "Box2D/Box2D.h"
USING_NS_CC;

class MoreTypeScene : public cocos2d::CCLayer
{
protected:
	CCParticleSystem*    m_emitter;

public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();  

	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();

	// a selector callback
	void menuCloseCallback(CCObject* pSender);

	void toGame4Layer(CCObject* pSender);
	void toGame5Layer(CCObject* pSender);
	void toGame6Layer(CCObject* pSender);
	void tempGameLayer(CCObject* pSender) ;

	// implement the "static node()" method manually
	CREATE_FUNC(MoreTypeScene);
};
#endif