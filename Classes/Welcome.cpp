#include "Welcome.h"


bool WelcomeLayer::init()
{

	if (!CCLayer::init()) {
		return false;
	}




	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("login.plist", "login.png");


	CCSprite* QQeButton = CCSprite::createWithSpriteFrameName(
		"qq.png");
	CCSprite* WeixinButton = CCSprite::createWithSpriteFrameName(
		"weixin.png");
	CCSprite* playQQ = CCSprite::createWithSpriteFrameName("23.png");
	QQeButton->setScaleX(1.5f);
	QQeButton->setScaleY(0.5f);
	WeixinButton->setScaleX(1.5f);
	WeixinButton->setScaleY(0.5f);
	SEL_MenuHandler QQselect= (SEL_MenuHandler)menu_selector(WelcomeLayer::toGame);
	SEL_MenuHandler Weixinselect= (SEL_MenuHandler)menu_selector(WelcomeLayer::toGame);
	CCMenuItemSprite* QQMenu = CCMenuItemSprite::create(QQeButton,
		QQeButton, QQeButton, this,
		QQselect );
	CCMenuItemSprite* WeixinMenu = CCMenuItemSprite::create(WeixinButton,
		WeixinButton, WeixinButton, this,
		Weixinselect );
	CCMenu* menu = CCMenu::create(QQMenu, WeixinMenu,
		NULL);
	menu->alignItemsHorizontally();
	this->addChild(menu, 1);
	menu->setPosition(ccp(origin.x + visibleSize.width/2,
		origin.y + visibleSize.height/2));
	return true;
}

cocos2d::CCScene* WelcomeLayer::scene()
{
	CCScene *scene = CCScene::create();

	WelcomeLayer *layer = WelcomeLayer::create();

	scene->addChild(layer);

	return scene;
}

void WelcomeLayer::toGame( CCObject* pSender )
{

}

