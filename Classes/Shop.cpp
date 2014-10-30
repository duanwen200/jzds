#include "Shop.h"
#include "mainFace.h"

CCScene * Shop::scene()
{
	CCScene *scene = CCScene::create();
	Shop *layer = Shop::create();
	scene->addChild(layer);
	return scene;
}

bool Shop::init()
{
	if (!CCLayer::init())
	{
		return false;
	}
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	cellNum = 0;

	CCSprite* bgSprite = CCSprite::create("login_2.png");
	bgSprite->setAnchorPoint(CCPointZero);
	bgSprite->setPosition(ccp(origin.x,origin.y));
	this->addChild(bgSprite,9);

	//CCSprite* buttonSprite = CCSprite::create("start.png");
	//SEL_MenuHandler startSelect= (SEL_MenuHandler)menu_selector(Shop::buy);
	//CCMenuItemSprite* startMenu = CCMenuItemSprite::create(buttonSprite,
	//	buttonSprite, buttonSprite, this,
	//	startSelect );
	//CCMenu* menu = CCMenu::create(startMenu,NULL);
	//menu->setPosition(ccp(origin.x+visibleSize.width*4/5,origin.y+visibleSize.height/6));
	//menu->setScale(0.5f);
	//menu->setAnchorPoint(ccp(0,0));
	//addChild(menu,13);


	CCTableView* tableView = CCTableView::create(this, CCSizeMake(330, 250));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(20,20));
	tableView->setDelegate(this);
	this->addChild(tableView,10);
	tableView->reloadData();


	CCMenuItemImage *pCloseItem = CCMenuItemImage::create("back.png",
		"back.png", this,
		menu_selector(Shop::callBack));

	pCloseItem->setPosition(
		ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
		origin.y +visibleSize.height- pCloseItem->getContentSize().height/2));
	pCloseItem->setScale(0.5f);
	CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 13);

	return true;
}

void Shop::tableCellTouched( cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell )
{

	CCLOG("cell touched at index: %i", cell->getIdx());
}

cocos2d::CCSize Shop::tableCellSizeForIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{

	return CCSizeMake(330,60);
}

cocos2d::extension::CCTableViewCell* Shop::tableCellAtIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{

	CCString *string = CCString::createWithFormat("*  %d", idx * 5);
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell) {
		cell = new CCTableViewCell;
		cell->autorelease();



		CCSprite *sprite = CCSprite::create("physical.png");
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(30, 0));
		sprite->setScaleY(60/sprite->getContentSize().height);
		cell->addChild(sprite,2);

		CCSprite *bgsprite = CCSprite::create("item_1.png");
		bgsprite->setAnchorPoint(CCPointZero);
		bgsprite->setPosition(ccp(0, 0));
		bgsprite->setScaleY(60/bgsprite->getContentSize().height);
		bgsprite->setScaleX(330/bgsprite->getContentSize().width);
		cell->addChild(bgsprite,1,200);

		CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
		label->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,0));
		label->setAnchorPoint(CCPointZero);
		label->setTag(123);
		cell->addChild(label,2);

		CCSprite* goldbuySprite = CCSprite::create("gold_buy.png");
		goldbuySprite->setPosition(ccp(label->getPositionX() + 20*3,0 ));
		goldbuySprite->setAnchorPoint(CCPointZero);
		cell->addChild(goldbuySprite,2);


		CCLabelTTF *goldlabel = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
		goldlabel->setPosition(ccp(goldbuySprite->getPositionX() + 20 ,0));
		goldlabel->setAnchorPoint(CCPointZero);
		goldlabel->setTag(123);
		cell->addChild(goldlabel,2);

		//CCSprite* buySprite = CCSprite::create("buy.png");
		//buySprite->setPosition(ccp(goldbuySprite->getPositionX() + goldbuySprite->getContentSize().width,0));
		//buySprite->setAnchorPoint(CCPointZero);
		//buySprite->setScale(0.5f);
		//cell->addChild(buySprite,2);

		//////////////////////////////////////////////////////////////////////////

		CCMenuItemImage *buySprite = CCMenuItemImage::create("buy.png",
			"buy.png", this,
			menu_selector(Shop::callBack));

		buySprite->setPosition(
			ccp(goldbuySprite->getPositionX() + goldbuySprite->getContentSize().width+20,0));
		buySprite->setScale(0.5f);
		CCMenu* pMenu = CCMenu::create(buySprite, NULL);
		pMenu->setPosition(ccp(20,20));
		cell->addChild(pMenu, 2);
		//////////////////////////////////////////////////////////////////////////
		
	}
	else
	{
		CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
		label->setString(string->getCString());
	}


	return cell;
}

