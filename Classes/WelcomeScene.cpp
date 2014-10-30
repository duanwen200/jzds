#include "WelcomeScene.h"
#include "mainFace.h"
#include <string>
#include "Common.h"
#include "SimpleAudioEngine.h"
using namespace std;
using namespace CocosDenshion;



WelcomeScene::WelcomeScene()
{
}

WelcomeScene::~WelcomeScene()
{
}

cocos2d::CCScene* WelcomeScene::scene()
{

	CCScene *scene = CCScene::create();
	WelcomeScene *layer = WelcomeScene::create();
	scene->addChild(layer);
	return scene;
}

bool WelcomeScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	SongSingleton::getInstance()->billShow = 1;

	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("welcome.plist","welcome.png");


	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(
		"music/title_bgm.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect(
		"music/mode_select_02.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect(
		"music/music_select_01.wav");
	SimpleAudioEngine::sharedEngine()->preloadEffect(
		"music/Nobodys_Listening.mp3");
	SimpleAudioEngine::sharedEngine()->preloadEffect(
		"music/Passing_Through.mp3");
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
	SimpleAudioEngine::sharedEngine()->setEffectsVolume(0.5);


	SongSingleton::getInstance()->ReadXmlFile();

	CCSprite* bgSprite = CCSprite::create("login_2.png");
	bgSprite->setAnchorPoint(CCPointZero);
	bgSprite->setPosition(ccp(origin.x,origin.y));
	this->addChild(bgSprite);

	//CCScale9Sprite* qqSprite = CCScale9Sprite::createWithSpriteFrameName("15.png");
	//qqSprite->setContentSize(CCSizeMake(visibleSize.width - 150, 60));
	CCSprite* qqSprite = CCSprite::createWithSpriteFrameName("15.png");
	//qqSprite->setScale(1.5f);
	//qqSprite->setScaleX(1.8f);
	//qqSprite->setScaleY(0.5f);
	qqSprite->setPosition(ccp(origin.x ,origin.y + visibleSize.height/12));
	qqSprite->setAnchorPoint(CCPointZero);
	//this->addChild(qqSprite,100,15);


	//CCScale9Sprite* passwordSprite = CCScale9Sprite::createWithSpriteFrameName("15.png");
	//CCEditBox* m_InputBox = CCEditBox::create(CCSizeMake(100, 50),  
	//	passwordSprite);  
	//m_InputBox->setAnchorPoint(ccp(0.5f, 0.5f));  
	//m_InputBox->setPosition(ccp(100, 200));  
	//this->addChild(m_InputBox, 100);  
	//m_InputBox->setColor(ccc3(255, 0, 0));  
	//m_InputBox->setText("***");  
	//m_InputBox->setMaxLength(10); //这个在PC上没有作用的。  
	//m_InputBox->setOpacity(200);  
	//m_InputBox->setFontSize(10);  
	//m_InputBox->setInputFlag(kEditBoxInputFlagPassword); 

	//string string = m_InputBox->getText();

	CCSprite* weixinSprite = CCSprite::createWithSpriteFrameName("25.png");
	//weixinSprite->setScale(1.5f);
	//weixinSprite->setScaleX(1.8f);
	//weixinSprite->setScaleY(0.5f);
	weixinSprite->setPosition(ccp(qqSprite->getPositionX() + qqSprite->getContentSize().width*2 - 20 ,origin.y + visibleSize.height/12));
	weixinSprite->setAnchorPoint(CCPointZero);
	//this->addChild(weixinSprite,100,25);

	//////////////////////////////////////////////////////////////////////////
	CCSprite* buttonSprite = CCSprite::create("start.png");
	//buttonSprite->setAnchorPoint(CCPointZero);
	//buttonSprite->setScale(0.5f);
	//buttonSprite->setPosition(ccp(origin.x+visibleSize.width/2,origin.y));
	//this->addChild(buttonSprite);

	SEL_MenuHandler startSelect= (SEL_MenuHandler)menu_selector(WelcomeScene::playWithQQ);
	CCMenuItemSprite* startMenu = CCMenuItemSprite::create(buttonSprite,
		buttonSprite, buttonSprite, this,
		startSelect );
	CCMenu* menu = CCMenu::create(startMenu,NULL);
	menu->setPosition(ccp(origin.x+visibleSize.width*2/4 +50,origin.y));
	menu->setScale(0.5f);
	addChild(menu,10);
	//////////////////////////////////////////////////////////////////////////

	CCSprite* manloginSprite = CCSprite::createWithSpriteFrameName("02.png");
	manloginSprite->setScale(0.5f);
	manloginSprite->setPosition(ccp(origin.x + visibleSize.width/2 - 85 ,origin.y + visibleSize.height - 20));
	manloginSprite->setAnchorPoint(ccp(0.5,1));
	this->addChild(manloginSprite,10,2);

	CCSprite* mwomanloginSprite = CCSprite::createWithSpriteFrameName("03.png");
	mwomanloginSprite->setScale(0.5f);
	mwomanloginSprite->setPosition(ccp(origin.x + visibleSize.width/2 ,origin.y + visibleSize.height-5));
	mwomanloginSprite->setAnchorPoint(ccp(0.5,1));
	this->addChild(mwomanloginSprite,11,3);

	CCSprite* rwomanloginSprite = CCSprite::createWithSpriteFrameName("04.png");
	rwomanloginSprite->setScale(0.5f);
	rwomanloginSprite->setPosition(ccp(origin.x + visibleSize.width/2 +85,origin.y + visibleSize.height -20));
	rwomanloginSprite->setAnchorPoint(ccp(0.5,1));
	this->addChild(rwomanloginSprite,10,4);


	CCSprite* mloginSprite = CCSprite::createWithSpriteFrameName("10.png");
	mloginSprite->setScaleY(0.4f);
	mloginSprite->setScaleX(0.5f);
	mloginSprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 20));
	mloginSprite->setAnchorPoint(ccp(0.5,0.5));
	addChild(mloginSprite,9,10);

	CCSprite* jzdsSprite = CCSprite::createWithSpriteFrameName("01.png");
	jzdsSprite->setScale(0.4f);
	//jzdsSprite->setScaleX(0.5f);
	jzdsSprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 20));
	jzdsSprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(jzdsSprite,12,1);

	CCSprite* pkSprite = CCSprite::createWithSpriteFrameName("16.png");
	pkSprite->setScale(0.4f);
	//jzdsSprite->setScaleX(0.5f);
	pkSprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 -10));
	pkSprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(pkSprite,12,16);

	CCSprite* gzhu1Sprite = CCSprite::createWithSpriteFrameName("09.png");
	gzhu1Sprite->setScaleY(0.5f);
	gzhu1Sprite->setRotation(-30.0f);
	gzhu1Sprite->setColor(ccc3(255,255,0));
	//jzdsSprite->setScaleX(0.5f);
	gzhu1Sprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 20));
	gzhu1Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(gzhu1Sprite,8,91);

	CCSprite* gzhu2Sprite = CCSprite::createWithSpriteFrameName("09.png");
	gzhu2Sprite->setScaleY(0.5f);
	gzhu2Sprite->setRotation(-60.0f);
	//gzhu2Sprite->setFlipX(true);
	//gzhu2Sprite->setFlipY(true);
	//jzdsSprite->setScaleX(0.5f);
	gzhu2Sprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 20));
	gzhu2Sprite->setAnchorPoint(ccp(-1,-1));
	this->addChild(gzhu2Sprite,8,92);

	CCSprite* gzhu3Sprite = CCSprite::createWithSpriteFrameName("09.png");
	gzhu3Sprite->setScaleY(0.5f);
	gzhu3Sprite->setRotation(-150.0f);
	//jzdsSprite->setScaleX(0.5f);
	gzhu3Sprite->setPosition(ccp(origin.x + visibleSize.width/2,origin.y + visibleSize.height/2 + 20));
	gzhu3Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(gzhu3Sprite,8,93);


	CCSprite* yinfu1Sprite = CCSprite::createWithSpriteFrameName("17.png");
	yinfu1Sprite->setScale(0.5f);
	//yinfu1Sprite->setRotation(-150.0f);
	//jzdsSprite->setScaleX(0.5f);
	yinfu1Sprite->setPosition(ccp(origin.x + visibleSize.width/8 ,origin.y+ visibleSize.height/4));
	yinfu1Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(yinfu1Sprite,15,17);

	CCSprite* yinfu2Sprite = CCSprite::createWithSpriteFrameName("30.png");
	yinfu2Sprite->setScale(0.5f);
	//yinfu1Sprite->setRotation(-150.0f);
	//jzdsSprite->setScaleX(0.5f);
	yinfu2Sprite->setPosition(ccp(origin.x + visibleSize.width/8 ,origin.y+ visibleSize.height*3/4));
	yinfu2Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(yinfu2Sprite,15,30);

	CCSprite* yinfu3Sprite = CCSprite::createWithSpriteFrameName("18.png");
	yinfu3Sprite->setScale(0.5f);
	//yinfu1Sprite->setRotation(-150.0f);
	//jzdsSprite->setScaleX(0.5f);
	yinfu3Sprite->setPosition(ccp(origin.x + visibleSize.width*7/8 ,origin.y+ visibleSize.height/4));
	yinfu3Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(yinfu3Sprite,15,18);

	CCSprite* yinfu4Sprite = CCSprite::createWithSpriteFrameName("19.png");
	yinfu4Sprite->setScale(0.5f);
	//yinfu1Sprite->setRotation(-150.0f);
	//jzdsSprite->setScaleX(0.5f);
	yinfu4Sprite->setPosition(ccp(origin.x + visibleSize.width*7/8 ,origin.y+ visibleSize.height*3/4));
	yinfu4Sprite->setAnchorPoint(ccp(0.5,0.5));
	this->addChild(yinfu4Sprite,15,19);


	CCSize editBoxSize = CCSizeMake(visibleSize.width/3, visibleSize.height/10);

	// top
	m_pEditName = CCEditBox::create(editBoxSize, CCScale9Sprite::create("username.png"));
	m_pEditName->setPosition(ccp(origin.x+visibleSize.width/2, origin.y+visibleSize.height*4/10));
	m_pEditName->setFontSize(25);
	m_pEditName->setFontColor(ccRED);
	m_pEditName->setPlaceHolder("Name:");
	m_pEditName->setPlaceholderFontColor(ccWHITE);
	m_pEditName->setMaxLength(8);
	m_pEditName->setReturnType(kKeyboardReturnTypeDone);
	m_pEditName->setInputMode(kEditBoxInputModeSingleLine);
	m_pEditName->setDelegate(this);
	addChild(m_pEditName,20);

	m_pEditPassword = CCEditBox::create(editBoxSize, CCScale9Sprite::create("username.png"));
	m_pEditPassword->setPosition(ccp(origin.x+visibleSize.width/2, origin.y+visibleSize.height*3/10));
	m_pEditPassword->setFontColor(ccGREEN);
	m_pEditPassword->setPlaceHolder("Password:");
	m_pEditPassword->setMaxLength(6);
	m_pEditPassword->setInputFlag(kEditBoxInputFlagPassword);
	m_pEditPassword->setInputMode(kEditBoxInputModeSingleLine);
	m_pEditPassword->setDelegate(this);
	addChild(m_pEditPassword,20);

	schedule(schedule_selector(WelcomeScene::amation), 1.0f);


	return true;
}

