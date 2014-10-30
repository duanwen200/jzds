#include "PauseScene.h"
#include "ChuangguanScene.h"

bool PauseScene::init()
{
	bool bRef = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		this->setContentSize(CCSizeZero);
		// 初始化需要的 Menu
		//CCMenu* menu = CCMenu::create();
		//menu->setPosition(CCPointZero);
		//setMenuButton(menu);
		//CCLayerColor* color = CCLayerColor::create(ccc4(0,0,0,0));

		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		CCLayerColor* layerColor = CCLayerColor::create();  

		layerColor->setColor(ccc3(0, 0, 0));  

		layerColor->setOpacity(150);  

		layerColor->setContentSize(CCSizeMake(winSize.width, winSize.height));  

		this->addChild(layerColor,0); 
		setTouchEnabled(true);
		bRef = true;
	}while(0);
	return bRef;
}

void PauseScene::registerWithTouchDispatcher( void )
{

	// 这里的触摸优先级设置为 -128 这保证了，屏蔽下方的触摸
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}

bool PauseScene::ccTouchBegan( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent )
{
	return true;

}

PauseScene* PauseScene::create(const char* backgroundImage)
{
	PauseScene* pPause = PauseScene::create();
	pPause->setSpriteBackGround(CCSprite::create(backgroundImage));
	return pPause;
}

PauseScene::PauseScene():
	m_callbackListener(NULL)
	, m_callback(NULL)
	, m__sfBackGround(NULL)
{

}

PauseScene::~PauseScene()
{
	CC_SAFE_RELEASE(m__sfBackGround);

}

void PauseScene::onEnter()
{
	CCLayer::onEnter();
	CCSize contentSize;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint pCenter = ccp(winSize.width / 2, winSize.height / 2);
	getSpriteBackGround()->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	//getSpriteBackGround()->setScale(0.5f);
	this->addChild(getSpriteBackGround(), 1, 0);

	//CCScale9Sprite* pauseSprite = CCScale9Sprite::create("pauseButton.png");
	//CCLabelTTF* ttf = CCLabelTTF::create("pause","",20);
	//ttf->setColor(ccc3(0,0,0));
	//CCControlButton* pauseButton = CCControlButton::create(ttf,pauseSprite);
	//pauseButton->setPosition(pCenter);
	//pauseButton->addTargetWithActionForControlEvents(
	//	this,
	//	cccontrol_selector(PauseScene::pauseaction),
	//	CCControlEventTouchDown
	//	);
	//addChild(pauseButton,0,0);
	// 创建图片菜单按钮
	CCMenuItemImage* pausemenuImage = CCMenuItemImage::create("pauseButton.png", "pauseButton.png", this, menu_selector(PauseScene::buttonCallback));
	pausemenuImage->setTag(0);
	pausemenuImage->setPosition(pCenter);
	pausemenuImage->setScale(0.5f);
	// 添加文字说明并设置位置
	CCSize iPausemenu = pausemenuImage->getContentSize();
	CCLabelTTF* ttf = CCLabelTTF::create("resume", "", 20);
	ttf->setColor(ccc3(0, 0, 0));
	ttf->setPosition(ccp(iPausemenu.width / 2, iPausemenu.height / 2));
	pausemenuImage->addChild(ttf);
	CCMenuItemImage* stopmenuImage = CCMenuItemImage::create("pauseButton.png", "pauseButton.png", this, menu_selector(PauseScene::buttonCallback));
	stopmenuImage->setTag(1);
	stopmenuImage->setPosition(ccp(pCenter.x,pCenter.y - 30));
	stopmenuImage->setScale(0.5f);
	// 添加文字说明并设置位置
	CCSize iStopmenu = stopmenuImage->getContentSize();
	CCLabelTTF* stopttf = CCLabelTTF::create("stop", "", 20);
	stopttf->setColor(ccc3(0, 0, 0));
	stopttf->setPosition(ccp(iStopmenu.width / 2, iStopmenu.height / 2));
	stopmenuImage->addChild(stopttf);
	CCMenu* menu = CCMenu::create(pausemenuImage,stopmenuImage,NULL);
	menu->setPosition(CCPointZero);
	addChild(menu,2);
	//getMenuButton()->addChild(menuImage);
	//contentSize = getSpriteBackGround()->getTexture()->getContentSize();
	//setContentSize(CCSizeMake(200,250));
}

void PauseScene::onExit()
{
	CCLayer::onExit();
}

void PauseScene::setCallbackFunc( CCObject* target, SEL_CallFuncN callfun )
{
	m_callbackListener = target;
	m_callback = callfun;
}

void PauseScene::buttonCallback( CCObject* pSender )
{
	CCNode* node = dynamic_cast<CCNode*>(pSender);
	CCLog("touch tag: %d", node->getTag());
	//if (node->getTag() == 0)
	//{
	//	
	//	if (m_callback && m_callbackListener){
	//		(m_callbackListener->*m_callback)(node);
	//	}
	//	this->removeFromParent();
	//	CCDirector::sharedDirector()->replaceScene(ChuangguanScene::scene());
	//}
	//if (node->getTag() == 1)
	//{

	//	//CCDirector::sharedDirector()->replaceScene(ChuangguanScene::scene());
	//}

	if (m_callback && m_callbackListener){
		(m_callbackListener->*m_callback)(node);
	}
	this->removeFromParent();
}

void PauseScene::pauseaction( CCObject * pSender,CCControlEvent )
{

	CCNode* node = dynamic_cast<CCNode*>(pSender);
	CCLog("touch tag: %d", node->getTag());
	if (m_callback && m_callbackListener){
		(m_callbackListener->*m_callback)(node);
	}
	this->removeFromParent();
}
