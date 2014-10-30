#include "Quest.h"
#include "mainFace.h"
bool QuestScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("back.png",
		"back.png", this,
		menu_selector(QuestScene::menuCloseBack));
	pCloseItem->setScale(0.5f);
	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- pCloseItem->getContentSize().height/4));

	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 13);

	return true;
}

cocos2d::CCScene* QuestScene::scene()
{
	CCScene *scene = CCScene::create();
	QuestScene *layer = QuestScene::create();
	scene->addChild(layer);
	return scene;
}

void QuestScene::menuCloseBack( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(MainGaneScene::scene());
}