void WelcomeScene::playWithQQ( CCObject* pSender )
{
	string username = m_pEditName->getText();
	string password = m_pEditPassword->getText();
	if (!username.empty() && !password.empty())
	{
		CCLOG(username.c_str());
		CCLOG(password.c_str());
	}
	CCDirector::sharedDirector()->replaceScene(MainGaneScene::scene());
}

void WelcomeScene::playWithWeixin( CCObject* pSender )
{

}

void WelcomeScene::amation( float dt )
{
	CCSprite* mloginSprite = (CCSprite*)getChildByTag(10);


	CCActionInterval *actionScaleTo = CCScaleTo::create(0.5, 0.6f);
	CCActionInterval *actionScaleToBack = CCScaleTo::create(0.5, 0.50f);
	mloginSprite->runAction(CCSequence::create(actionScaleTo, actionScaleToBack, NULL));
	//CCActionInterval*  actionBy = CCScaleBy::create(2.0f, 0.5f,1.0f); 
	//CCActionInterval*  actionTo = CCScaleTo::create(2.0f, 0.5f); 
	//mloginSprite->runAction( CCSequence::create(actionBy, actionBy->reverse(), NULL));   
	//mloginSprite->runAction( actionTo);   

	CCSprite* gzhu2Sprite = (CCSprite*)getChildByTag(91);
	CCActionInterval *actionSkewTo = CCSkewTo::create(0.5, 0.0f,10.0f);
	CCActionInterval *actionSkewBack = CCSkewTo::create(0.5, 0.0f,0.0f);
	gzhu2Sprite->runAction(CCSequence::create(actionSkewTo, actionSkewBack, NULL));

	CCSprite* jzdsSprite = (CCSprite*)getChildByTag(1);
	CCActionInterval *jzdsactionScaleTo = CCScaleTo::create(0.5, 0.6f);
	CCActionInterval *jzdsactionScaleToBack = CCScaleTo::create(0.5, 0.50f);
	jzdsSprite->runAction(CCSequence::create(jzdsactionScaleTo, jzdsactionScaleToBack, NULL));

}

void WelcomeScene::editBoxEditingDidBegin( CCEditBox* editBox )
{

}

void WelcomeScene::editBoxEditingDidEnd( CCEditBox* editBox )
{

}

void WelcomeScene::editBoxTextChanged( CCEditBox* editBox, const std::string& text )
{

}

void WelcomeScene::editBoxReturn( CCEditBox* editBox )
{

}