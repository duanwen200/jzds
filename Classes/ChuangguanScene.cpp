#include "ChuangguanScene.h"
#include "Game4Key.h"
#include "mainFace.h"
#include "Shop.h"
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


	
	level = CCLabelTTF::create("lv 1","Arial",15);
	level->setPosition(ccp(origin.x,visibleSize.height));
	level->setAnchorPoint(ccp(0,1));
	addChild(level,11,10);


	username = CCLabelTTF::create("username","Arial",15);
	username->setPosition(ccp(origin.x + 15* 5,visibleSize.height));
	username->setAnchorPoint(ccp(0,1));
	addChild(username,11,11);

	CCSprite* physicalIcon = CCSprite::create("physical.png");
	physicalIcon->setScale(0.5f);
	physicalIcon->setPosition(ccp(origin.x + visibleSize.width/2-15,visibleSize.height));
	physicalIcon->setAnchorPoint(ccp(0,1));
	addChild(physicalIcon,11,121);
	Physical = CCLabelTTF::create("500","Arial",15);
	Physical->setPosition(ccp(origin.x + visibleSize.width/2,visibleSize.height));
	Physical->setAnchorPoint(ccp(0,1));
	addChild(Physical,11,12);
	CCSprite* physicalAdd = CCSprite::create("add.png");
	//physicalAdd->setScale(0.5f);
	//physicalAdd->setPosition(ccp(origin.x + visibleSize.width/2+50,visibleSize.height));
	//physicalAdd->setAnchorPoint(ccp(0,1));
	//addChild(physicalAdd,11,122);

	//////////////////////////////////////////////////////////////////////////
	SEL_MenuHandler addPhysicalSelect= (SEL_MenuHandler)menu_selector(ChuangguanScene::addPhysical);
	CCMenuItemImage* addPhysicalMenu = CCMenuItemImage::create("add.png",
		"add.png", this,
		addPhysicalSelect );
	addPhysicalMenu->setPosition(ccp(origin.x + visibleSize.width/2+50,visibleSize.height));
	addPhysicalMenu->setAnchorPoint(ccp(1,1));
	addPhysicalMenu->setScale(0.5f);
	CCMenu* addPhysicalmenu = CCMenu::create(addPhysicalMenu,NULL);
	addPhysicalmenu->setPosition(CCPointZero);
	//addPhysicalmenu->setScale(0.5f);
	//addPhysicalmenu->setAnchorPoint(ccp(0,1));
	//addPhysicalmenu->alignItemsVertically();
	addChild(addPhysicalmenu,11,122);


	/*	Button* buttonPlay = Button::create();  
	buttonPlay->setTouchEnabled(true);  
	buttonPlay->loadTextures("add.png", "add.png", "");  
	buttonPlay->setAnchorPoint(ccp(0,1));
	buttonPlay->setScale(0.5f);
	buttonPlay->setPosition(ccp(origin.x + visibleSize.width/2+50,origin.y+visibleSize.height));  
	buttonPlay->addTouchEventListener(this, toucheventselector(MainGaneScene::addPhysical));  
	this->addChild(buttonPlay,11,122);*/  
	//////////////////////////////////////////////////////////////////////////

	gold  = CCLabelTTF::create("500","Arial",15);
	gold->setPosition(ccp(origin.x + visibleSize.width/2 + 100,visibleSize.height));
	gold->setAnchorPoint(ccp(0,1));
	addChild(gold,11,13);

	Diamond  = CCLabelTTF::create("500","Arial",15);
	Diamond->setPosition(ccp(origin.x + visibleSize.width/2 + 150,visibleSize.height));
	Diamond->setAnchorPoint(ccp(0,1));
	addChild(Diamond,11,14);

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



	CCSprite* box_1 = CCSprite::create("box_1.png");
	box_1->setPosition(ccp(visibleSize.width/5,visibleSize.height*6/8));
	box_1->setScale(0.5f);
	addChild(box_1,12);
	CCSprite* box_2 = CCSprite::create("box_2.png");
	box_2->setPosition(ccp(visibleSize.width/5,visibleSize.height*6/8 - box_1->getContentSize().height/2));
	box_2->setScale(0.5f);
	addChild(box_2,11);


	//CCSprite* speed = CCSprite::create("speedControl.png");
	//speed->setPosition(CCPointZero);
	//speed->setAnchorPoint(ccp(0,0));
	//speed->setScale(0.5f);
	//addChild(speed,12);

	SEL_MenuHandler speedSelect= (SEL_MenuHandler)menu_selector(ChuangguanScene::speed);
	CCMenuItemImage* speedMenu = CCMenuItemImage::create("speedControl.png",
		"speedControl.png", this,
		speedSelect );
	speedMenu->setTag(1231);
	speedMenu->setPosition(CCPointZero);
	speedMenu->setAnchorPoint(ccp(0,0));
	speedMenu->setScale(0.5f);
	CCMenu* speedmenu = CCMenu::create(speedMenu,NULL);
	speedmenu->setPosition(CCPointZero);
	//addPhysicalmenu->setScale(0.5f);
	//addPhysicalmenu->setAnchorPoint(ccp(0,1));
	//addPhysicalmenu->alignItemsVertically();
	addChild(speedmenu,11,123);

	CCSprite* speed = CCSprite::create("speed_1.png");
	speed->setPosition(ccp(speedMenu->getPositionX(),speedMenu->getPositionY()+speedMenu->getContentSize().height/2-10));
	speed->setAnchorPoint(ccp(0,0));
	speed->setScale(0.5f);
	speed->setTag(124);
	addChild(speed,12);

	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("back.png",
		"back.png", this,
		menu_selector(ChuangguanScene::menuCloseCallback));
	pCloseItem->setScale(0.5f);
	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- pCloseItem->getContentSize().height/4));

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
	CCDirector::sharedDirector()->replaceScene(Game4Key::scene());
}

void ChuangguanScene::addPhysical( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(Shop::scene());
}

void ChuangguanScene::speed( CCObject* pSender )
{
	CCMenu* speedMenu = (CCMenu*)(getChildByTag(123));
	CCMenuItemImage* speedm = (CCMenuItemImage*)speedMenu->getChildByTag(1231);
	if (speedNum == 1)
	{
		CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("speed_2.png");
		CCSprite* speed = (CCSprite*)(getChildByTag(124));
		speed->setTexture(aTexture);
		speed->setPosition(ccp(speedm->getContentSize().width / 2 / 4,speedm->getContentSize().height /2 /4 *3 - 10));
		//speed->setAnchorPoint(ccp(0,0));
		//speed->setScale(0.5f);
		//addChild(speed,12);
	}
}

void ChuangguanScene::menuCloseCallback(CCObject* pSender)
{
	CCDirector::sharedDirector()->replaceScene(MainGaneScene::scene());
}

