#include "BillboardScene.h"

bool BillboardScene::init()
{
	bool bRef = false;
	do{
		CC_BREAK_IF(!CCLayer::init());
		this->setContentSize(CCSizeZero);

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

void BillboardScene::registerWithTouchDispatcher( void )
{
	// 这里的触摸优先级设置为 -128 这保证了，屏蔽下方的触摸
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}

bool BillboardScene::ccTouchBegan( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent )
{
	this->removeFromParent();
	return true;
}

BillboardScene* BillboardScene::create( const char* backgroundImage )
{
	BillboardScene* pBillboard = BillboardScene::create();
	pBillboard->setSpriteBackGround(CCSprite::create(backgroundImage));
	return pBillboard;
}

void BillboardScene::setCallbackFunc( CCObject* target, SEL_CallFuncN callfun )
{
	m_callbackListener = target;
	m_callback = callfun;
}

void BillboardScene::buttonCallback( CCObject* pSender )
{
	CCNode* node = dynamic_cast<CCNode*>(pSender);
	CCLog("touch tag: %d", node->getTag());
	if (m_callback && m_callbackListener){
		(m_callbackListener->*m_callback)(node);
	}
	this->removeFromParent();
}

void BillboardScene::pauseaction( CCObject * sender,CCControlEvent )
{

}

void BillboardScene::onEnter()
{

	CCLayer::onEnter();
	CCSize contentSize;
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCPoint pCenter = ccp(winSize.width / 2, winSize.height / 2);
	getSpriteBackGround()->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	getSpriteBackGround()->setScale(0.5f);
	this->addChild(getSpriteBackGround(), 1);

	//CCSprite* closeSprite = CCSprite::create("close.png");
	CCMenuItemImage* closemenuImage = CCMenuItemImage::create("close.png", "close.png", this, menu_selector(BillboardScene::buttonCallback));
	closemenuImage->setTag(0);
	closemenuImage->setPosition(ccp(getSpriteBackGround()->getPositionX() + getSpriteBackGround()->getContentSize().width/4,getSpriteBackGround()->getPositionY() + getSpriteBackGround()->getContentSize().height/4));
	//closemenuImage->setScale(0.5f);
	closemenuImage->setAnchorPoint(ccp(1,1));
	CCMenu* menu = CCMenu::create(closemenuImage,NULL);
	menu->setPosition(CCPointZero);
	addChild(menu,2);

}

void BillboardScene::onExit()
{
	CCLayer::onExit();
}

BillboardScene::BillboardScene():
m_callbackListener(NULL)
	, m_callback(NULL)
	, m__sfBackGround(NULL)
{

}

BillboardScene::~BillboardScene()
{
	CC_SAFE_RELEASE(m__sfBackGround);
}
