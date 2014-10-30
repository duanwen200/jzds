#include "TitleScene.h"


bool TitleScene::init()
{
	if (!CCLayerColor::initWithColor(ccc4(0,100,255,255)))
	{
		return false;
	}

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	this->setContentSize(CCSizeMake(visibleSize.width,visibleSize.width/12));
	//this->setAnchorPoint(ccp(0,1));
	//this->setPosition(ccp(origin.x ,origin.y + visibleSize.height));
	//CCLayerColor* layerColor = CCLayerColor::create(ccc4(0,0,255,255));
	//layerColor->setContentSize(CCSizeMake(visibleSize.width/7,visibleSize.height));
	//layerColor->setAnchorPoint(ccp(0,1));
	//layerColor->setPosition(ccp(origin.x ,origin.y + visibleSize.height));
	//this->addChild(layerColor,0);

	CCSprite* labelBG = CCSprite::create("title_1.png");
	labelBG->setContentSize(CCSizeMake(visibleSize.width/5,visibleSize.width/24));
	labelBG->setPosition(ccp( this->getPositionX()+this->getContentSize().width*2/5,this->getPositionY()+this->getContentSize().height/4));
	float p = this->getContentSize().width;
	p = this->getContentSize().height;
	labelBG->setAnchorPoint(ccp(0,1));
	this->addChild(labelBG,1);


	return true;
}

cocos2d::CCScene* TitleScene::scene()
{
	CCScene *scene = CCScene::create();
	TitleScene *layer = TitleScene::create();
	scene->addChild(layer);
	return scene;
}

void TitleScene::addPhysical( CCObject* pSender )
{

}

void TitleScene::addGold( CCObject* pSender )
{

}

void TitleScene::addDiamone( CCObject* pSender )
{

}

void TitleScene::menuCloseBack( CCObject* pSender )
{

}

void TitleScene::userInfo( CCObject* pSender )
{

}
