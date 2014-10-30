#include "RankScene.h"
#include "Game4Key.h"
#include "UseItems.h"
#include "mainFace.h"
bool ChuangguanScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}


	speedNum = 1;
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSprite* bgsprite = CCSprite::create("login_2.png");
	bgsprite->setAnchorPoint(CCPointZero);
	bgsprite->setPosition(ccp(origin.x,origin.y));
	addChild(bgsprite,10);


	CCSprite* bg2sprite = CCSprite::create("chuangguanbg2.png");
	bg2sprite->setAnchorPoint(CCPointZero);
	bg2sprite->setPosition(ccp(origin.x + visibleSize.width*2/5,origin.y+ visibleSize.height/4));
	bg2sprite->setScaleY(1.2f);
	addChild(bg2sprite,11);


	CCSprite* songbgsprite = CCSprite::create("chuangguantest.png");
	songbgsprite->setAnchorPoint(ccp(0,1));
	songbgsprite->setPosition(ccp(bg2sprite->getPositionX() + bg2sprite->getContentSize().width/8,bg2sprite->getPositionY()+bg2sprite->getContentSize().height));
	addChild(songbgsprite,12);

	CCSprite* buttonSprite = CCSprite::create("start.png");
	SEL_MenuHandler startSelect= (SEL_MenuHandler)menu_selector(ChuangguanScene::startGame);
	CCMenuItemSprite* startMenu = CCMenuItemSprite::create(buttonSprite,
		buttonSprite, buttonSprite, this,
		startSelect );
	CCMenu* menu = CCMenu::create(startMenu,NULL);
	menu->setPosition(ccp(origin.x+visibleSize.width*4/5,origin.y+visibleSize.height/6));
	menu->setScale(0.5f);
	menu->setAnchorPoint(ccp(0,0));
	addChild(menu,13);

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("back.png",
		"back.png", this,
		menu_selector(ChuangguanScene::menuCloseCallback));

	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- pCloseItem->getContentSize().height/2));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 13);

	return true;
}

cocos2d::CCScene* ChuangguanScene::scene()
{

	CCScene *scene = CCScene::create();
	ChuangguanScene *layer = ChuangguanScene::create();
	scene->addChild(layer);
	return scene;
}

void ChuangguanScene::startGame( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(UserItems::scene());
}

void ChuangguanScene::menuCloseCallback( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(MainGaneScene::scene());
}

