#include "mainFace.h"
//#include "RankScene.h"
#include "MoreTypeScene.h"
#include "Shop.h"
#include "BillboardScene.h"
#include "ChuangguanScene.h"
#include "setting.h"
#include "Quest.h"

bool MainGaneScene::init()
{
	if (!CCLayer::init())
	{
		return false;
	}



	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	cellNum = 0;
	tableSelect = 0;

	CCSprite* bgSprite = CCSprite::create("login_2.png");
	bgSprite->setAnchorPoint(CCPointZero);
	bgSprite->setPosition(ccp(origin.x,origin.y));
	this->addChild(bgSprite,9);

	//CCScale9Sprite* userInfo = CCScale9Sprite::create("rolerank.png",CCRectMake(origin.x,origin.y + visibleSize.height,visibleSize.width/2,30));//("rolerank.png");
	//userInfo->setAnchorPoint(ccp(0,1));
	//userInfo->setPosition(ccp(origin.x,origin.y+visibleSize.height));
	//this->addChild(userInfo,10);



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
	SEL_MenuHandler addPhysicalSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::addPhysical);
	CCMenuItemSprite* addPhysicalMenu = CCMenuItemSprite::create(physicalAdd,
		physicalAdd, physicalAdd, this,
		addPhysicalSelect );
	CCMenu* addPhysicalmenu = CCMenu::create(addPhysicalMenu,NULL);
	addPhysicalmenu->setPosition(ccp(origin.x + visibleSize.width/2+50,origin.y+visibleSize.height - 180));
	addPhysicalmenu->setScale(0.5f);
	addPhysicalmenu->setAnchorPoint(ccp(0,1));
	addPhysicalmenu->alignItemsVertically();
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



	CCSprite* role = CCSprite::create("role.png");
	role->setScale(0.4f);
	role->setPosition(ccp(origin.x + visibleSize.width*4/5 - role->getContentSize().width * 0.1,origin.y+visibleSize.height/4));
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
	menu->setPosition(ccp(270,-20));
	menu->setScale(0.5f);
	menu->alignItemsHorizontallyWithPadding(10);
	addChild(menu,12);

	CCTableView* tableView = CCTableView::create(this, CCSizeMake(250, 200));
	tableView->setDirection(kCCScrollViewDirectionVertical);
	tableView->setPosition(ccp(origin.x,origin.y + visibleSize.height/7));
	tableView->setDelegate(this);
	tableView->setTag(200);
	this->addChild(tableView,10);
	tableView->reloadData();


	//////////////////////////////////////////////////////////////////////////
	// 创建图片菜单按钮
	CCMenuItemImage* pausemenuImage = CCMenuItemImage::create("tableSelect.png", "tableSelect.png", this, menu_selector(MainGaneScene::tableSelectCall0));
	pausemenuImage->setTag(0);
	pausemenuImage->setPosition(ccp(origin.x+50,origin.y + visibleSize.height/7+200));
	pausemenuImage->setScaleX(2.5f);
	pausemenuImage->setScaleY(0.5f);
	// 添加文字说明并设置位置
	CCSize iPausemenu = pausemenuImage->getContentSize();
	CCLabelTTF* ttf = CCLabelTTF::create("rank", "", 20);
	ttf->setColor(ccc3(0, 0, 0));
	ttf->setPosition(ccp(iPausemenu.width / 2, iPausemenu.height / 2));
	pausemenuImage->addChild(ttf);
	CCMenuItemImage* stopmenuImage = CCMenuItemImage::create("tableSelect.png", "tableSelect.png", this, menu_selector(MainGaneScene::tableSelectCall1));
	stopmenuImage->setTag(1);
	stopmenuImage->setPosition(ccp(origin.x+150,origin.y + visibleSize.height/7+200));
	stopmenuImage->setScaleX(2.5f);
	stopmenuImage->setScaleY(0.5f);
	// 添加文字说明并设置位置
	CCSize iStopmenu = stopmenuImage->getContentSize();
	CCLabelTTF* stopttf = CCLabelTTF::create("total", "", 20);
	stopttf->setColor(ccc3(0, 0, 0));
	stopttf->setPosition(ccp(iStopmenu.width / 2, iStopmenu.height / 2));
	stopmenuImage->addChild(stopttf);
	CCMenu* tablemenu = CCMenu::create(pausemenuImage,stopmenuImage,NULL);
	tablemenu->setPosition(CCPointZero);
	addChild(tablemenu,12);
	//////////////////////////////////////////////////////////////////////////

	if (SongSingleton::getInstance()->billShow == 1)
	{

		BillboardScene* p1 = BillboardScene::create("innerpublicnotify1.png");
		p1->setContentSize(CCSizeMake(200,200));
		p1->setCallbackFunc(this,callfuncN_selector(MainGaneScene::buttonCallback));
		this->addChild(p1,15); 
		SongSingleton::getInstance()->billShow = 0;
	}



	//////////////////////////////////////////////////////////////////////////
	CCSprite* settingButton = CCSprite::create("setting.png");
	SEL_MenuHandler settingSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::setting);
	CCMenuItemSprite* settingMenu = CCMenuItemSprite::create(settingButton,
		settingButton, settingButton, this,
		settingSelect );
	settingMenu->setScale(0.5f);
	settingMenu->setAnchorPoint(ccp(0.5,0.5));
	//settingMenu->setPosition(ccp(origin.x + visibleSize.width / 10,origin.y + settingButton->getContentSize().height));

	CCSprite* inviteButton = CCSprite::create("invite.png");
	SEL_MenuHandler inviteSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::invite);
	CCMenuItemSprite* inviteMenu = CCMenuItemSprite::create(inviteButton,
		inviteButton, inviteButton, this,
		inviteSelect );
	inviteMenu->setScale(0.5f);
	inviteMenu->setAnchorPoint(ccp(0.5,0.5));
	//inviteMenu->setPosition(ccp(origin.x + visibleSize.width / 5,origin.y + settingMenu->getPositionY()));

	CCSprite* billButton = CCSprite::create("bill.png");
	SEL_MenuHandler billSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::bill);
	CCMenuItemSprite* billMenu = CCMenuItemSprite::create(billButton,
		billButton, billButton, this,
		billSelect );
	billMenu->setScale(0.5f);
	billMenu->setAnchorPoint(ccp(0.5,0.5));
	//billMenu->setPosition(ccp(origin.x + visibleSize.width *3 / 10,origin.y + settingMenu->getPositionY()));

	CCSprite* questButton = CCSprite::create("quest.png");
	SEL_MenuHandler questSelect= (SEL_MenuHandler)menu_selector(MainGaneScene::quest);
	CCMenuItemSprite* questMenu = CCMenuItemSprite::create(questButton,
		questButton, questButton, this,
		questSelect );
	questMenu->setScale(0.5f);
	questMenu->setAnchorPoint(ccp(0.5,0.5));
	//questMenu->setPosition(ccp(origin.x + visibleSize.width *4 / 10,origin.y + settingMenu->getPositionY()));

	CCMenu* setmenu = CCMenu::create(settingMenu,inviteMenu,billMenu,questMenu,NULL);
	setmenu->setPosition(ccp(100,10));
	//setmenu->setScale(0.5f);
	setmenu->alignItemsHorizontallyWithPadding(10);
	addChild(setmenu,12);
	//////////////////////////////////////////////////////////////////////////

	CCMenuItemImage* pkmenuImage = CCMenuItemImage::create("pk.png", "pk.png", this, menu_selector(MainGaneScene::tableSelectCall1));
	//pkmenuImage->setTag();
	pkmenuImage->setAnchorPoint(ccp(0.5,0.5));
	pkmenuImage->setScale(0.5f);
	pkmenuImage->setPosition(ccp(visibleSize.width - pkmenuImage->getContentSize().width /4 ,visibleSize.height*4/5));

	CCMenuItemImage* racemenuImage = CCMenuItemImage::create("race.png", "race.png", this, menu_selector(MainGaneScene::tableSelectCall1));
	//pkmenuImage->setTag();
	racemenuImage->setAnchorPoint(ccp(0.5,0.5));
	racemenuImage->setScale(0.5f);
	racemenuImage->setPosition(ccp(visibleSize.width - racemenuImage->getContentSize().width /4 ,visibleSize.height*3/5));

	CCMenu* imageMenu = CCMenu::create(pkmenuImage,racemenuImage,NULL);
	imageMenu->setPosition(CCPointZero);
	addChild(imageMenu,12);
	//////////////////////////////////////////////////////////////////////////
	return true;
}

