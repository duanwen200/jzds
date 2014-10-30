#include "UserInput.h"
#include "WelcomeScene.h"


bool UserInputScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}


	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("welcome.plist","welcome.png");


	CCSprite* bgSprite = CCSprite::create("login_2.png");
	bgSprite->setAnchorPoint(CCPointZero);
	bgSprite->setPosition(ccp(origin.x,origin.y));
	this->addChild(bgSprite,9);


	CCSprite* buttonSprite = CCSprite::create("start.png");
	//buttonSprite->setAnchorPoint(CCPointZero);
	//buttonSprite->setScale(0.5f);
	//buttonSprite->setPosition(ccp(origin.x+visibleSize.width/2,origin.y));
	//this->addChild(buttonSprite);

	SEL_MenuHandler startSelect= (SEL_MenuHandler)menu_selector(UserInputScene::startGame);
	CCMenuItemSprite* startMenu = CCMenuItemSprite::create(buttonSprite,
		buttonSprite, buttonSprite, this,
		startSelect );
	CCMenu* menu = CCMenu::create(startMenu,NULL);
	menu->setPosition(ccp(origin.x+visibleSize.width/2,origin.y));
	menu->setScale(0.5f);
	addChild(menu,10);



	CCSize editBoxSize = CCSizeMake(visibleSize.width - 100, 60);

	// top
	m_pEditName = CCEditBox::create(editBoxSize, CCScale9Sprite::create("username.png"));
	m_pEditName->setPosition(ccp(origin.x+visibleSize.width/2, origin.y+visibleSize.height*3/4));
	m_pEditName->setFontSize(25);
	m_pEditName->setFontColor(ccRED);
	m_pEditName->setPlaceHolder("Name:");
	m_pEditName->setPlaceholderFontColor(ccWHITE);
	m_pEditName->setMaxLength(8);
	m_pEditName->setReturnType(kKeyboardReturnTypeDone);
	m_pEditName->setDelegate(this);
	addChild(m_pEditName,10);

	m_pEditPassword = CCEditBox::create(editBoxSize, CCScale9Sprite::create("username.png"));
	m_pEditPassword->setPosition(ccp(origin.x+visibleSize.width/2, origin.y+visibleSize.height/2));
	m_pEditPassword->setFontColor(ccGREEN);
	m_pEditPassword->setPlaceHolder("Password:");
	m_pEditPassword->setMaxLength(6);
	m_pEditPassword->setInputFlag(kEditBoxInputFlagPassword);
	m_pEditPassword->setInputMode(kEditBoxInputModeSingleLine);
	m_pEditPassword->setDelegate(this);
	addChild(m_pEditPassword,10);

	
	//////////////////////////////////////////////////////////////////////////
	//UILayer* ul = UILayer::create();
	//UILayout* widget = dynamic_cast<UILayout*>(GUIReader::shareReader()->widgetFromJsonFile("SelectSong1_1.json"));
	//ul->addWidget(widget);

	//Button* startBT = (Button*)ul->getWidgetByName("Button_28");
	//startBT->addTouchEventListener(this,toucheventselector(UserInputScene::startGame));
	//////////////////////////////////////////////////////////////////////////
	return true;
}

cocos2d::CCScene* UserInputScene::scene()
{

	CCScene *scene = CCScene::create();
	UserInputScene *layer = UserInputScene::create();
	scene->addChild(layer);
	return scene;
}


void UserInputScene::startGame( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(WelcomeScene::scene());
}

//void UserInputScene::startGame( CCObject* pSender,TouchEventType type )
//{
//	CCDirector::sharedDirector()->replaceScene(WelcomeScene::scene());
//
//}

void UserInputScene::editBoxEditingDidBegin( CCEditBox* editBox )
{

}

void UserInputScene::editBoxEditingDidEnd( CCEditBox* editBox )
{

}

void UserInputScene::editBoxTextChanged( CCEditBox* editBox, const std::string& text )
{

}

void UserInputScene::editBoxReturn( CCEditBox* editBox )
{

}
