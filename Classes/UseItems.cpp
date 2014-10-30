#include "UseItems.h"
#include "Game4Key.h"
#include "Game5Key.h"
#include "Game6Key.h"
#include "Common.h"
void UserItems::tableCellTouched( cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell )
{

	CCLOG("cell touched at index: %i", cell->getIdx());
	CCLOG("wwww");  

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("rolerankcell.png");  

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

	pSprite->setTexture(aTexture);  
	if (cellNum != cell->getIdx())
	{
		cocos2d::extension::CCTableViewCell* cellLast = table->cellAtIndex(cellNum);

		if (cellLast!=NULL)
		{
			CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("roleListinfo.png");  

			CCSprite *pSprite=(CCSprite *)cellLast->getChildByTag(200);  

			pSprite->setTexture(aTexture); 
		} 
		cellNum = cell->getIdx();
	}
}

cocos2d::CCSize UserItems::tableCellSizeForIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{

	return CCSizeMake(250,50);
}

cocos2d::extension::CCTableViewCell* UserItems::tableCellAtIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{

	CCString *string = CCString::createWithFormat("item :%d", idx);
	CCTableViewCell *cell = table->dequeueCell();
	if (!cell) {
		cell = new CCTableViewCell;
		cell->autorelease();



		CCSprite *sprite = CCSprite::create("icon.png");
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(30, 0));
		sprite->setScaleY(30/sprite->getContentSize().height);
		cell->addChild(sprite,2);

		CCSprite *bgsprite = CCSprite::create("rolerankcellnormal.png");
		bgsprite->setAnchorPoint(CCPointZero);
		bgsprite->setPosition(ccp(0, 0));
		bgsprite->setScaleY(30/bgsprite->getContentSize().height);
		bgsprite->setScaleX(250/bgsprite->getContentSize().width);
		cell->addChild(bgsprite,1,200);

		CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
		label->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,0));
		label->setAnchorPoint(CCPointZero);
		label->setTag(123);
		cell->addChild(label,2);
	}
	else
	{
		CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
		label->setString(string->getCString());
	}


	return cell;
}

unsigned int UserItems::numberOfCellsInTableView( cocos2d::extension::CCTableView *table )
{
	return 20;
}

cocos2d::CCScene* UserItems::scene()
{

	CCScene *scene = CCScene::create();
	UserItems *layer = UserItems::create();
	scene->addChild(layer);
	return scene;
}

bool UserItems::init()
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

	CCSprite* buttonSprite = CCSprite::create("start.png");
	SEL_MenuHandler startSelect= (SEL_MenuHandler)menu_selector(UserItems::startGame);
	CCMenuItemSprite* startMenu = CCMenuItemSprite::create(buttonSprite,
		buttonSprite, buttonSprite, this,
		startSelect );
	CCMenu* menu = CCMenu::create(startMenu,NULL);
	menu->setPosition(ccp(origin.x+visibleSize.width*4/5,origin.y+visibleSize.height/6));
	menu->setScale(0.5f);
	menu->setAnchorPoint(ccp(0,0));
	addChild(menu,13);


	CCTableView* tableView = CCTableView::create(this, CCSizeMake(250, 200));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(20,30));
	tableView->setDelegate(this);
	this->addChild(tableView,10);
	tableView->reloadData();
	return true;
}

void UserItems::startGame( CCObject* pSender )
{
	int key = SongSingleton::getInstance()->g_info->key;
	switch (key)
	{
	case 4:
		CCDirector::sharedDirector()->replaceScene(Game4Key::scene());
		break;
	case 5:
		CCDirector::sharedDirector()->replaceScene(Game5Key::scene());
		break;
	case 6:
		CCDirector::sharedDirector()->replaceScene(Game6Key::scene());
		break;
	default:
		CCDirector::sharedDirector()->replaceScene(Game4Key::scene());
		break;
	}
}


void UserItems::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)  
{  

	CCLOG("wwww");  

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("rolerankcell.png");  

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

	pSprite->setTexture(aTexture);  


} 

void UserItems::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)  
{  
	CCLOG("dddd");  

	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("rolerankcellnormal.png");  

	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

	pSprite->setTexture(aTexture);  
} 