void MainGaneScene::tableSelectCall0(CCObject* pSender)
{
		tableSelect = 0;
		CCLOG("1111");
		CCTableView* tableview = (CCTableView*)getChildByTag(200);
		tableview->reloadData();
}
void MainGaneScene::buttonCallback(cocos2d::CCNode *pNode)
{
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
	return CCSizeMake(250,50);
}

void MainGaneScene::tableCellTouched( cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell )
{
		CCLOG("wwww");  

		CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("item_1.png");  

		CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  

		pSprite->setTexture(aTexture);  
	if (cellNum != cell->getIdx())
	{
		cocos2d::extension::CCTableViewCell* cellLast = table->cellAtIndex(cellNum);

		if (cellLast!=NULL)
		{
		CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("item_1.png");  

		CCSprite *pSprite=(CCSprite *)cellLast->getChildByTag(200);  

		pSprite->setTexture(aTexture); 
		} 
		cellNum = cell->getIdx();
	}



}

cocos2d::extension::CCTableViewCell* MainGaneScene::tableCellAtIndex( cocos2d::extension::CCTableView *table, unsigned int idx )
{
	//CCTableView* totalView = (CCTableView*)this->getChildByTag(200);
	//if (table == totalView)
	//{
	//	CCLOG("ssssssss");
	//}
	
	if (tableSelect == 0)
	{
		CCString *stringName = CCString::createWithFormat("user name :%d", idx);
		CCString *stringLevel = CCString::createWithFormat("level :%d", idx);
		CCString *stringScore = CCString::createWithFormat("score :%d", idx);
		CCTableViewCell *cell = table->dequeueCell();
		if (!cell) {
			cell = new CCTableViewCell;
			cell->autorelease();



			CCSprite *sprite = CCSprite::create("icon.png");
			sprite->setAnchorPoint(CCPointZero);
			sprite->setPosition(ccp(5, 0));
			sprite->setScaleY(50/sprite->getContentSize().height);
			cell->addChild(sprite,2);

			CCSprite *bgsprite = CCSprite::create("item_1.png");
			bgsprite->setAnchorPoint(CCPointZero);
			bgsprite->setPosition(ccp(0, 0));
			bgsprite->setScaleY(50/bgsprite->getContentSize().height);
			bgsprite->setScaleX(250/bgsprite->getContentSize().width);
			cell->addChild(bgsprite,1,200);


			CCLabelTTF *labelName = CCLabelTTF::create(stringName->getCString(), "Helvetica", 10.0);
			labelName->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,15));
			labelName->setAnchorPoint(CCPointZero);
			labelName->setTag(123);
			cell->addChild(labelName,2);

			CCLabelTTF *labelLevel = CCLabelTTF::create(stringLevel->getCString(), "Helvetica", 10.0);
			labelLevel->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width + 15 * 8,15));
			labelLevel->setAnchorPoint(CCPointZero);
			labelLevel->setTag(124);
			cell->addChild(labelLevel,2);

			CCLabelTTF *labelScore = CCLabelTTF::create(stringScore->getCString(), "Helvetica", 10.0);
			labelScore->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,5));
			labelScore->setAnchorPoint(CCPointZero);
			labelScore->setTag(125);
			cell->addChild(labelScore,2);
		}
		else
		{
			CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
			label->setString(stringName->getCString());
		}


		return cell;
	}
	if (tableSelect == 1)
	{
		CCString *stringName = CCString::createWithFormat("user_name :%d", idx);
		CCString *stringLevel = CCString::createWithFormat("level :%d", idx);
		CCString *stringScore = CCString::createWithFormat("score :%d", idx);
		CCTableViewCell *cell = table->dequeueCell();
		if (!cell) {
			cell = new CCTableViewCell;
			cell->autorelease();



			CCSprite *sprite = CCSprite::create("icon.png");
			sprite->setAnchorPoint(CCPointZero);
			sprite->setPosition(ccp(5, 0));
			sprite->setScaleY(50/sprite->getContentSize().height);
			cell->addChild(sprite,2);

			CCSprite *bgsprite = CCSprite::create("item_1.png");
			bgsprite->setAnchorPoint(CCPointZero);
			bgsprite->setPosition(ccp(0, 0));
			bgsprite->setScaleY(50/bgsprite->getContentSize().height);
			bgsprite->setScaleX(250/bgsprite->getContentSize().width);
			cell->addChild(bgsprite,1,200);


			CCLabelTTF *labelName = CCLabelTTF::create(stringName->getCString(), "Helvetica", 10.0);
			labelName->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,15));
			labelName->setAnchorPoint(CCPointZero);
			labelName->setTag(123);
			cell->addChild(labelName,2);

			CCLabelTTF *labelLevel = CCLabelTTF::create(stringLevel->getCString(), "Helvetica", 10.0);
			labelLevel->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width + 15 * 8,15));
			labelLevel->setAnchorPoint(CCPointZero);
			labelLevel->setTag(124);
			cell->addChild(labelLevel,2);

			CCLabelTTF *labelScore = CCLabelTTF::create(stringScore->getCString(), "Helvetica", 10.0);
			labelScore->setPosition(ccp(sprite->getPositionX()+sprite->getContentSize().width,5));
			labelScore->setAnchorPoint(CCPointZero);
			labelScore->setTag(125);
			cell->addChild(labelScore,2);
		}
		else
		{
			CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(123);
			label->setString(stringName->getCString());
		}


		return cell;
	}
	
	
}