unsigned int Shop::numberOfCellsInTableView( cocos2d::extension::CCTableView *table )
{
	return 20;
}


void Shop::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)  
{  

	CCLOG("wwww");  

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("item_1.png");  

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

	pSprite->setTexture(aTexture);  


} 
void Shop::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)  
{  
	CCLOG("dddd");  

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("item_1.png");  

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

	pSprite->setTexture(aTexture);  
} 

void Shop::callBack( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(MainGaneScene::scene());
}

void Shop::buy( CCObject* pSender )
{
	CCLOG("buy ........");
}

CCScene * ShopScene::scene()
{

	CCScene *scene = CCScene::create();
	ShopScene *layer = ShopScene::create();
	scene->addChild(layer);
	return scene;
}

bool ShopScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCLayerColor* layerColor = CCLayerColor::create();  
	layerColor->setColor(ccc3(0, 0, 0));  

	layerColor->setOpacity(150);  

	layerColor->setContentSize(CCSizeMake(winSize.width, winSize.height));  

	this->addChild(layerColor,0); 
	setTouchEnabled(true);

	CCSprite* bgSprite = CCSprite::create("buygold.png");
	bgSprite->setPosition(ccp(winSize.width / 2, winSize.height / 2));
	bgSprite->setScale(1.5f);
	this->addChild(bgSprite, 1);


	CCTableView* tableView = CCTableView::create(this, CCSizeMake(250, 200));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(bgSprite->getPositionX() ,bgSprite->getPositionY()));
	tableView->setDelegate(this);
	tableView->setTag(200);
	this->addChild(tableView,10);
	tableView->reloadData();

	return true;
}

void ShopScene::tableCellTouched( cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell )
{
	CCLOG("shop cell touch");
}

cocos2d::CCSize ShopScene::tableCellSizeForIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{

	return CCSizeMake(100,50);
}

cocos2d::extension::CCTableViewCell* ShopScene::tableCellAtIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{
	//CCString *stringName = CCString::createWithFormat("user name :%d", idx);
	//CCString *stringLevel = CCString::createWithFormat("level :%d", idx);
	//CCString *stringScore = CCString::createWithFormat("score :%d", idx);
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell) {
		cell = new CCTableViewCell;
		cell->autorelease();


		CCSprite *bgsprite = CCSprite::create("item_1.png");
		bgsprite->setAnchorPoint(CCPointZero);
		bgsprite->setPosition(ccp(0, 0));
		bgsprite->setScaleY(50/bgsprite->getContentSize().height);
		bgsprite->setScaleX(250/bgsprite->getContentSize().width);
		cell->addChild(bgsprite,1,200);

		CCSprite *sprite = CCSprite::create("physical.png");
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(5, 0));
		sprite->setScaleY(50/sprite->getContentSize().height);
		cell->addChild(sprite,2);

		int num = 5 * idx;
		CCString *stringTemp = CCString::createWithFormat("× %d", num);

		CCLabelTTF *labelName = CCLabelTTF::create(stringTemp->getCString(), "Helvetica", 10.0);
		labelName->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width + 10 ,sprite->getPositionY()));
		labelName->setAnchorPoint(CCPointZero);
		labelName->setTag(123);
		cell->addChild(labelName,2);

		//CCLabelTTF *labelLevel = CCLabelTTF::create(stringLevel->getCString(), "Helvetica", 10.0);
		//labelLevel->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width + 15 * 8,15));
		//labelLevel->setAnchorPoint(CCPointZero);
		//labelLevel->setTag(124);
		//cell->addChild(labelLevel,2);

		//CCLabelTTF *labelScore = CCLabelTTF::create(stringScore->getCString(), "Helvetica", 10.0);
		//labelScore->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,5));
		//labelScore->setAnchorPoint(CCPointZero);
		//labelScore->setTag(125);
		//cell->addChild(labelScore,2);
	}
	return cell;
}

unsigned int ShopScene::numberOfCellsInTableView( cocos2d::extension::CCTableView *table )
{
	return 10;
}

void ShopScene::registerWithTouchDispatcher( void )
{

	// 这里的触摸优先级设置为 -128 这保证了，屏蔽下方的触摸
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -128, true);
}

bool ShopScene::ccTouchBegan( cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent )
{
	CCLOG("shopscene touchbegan");
	return true;
}
