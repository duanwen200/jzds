#include "mainGame.h"
#include "HelloWorldScene.h"
#include "ChuangguanScene.h"
#include "MoreTypeScene.h"

bool MainGaneScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}



	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();


	CCSprite* bgSprite = CCSprite::create("login_2.png");
	bgSprite->setAnchorPoint(CCPointZero);
	bgSprite->setPosition(ccp(origin.x,origin.y));
	this->addChild(bgSprite,9);

	CCScale9Sprite* userInfo = CCScale9Sprite::create("rolerank.png",CCRectMake(origin.x,origin.y + visibleSize.height,visibleSize.width/2,30));//("rolerank.png");
	userInfo->setAnchorPoint(ccp(0,1));
	userInfo->setPosition(ccp(origin.x,origin.y+visibleSize.height));
	this->addChild(userInfo,10);


	CCLabelBMFont *name = CCLabelBMFont::create("test", "fonts/futura-48.fnt");
	addChild(name, 11, 10);
	name->setPosition(origin.x , visibleSize.height);
	name->setAnchorPoint(ccp(0,1));


	CCLabelBMFont *level = CCLabelBMFont::create("level 1", "fonts/futura-48.fnt");
	addChild(level, 11, 11);
	level->setPosition(origin.x+name->getContentSize().width,origin.y + visibleSize.height);
	level->setAnchorPoint(ccp(0,1));

	CCSprite* role = CCSprite::create("role.png");
	role->setScale(0.4f);
	role->setPosition(ccp(origin.x + visibleSize.width*4/5,origin.y+visibleSize.height/4));
	role->setAnchorPoint(ccp(0.5,0));
	addChild(role,12);

	CCSprite* moretypeButton = CCSprite::create("moretype.png");
	//moretypeButton->setScale(0.5f);
	//moretypeButton->setAnchorPoint(CCPointZero);
	//moretypeButton->setPosition(ccp(origin.x + visibleSize.width*3/5,origin.y+visibleSize.height/8));
	//addChild(moretypeButton,12);

	CCSprite* cgButton = CCSprite::create("chuangguan.png");
	//cgButton->setScale(0.5f);
	//cgButton->setAnchorPoint(CCPointZero);
	//cgButton->setPosition(ccp(origin.x + visibleSize.width*4/5,origin.y+visibleSize.height/8));
	//addChild(cgButton,12);


	SEL_MenuHandler moretypeSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::moretype);
	CCMenuItemSprite* moreMenu = CCMenuItemSprite::create(moretypeButton,
		moretypeButton, moretypeButton, this,
		moretypeSelect );
	SEL_MenuHandler cgSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::rank);
	CCMenuItemSprite* cgMenu = CCMenuItemSprite::create(cgButton,
		cgButton, cgButton, this,
		cgSelect );
	CCMenu* menu = CCMenu::create(moreMenu,cgMenu,NULL);
	menu->setPosition(ccp(270,origin.y+visibleSize.height/10));
	menu->setScale(0.5f);
	menu->alignItemsHorizontallyWithPadding(10);
	addChild(menu,12);

	CCTableView* tableView = CCTableView::create(this, CCSizeMake(250, 200));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(20,30));
	tableView->setDelegate(this);
	this->addChild(tableView,10);
	tableView->reloadData();
	return true;
}

cocos2d::CCScene* MainGaneScene::scene()
{
	CCScene *scene = CCScene::create();
	MainGaneScene *layer = MainGaneScene::create();
	scene->addChild(layer);
	return scene;

}

cocos2d::CCSize MainGaneScene::tableCellSizeForIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{
	return CCSizeMake(250,30);
}

void MainGaneScene::tableCellTouched( cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell )
{

}

cocos2d::extension::CCTableViewCell* MainGaneScene::tableCellAtIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{
	CCString *string = CCString::createWithFormat("user name :%d", idx);
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
		cell->addChild(bgsprite,1);

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

unsigned int MainGaneScene::numberOfCellsInTableView( cocos2d::extension::CCTableView *table )
{
	return 10;
}

void MainGaneScene::moretype( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}

void MainGaneScene::rank( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(ChuangguanScene::scene());
}