unsigned int MainGaneScene::numberOfCellsInTableView( cocos2d::extension::CCTableView *table )
{
	return 10;
}

void MainGaneScene::moretype( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(MoreTypeScene::scene());
}

void MainGaneScene::rank( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(ChuangguanScene::scene());
}

void MainGaneScene::addPhysical( CCObject* pSender )
{
	CCLOG("addPhysical");
	CCDirector::sharedDirector()->replaceScene(Shop::scene());
}

void MainGaneScene::tableSelectCall1( CCObject* pSender )
{

	tableSelect = 1;
	CCLOG("1111");
	CCTableView* tableview = (CCTableView*)getChildByTag(200);
	tableview->reloadData();
}

void MainGaneScene::setting( CCObject* pSender )
{
	CCDirector::sharedDirector()->replaceScene(SettingScene::scene());
}

void MainGaneScene::invite( CCObject* pSender )
{

}

void MainGaneScene::bill( CCObject* pSender )
{
	BillboardScene* p1 = BillboardScene::create("innerpublicnotify1.png");
	p1->setContentSize(CCSizeMake(200,200));
	p1->setCallbackFunc(this,callfuncN_selector(MainGaneScene::buttonCallback));
	this->addChild(p1,15);
}

void MainGaneScene::quest( CCObject* pSender )
{

	CCDirector::sharedDirector()->replaceScene(QuestScene::scene());
}

void MainGaneScene::race( CCObject* pSender )
{

	BillboardScene* p1 = BillboardScene::create("innerpublicnotify1.png");
	p1->setContentSize(CCSizeMake(200,200));
	p1->setCallbackFunc(this,callfuncN_selector(MainGaneScene::buttonCallback));
	this->addChild(p1,15);
}

//void MainGaneScene::tableCellHighlight(CCTableView *table, CCTableViewCell *cell)  
//{  
//
//	CCLOG("wwww");  
//
//	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("rolerankcell.png");  
//
//	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  
//
//	pSprite->setTexture(aTexture);  
//
//
//} 

//void MainGaneScene::tableCellUnhighlight(CCTableView *table, CCTableViewCell *cell)  
//{  
//	CCLOG("dddd");  
//
//	CCTexture2D *aTexture=CCTextureCache::sharedTextureCache()->addImage("rolerankcellnormal.png");  
//
//	CCSprite *pSprite=(CCSprite *)cell->getChildByTag(200);  
//
//	pSprite->setTexture(aTexture);  
//} 